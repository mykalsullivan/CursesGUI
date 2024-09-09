//
// Created by msullivan on 9/7/24.
//

#include "cviewport.h"
#include "../ECS/components.h"

#include <iostream>

CViewport::CViewport() : CWidget(nullptr)
{
    init();
}

CViewport::~CViewport()
{
    auto& cursesWindowComponent = g_Registry.get<CursesWindowComponent>(m_ID);
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

void CViewport::init()
{
    g_Registry.emplace_or_replace<CursesWindowComponent>(m_ID);
    g_Registry.emplace_or_replace<Position>(m_ID);
    g_Registry.emplace_or_replace<Dimensions>(m_ID);
    g_Registry.emplace_or_replace<Colors>(m_ID);
    g_Registry.emplace_or_replace<WidgetAttributes>(m_ID);

    // Curses window stuff
    auto& cursesWindowComponent = g_Registry.get<CursesWindowComponent>(m_ID);
    cursesWindowComponent.self = stdscr;
    cursesWindowComponent.parent = stdscr;
    refresh();

    // Position component
    auto& positionComponent = g_Registry.get<Position>(m_ID);
    positionComponent.y = &cursesWindowComponent.self->_begy;
    positionComponent.x = &cursesWindowComponent.self->_begx;

    // Dimensions component
    auto& dimensionsComponent = g_Registry.get<Dimensions>(m_ID);
    dimensionsComponent.height = &cursesWindowComponent.self->_maxy;
    dimensionsComponent.width = &cursesWindowComponent.self->_maxx;

    // Colors component
    auto& colorsComponent = g_Registry.get<Colors>(m_ID);
    colorsComponent.foreground = COLOR_WHITE;
    colorsComponent.background = COLOR_BLACK;

    // Attributes component
    auto& attributesComponent = g_Registry.get<WidgetAttributes>(m_ID);
    attributesComponent.hidden = false;
    attributesComponent.bold = false;
    attributesComponent.underlined = false;
}
