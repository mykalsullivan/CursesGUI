//
// Created by msullivan on 5/17/24.
// TODO: Add documentation
// TODO: Cleanup this file for God's sake

#include "render_system.h"
#include "position_system.h"
#include "dimensions_system.h"
#include "attributes_system.h"
#include "info_system.h"
#include "child_element_lookup_system.h"
#include "CursesGUI/ECS/components.h"
#include "CursesGUI/Elements/ielement.h"
#include "CursesGUI/Elements/viewport.h"
#include "CursesGUI/Core/ui.h"
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

            // Reset if element is the viewport
            if (element.getType() == ElementType::VIEWPORT)
            {
                // Get dimensions of terminal and set the dimensions of the viewport accordingly
                setDimensions(g_Viewport, getmaxy(stdscr), getmaxx(stdscr));
                cursesWindow = dupwin(stdscr);
                setCursesWindow(element, cursesWindow);
                return;
            }

            CursesWindow parentCursesWindow = nullptr;
            if (element.hasParent())
                parentCursesWindow = getCursesWindow(*element.getParent());

            int height = getHeight(element);
            int width = getWidth(element);
            int y = getY(element);
            int x = getX(element);
            cursesWindow = derwin(parentCursesWindow, height, width, y, x);
            setCursesWindow(element, cursesWindow);
        }
    }

    namespace UI
    {
        void reset()
        {
            // Don't do anything if the UI hasn't started
            if (!UI::isRunning()) return;

            endwin();
            refresh();
            wclear(getCursesWindow(g_Viewport));

            // Reset viewport, then all elements
            resetElement(g_Viewport);
            for (auto element : getChildren(g_Viewport)) resetElement(*element);
        }

        void update()
        {
            // Don't do anything if the UI hasn't started
            if (!UI::isRunning()) return;

            // Update viewport, then all elements below it
            updateElement(g_Viewport);
            for (auto element : getChildren(g_Viewport))
                if (!getAttribute(*element, PanelAttribute::PAUSED)) updateElement(*element);
        }

        void draw()
        {
            // Don't do anything if the UI hasn't started
            if (!UI::isRunning()) return;

            // Draw viewport, then draw all panels that are not hidden and have been modified
            drawElement(g_Viewport);

            for (auto element : getChildren(g_Viewport))
                if (!getAttribute(*element, PanelAttribute::HIDDEN)) drawElement(*element);

            // Sleep for a frame, then refresh Curses
            std::this_thread::sleep_for(std::chrono::milliseconds(17));
        }
    }

    void resetElement(IElement& element)
    {
        // Return if element doesn't exist
        assert(element.valid() && "Cannot reset an invalid element");

        // If modified, reset Curses window
        if (getAttribute(element, PanelAttribute::MODIFIED))
            resetCursesWindow(element);

        // Get position
        int y = getY(element), x = getX(element);

        // Get parent element (if any)
        auto parentElement = element.getParent();

        // Set position based on parent window (if it exists)
        if (parentElement != nullptr && parentElement->valid())
        {
            // Get position for parent
            int parentY = getY(*parentElement);
            int parentX = getX(*parentElement);
//                setPosition(element, parentY, parentX);
        }

        // Reset all children as well
        std::vector<IElement*> children = getChildren(element);
        for (auto child : children)
            resetElement(*child);

        setAttribute(element, PanelAttribute::MODIFIED, false);
    }

    void updateElement(IElement& element)
    {
        // Return if element doesn't exist
        assert(element.valid() && "Cannot update an invalid element");
//
//            // Return if element is paused
//            if (getAttribute(element, PanelAttribute::PAUSED)) return;

//            // Return if it is not the viewport or panel, or it doesn't have a parent
//            if ((element.getType() != ElementType::PANEL ||
//                 element.getType() != ElementType::VIEWPORT) &&
//                !element.hasParent()) return;

        // Draw border around panel if the element has one
        if (getAttribute(element, PanelAttribute::BORDER)) box(getCursesWindow(element), 0, 0);

        // Update all children as well
        for (auto child : getChildren(element))
            updateElement(*child);

        incrementTickCounter(g_Viewport);
    }

    void drawElement(IElement& element)
    {
        // Return if element doesn't exist
        assert(element.valid() && "Cannot draw an invalid element");

        // Refresh Curses window
        mvwprintw(getCursesWindow(element), getHeight(element)-1, 2, "%ld", getTicks(element));
        wrefresh(getCursesWindow(element));

        // Draw all children as well
        for (auto& child : getChildren(element))
            drawElement(*child);
    }
}