//
// Created by msullivan on 9/6/24.
//

#include "cwidget.h"
#include "components.h"

CWidget::CWidget(CWidget *parent) : m_Parent(parent), m_Layout(nullptr)
{
    // Curses window component
    cursesWindowComponent.self = newwin(20, 40, 0, 0);
    if (m_Parent != nullptr)
        cursesWindowComponent.parent = cursesWindowComponent.self->_parent;
    else
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

CWidget &CWidget::operator=(const CWidget &)
{
    // Copy everything from the original widget and make a new one
    return *this;
}

CWidget &CWidget::operator=(CWidget &&)
{
    // Copy everything from the original widget and make a new one
    return *this;
}

CWidget::~CWidget()
{
    // Delete Curses window
    if (cursesWindow != nullptr)
        delwin(cursesWindow);
}