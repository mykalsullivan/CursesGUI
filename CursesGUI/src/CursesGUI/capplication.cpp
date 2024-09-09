//
// Created by msullivan on 9/7/24.
//

#include "capplication.h"
#include "cviewport.h"
#include "../ECS/components.h"
#include <ncurses.h>

struct CursesWindowComponent;

namespace
{
    void init()
    {
        initscr();
        start_color();
        noecho();
        curs_set(0);
        refresh();
    }
}

CApplication::CApplication(int argc, char *argv[])
{
    m_Args = { argc, argv };
    m_Running = true;
}

CApplication::~CApplication()
{
    endwin();
}

CApplication &CApplication::instance()
{
    static CApplication instance;
    return instance;
}

int CApplication::run()
{
    init();
    CViewport viewport;

    mvprintw(2, 0, "Viewport only...");
    mvprintw(3, 0, "Widgets: %ld", widgetCount());
    mvprintw(4, 0, "Objects: %ld", objectCount());
    getch();

    auto widget = new CWidget;
    mvprintw(6, 0, "Added widget...");
    mvprintw(7, 0, "Widgets: %ld", widgetCount());
    mvprintw(8, 0, "Objects: %ld", objectCount());
    getch();

    delete widget;
    mvprintw(22, 0, "Deleted widget...");
    mvprintw(23, 0, "Widgets: %ld", widgetCount());
    mvprintw(24, 0, "Objects: %ld", objectCount());
    getch();

    while (m_Running)
    {
        // 1. Get input


        // 2. Refresh all CObjects


        // 3. Draw all CObjects

        exit();
    }

    return 0;
}

void CApplication::exit()
{
    m_Running = false;
}

unsigned long CApplication::widgetCount()
{
    return g_Registry.view<CursesWindowComponent>().size();
}

unsigned long CApplication::objectCount()
{
    return g_Registry.view<Data>().size();
}
