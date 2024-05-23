//
// Created by msullivan on 5/7/24.
//

#include "ui.h"
#include "CursesGUI/Elements/viewport.h"
#include <curses.h>

// Here temporarily
namespace CursesGUI
{
    entt::registry g_Registry;
    Viewport& g_Viewport = Viewport::get();
}

namespace CursesGUI::UI
{
    // Global variables
    namespace
    {
        CommandLineArgs g_Args;
        bool g_Running = false;
    }

    namespace
    {
        bool hasArgument(const std::string& value)
        {

            return true;
        }
    }

    void start(int argc, char* argv[])
    {
        g_Args = { argc, argv };

        // Start Curses mode
        initscr();
        refresh();

        noecho();
        curs_set(0);

        keypad(stdscr, true);
        nodelay(stdscr, true);
        timeout(3);

        if (hasArgument("--no-mouse"))
        {
            mouseinterval(3);
            mousemask(ALL_MOUSE_EVENTS, nullptr);
        }

        if (hasArgument("--no-colors"))
        {
            start_color();
            use_default_colors();
        }

        g_Running = true;
    }

    void stop()
    {
        endwin();
        g_Registry.clear();
        g_Running = false;
    }

    bool isRunning()
    {
        return g_Running;
    }
}