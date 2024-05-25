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
#include <thread>

namespace CursesGUI
{
    extern entt::registry g_Registry;
    extern Viewport& g_Viewport;

    namespace
    {
        CursesWindow getCursesWindow(IElement& element)
        {
            // Return if element is invalid
            if (!element.valid()) return nullptr;
            return g_Registry.get<CursesWindow>(element.getEntity());
        }

        void setCursesWindow(IElement& element, CursesWindow cursesWindow)
        {
            // Return if element is invalid
            if (!element.valid()) return;
            g_Registry.get<CursesWindow>(element.getEntity()) = cursesWindow;
        }

        void resetCursesWindow(IElement& element)
        {
            // Return if element is invalid
            if (!element.valid()) return;



            CursesWindow cursesWindow = getCursesWindow(element);
            if (cursesWindow != nullptr) delwin(cursesWindow);



            CursesWindow parentCursesWindow = nullptr;



            // Reset if element is the viewport
            if (element.isType(ElementType::VIEWPORT)) parentCursesWindow = stdscr;



            if (element.hasParent())
                parentCursesWindow = getCursesWindow(*element.getParent());



            // Get dimensions of terminal and set the dimensions of the viewport accordingly
            if (element.isType(VIEWPORT))
                setDimensions(element, getmaxy(stdscr), getmaxx(stdscr));
            if (element.hasParent() && !element.isType(VIEWPORT))
                setDimensions(element, getmaxy(parentCursesWindow), getmaxx(parentCursesWindow));



            int height = getHeight(element);
            int width = getWidth(element);
            int y = getY(element);
            int x = getX(element);



            // Set Curses window based on parent
            if (element.isType(VIEWPORT))
                cursesWindow = dupwin(parentCursesWindow);
            if (element.hasParent() && !element.getParent()->isType(VIEWPORT))
                cursesWindow = derwin(parentCursesWindow, height, width, y, x);

            setCursesWindow(element, cursesWindow);
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
                if (element.isType(ElementType::VIEWPORT))
                {
                    endwin();
                    refresh();
                }
                resetCursesWindow(element);
            }

            setAttribute(element, PanelAttribute::MODIFIED, false);
        }

        void updateElement(IElement& element)
        {
            assert(element.valid() && "Cannot update an invalid element");

            // Draw border around panel if the element has one
            if (getAttribute(element, PanelAttribute::BORDER)) box(getCursesWindow(element), 0, 0);

            box(getCursesWindow(element), 0, 0);
            timeout(-1);
            getch();
            timeout(3);

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
            if (!UI::isRunning()) return;

            // Get all elements
            auto elements = g_Registry.view<Lookup>();


            // Find and draw viewport
            for (auto elementID : elements)
            {
                auto& element = g_Registry.get<Lookup>(elementID).self;
                if (element->isType(VIEWPORT))
                {
                    resetElement(*element);
                    updateElement(*element);
                    drawElement(*element);
                    break;
                }
            }

            // Draw children
            for (auto& elementID : elements)
            {
                auto& element = g_Registry.get<Lookup>(elementID).self;
                assert(element->valid() && "Cannot refresh an invalid element");

                if (element->isType(VIEWPORT)) continue;

                resetElement(*element);
                updateElement(*element);
                drawElement(*element);
            }

            std::this_thread::sleep_for(std::chrono::milliseconds(17));
        }
    }
}