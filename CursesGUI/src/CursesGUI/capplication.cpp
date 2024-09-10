//
// Created by msullivan on 9/7/24.
//

#include "capplication.h"
#include "cviewport.h"

#include "renderer.h"
#include <ncurses.h>

struct CursesWindowComponent;

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
    /* Curses stuff */
    initscr();
    start_color();
    noecho();
    timeout(16);
    curs_set(0);
    refresh();

    CViewport viewport;

    while (m_Running)
    {
        // 1. Buffer input
        m_InputBuffer.key = getch();
        // ...buffer mouse input (will require some work)

        // 2. Advance frame (which will process input + update the terminal)
        UI::advanceFrame();

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

}

unsigned long CApplication::objectCount()
{

}
