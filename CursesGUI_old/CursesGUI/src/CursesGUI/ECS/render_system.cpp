//
// Created by msullivan on 5/17/24.
// TODO: Add documentation
// TODO: Cleanup this file for God's sake

#include "render_system.h"
#include "position_system.h"
#include "dimensions_system.h"
#include "attributes_system.h"
#include "info_system.h"
#include "CursesGUI/ECS/components.h"
#include "CursesGUI/Elements/ielement.h"
#include "CursesGUI/Elements/viewport.h"
#include "child_element_lookup_system.h"
#include <CursesGUI/Core/input.h>
#include <CursesGUI/Core/ui.h>
#include <thread>

namespace CursesGUI
{
    extern entt::registry g_Registry;
    extern Viewport& g_Viewport;
    extern Input g_InputBuffer;
    extern Binds g_Binds;

    namespace
    {
        CursesWindow getCursesWindow(IElement& element)
        {
            assert(element.valid() && "Cannot retrieve Curses window of invalid element");

            auto lookupComponent = g_Registry.get<Lookup>(element.getEntity());
            auto cursesWindow = lookupComponent.self;

            if (cursesWindow != nullptr)
                return cursesWindow;
            return nullptr;
        }

        void setCursesWindow(IElement& element, CursesWindow cursesWindow)
        {
            assert(element.valid() && "Cannot set Curses window for invalid element");
            assert(cursesWindow != nullptr && "Cannot bind null Curses window to element");

            g_Registry.get<Lookup>(element.getEntity()).self = cursesWindow;
        }

        void resetCursesWindow(IElement& element)
        {
            assert(element.valid() && "Cannot reset Curses window on invalid element");

            CursesWindow cursesWindow = getCursesWindow(element);
            delwin(cursesWindow);

            // Get dimensions of terminal and set the dimensions of the viewport accordingly
            if (element.isType(VIEWPORT))
            {
                setDimensions(element, getmaxy(stdscr), getmaxx(stdscr));
                setCursesWindow(element, stdscr);
            }
            else if (element.hasParent() && !element.isType(VIEWPORT))
            {
                resetCursesWindow(element);

                int height = getHeight(element);
                int width = getWidth(element);
                int y = getY(element);
                int x = getX(element);

                setCursesWindow(element, derwin(getCursesWindow(*element.getParent()), height, width, y, x));
            }
        }
    }

    namespace
    {
        void resetElement(IElement& element)
        {
            assert(element.valid() && "Cannot reset an invalid element");

            // If modified, reset Curses window
            if (getAttribute(element, PanelAttribute::MODIFIED))
            {
                // If element is a viewport, reset Curses so that screen dimensions can be refreshed
                if (element.isType(VIEWPORT))
                {
                    endwin();
                    refresh();
                }
                resetCursesWindow(element);
                setDimensions(element, getHeight(element), getWidth(element));
            }
            setAttribute(element, PanelAttribute::MODIFIED, false);
        }

        void updateElement(IElement& element)
        {
            assert(element.valid() && "Cannot update an invalid element");

            // Draw border around panel if the element has one
            if (getAttribute(element, PanelAttribute::BORDER)) box(getCursesWindow(element), 0, 0);

            /* START DEBUG */
            mvprintw(14, 1, "Element(s): %d", (int) g_Registry.view<Lookup>().size());
            mvprintw(15, 1, "Element #%d", (int) element.getEntity());
            mvprintw(16, 1, "y: %d, x: %d, height: %d, width: %d",
                     getY(element),
                     getX(element),
                     getHeight(element),
                     getWidth(element));

            mvprintw(17, 1, "y: %d, x: %d, height: %d, width: %d",
                     getCursesWindow(element)->_cury,
                     getCursesWindow(element)->_curx,
                     getmaxy(getCursesWindow(element)),
                     getmaxx(getCursesWindow(element)));
            wrefresh(getCursesWindow(element));
            /* END DEBUG */

            // Increment frame counter for element
            incrementTickCounter(element);
        }

        void drawElement(IElement& element)
        {
            assert(element.valid() && "Cannot draw an invalid element");
            wrefresh(getCursesWindow(element));
        }
    }

    namespace UI
    {
        void refresh()
        {
            // Don't do anything if the UI hasn't started
            if (!isRunning()) return;

            // TODO Execute buffered input from the previous frame, then clear the buffer to be re-filled


            // Buffer user input for current frame
            g_InputBuffer = getInput();

            // Get all elements
            auto elements = g_Registry.view<Lookup>();


            // Find and draw viewport
            for (auto elementID : elements)
            {
                auto element = g_Registry.get<Lookup>(elementID).self;
                if (element->isType(VIEWPORT))
                {
                    resetElement(*element);
                    updateElement(*element);
                    drawElement(*element);
                    break;
                }
            }

            // Draw children
            for (auto elementID : elements)
            {
                auto element = g_Registry.get<Lookup>(elementID).self;
                assert(element->valid() && "Cannot refresh an invalid element");

                if (element->isType(VIEWPORT)) continue;

                // Refresh element
                resetElement(*element);
                updateElement(*element);
                drawElement(*element);

                // If it is a panel, refresh children
                if (element->isType(PANEL))
                {
                    auto children = getChildren(*element);
                    for (auto child : children)
                    {
                        resetElement(*child);
                        updateElement(*child);
                        drawElement(*child);
                    }
                }
            }
            std::this_thread::sleep_for(std::chrono::microseconds (16666));
        }
    }
}
