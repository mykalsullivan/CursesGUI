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
