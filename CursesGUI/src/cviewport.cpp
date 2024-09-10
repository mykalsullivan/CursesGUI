//
// Created by msullivan on 9/7/24.
//

#include "CursesGUI/cviewport.h"
#include "CursesGUI/components.h"

#include <iostream>

CViewport::CViewport() : CWidget(nullptr)
{
    // Curses window stuff
    cursesWindowComponent.self = stdscr;
    cursesWindowComponent.parent = stdscr;
    refresh();

    // Position component
    positionComponent.y = &cursesWindowComponent.self->_begy;
    positionComponent.x = &cursesWindowComponent.self->_begx;

    // Dimensions component
    dimensionsComponent.height = &cursesWindowComponent.self->_maxy;
    dimensionsComponent.width = &cursesWindowComponent.self->_maxx;

    // Colors component
    colorsComponent.foreground = COLOR_WHITE;
    colorsComponent.background = COLOR_BLACK;

    // Attributes component
    attributesComponent.hidden = false;
    attributesComponent.bold = false;
    attributesComponent.underlined = false;
}

CViewport::~CViewport()
{
    auto cursesWindow = cursesWindowComponent.self;

    // Delete children
    children().clear();

    // Delete Curses window
    if (cursesWindow != nullptr) {
        wclear(cursesWindow);
        wrefresh(cursesWindow);
        delwin(cursesWindow);
    }
}