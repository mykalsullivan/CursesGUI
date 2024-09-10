//
// Created by msullivan on 9/6/24.
//

#include "cwidget.h"
#include "../ECS/components.h"
#include "../../include/entt.hpp"

CWidget::CWidget(CWidget *parent) : m_Parent(parent), m_Layout(nullptr)
{
    init();
}

CWidget &CWidget::operator=(const CWidget &)
{
    // Copy everything from the original widget and make a new one
}

CWidget &CWidget::operator=(CWidget &&)
{
    // Copy everything from the original widget and make a new one
}

CWidget::~CWidget()
{
    auto cursesWindowComponent = g_Registry.get<CursesWindowComponent>(m_ID);
    auto cursesWindow = cursesWindowComponent.self;

    // Delete Curses window
    if (cursesWindow != nullptr)
        delwin(cursesWindow);
}

void CWidget::init()
{
    g_Registry.emplace_or_replace<CursesWindowComponent>(m_ID);
    g_Registry.emplace_or_replace<Position>(m_ID);
    g_Registry.emplace_or_replace<Dimensions>(m_ID);
    g_Registry.emplace_or_replace<Colors>(m_ID);
    g_Registry.emplace_or_replace<WidgetAttributes>(m_ID);

    // Curses window component
    auto& cursesWindowComponent = g_Registry.get<CursesWindowComponent>(m_ID);
    cursesWindowComponent.self = newwin(20, 40, 0, 0);
    if (m_Parent != nullptr)
        cursesWindowComponent.parent = cursesWindowComponent.self->_parent;
    else
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

void CWidget::show()
{

}

void CWidget::hide()
{

}

void CWidget::pause()
{

}

void CWidget::unpause()
{

}

bool CWidget::lockHeight()
{

    return false;
}

bool CWidget::lockWidth()
{

    return false;
}

int CWidget::lockResize()
{

    return 0;
}

bool CWidget::unlockHeight()
{

    return false;
}

bool CWidget::unlockWidth()
{

    return false;
}

int CWidget::unlockResize()
{

    return 0;
}

bool CWidget::isHidden()
{

    return false;
}

bool CWidget::isPaused()
{

    return false;
}

bool CWidget::hasLockedHeight()
{

    return false;
}

bool CWidget::hasLockedWidth()
{

    return false;
}

bool CWidget::hasUnlockableHeight()
{

    return false;
}

bool CWidget::hasUnlockableWidth()
{

    return false;
}

bool CWidget::isMoveable()
{

    return false;
}

bool CWidget::isResizeable()
{

    return false;
}

void CWidget::setForegroundColor(CColor color)
{

}

void CWidget::setBackgroundColor(CColor color)
{

}

void CWidget::setColor(CColor foregroundColor, CColor backgroundColor)
{

}

void CWidget::setColorAttribute(CColorAttribute attribute, bool b)
{

}

void CWidget::resetColorAttributes()
{

}

CColor CWidget::getForegroundColor()
{

    return 0;
}

CColor CWidget::getBackgroundColor()
{

    return 0;
}

bool CWidget::hasColorAttribute(CColorAttribute attribute)
{

    return false;
}

bool CWidget::setHeight(int n)
{

    return false;
}

bool CWidget::setWidth(int n)
{

    return false;
}

int CWidget::setDimensions(int h, int w)
{

    return 0;
}

bool CWidget::setMinimumHeight(int n)
{

    return false;
}

bool CWidget::setMinimumWidth(int n)
{

    return false;
}

int CWidget::setMinimumDimensions(int h, int w)
{

    return 0;
}

bool CWidget::setMaximumHeight(int n)
{

    return false;
}

bool CWidget::setMaximumWidth(int n)
{

    return false;
}

int CWidget::setMaximumDimensions(int h, int w)
{

    return false;
}

int CWidget::getHeight()
{

    return -1;
}

int CWidget::getWidth()
{

    return -1;
}

int CWidget::getMinimumHeight()
{

    return -1;
}

int CWidget::getMinimumWidth()
{

    return -1;
}

int CWidget::getMaximumHeight()
{

    return -1;
}

int CWidget::getMaximumWidth()
{

    return -1;
}

bool CWidget::extendTop(int n)
{

    return false;
}

bool CWidget::extendRight(int n)
{

    return false;
}

bool CWidget::extendBottom(int n)
{

    return false;
}

bool CWidget::extendLeft(int n)
{

    return false;
}

int CWidget::extendVertical(int n)
{

    return 0;
}

int CWidget::extendHorizontal(int n)
{

    return 0;
}

int CWidget::extendTopLeft(int h, int w)
{

    return 0;
}

int CWidget::extendTopRight(int h, int w)
{

    return 0;
}

int CWidget::extendBottomLeft(int h, int w)
{

    return 0;
}

int CWidget::extendBottomRight(int h, int w)
{

    return 0;
}

long CWidget::getFrameCount()
{

    return 0l;
}

bool CWidget::moveUp(int n)
{

    return false;
}

bool CWidget::moveRight(int n)
{

    return false;
}

bool CWidget::moveDown(int n)
{

    return false;
}

bool CWidget::moveLeft(int n)
{

    return false;
}

int CWidget::moveVertical(int n)
{

    return 0;
}

int CWidget::moveHorizontal(int n)
{

    return 0;
}

int CWidget::move(int y, int x)
{

    return 0;
}

bool CWidget::setY(int n)
{

    return false;
}

bool CWidget::setX(int n)
{

    return false;
}

int CWidget::setPosition(int y, int x)
{

    return 0;
}

int CWidget::getY()
{

    return 0;
}

int CWidget::getX()
{

    return 0;
}

int CWidget::getTopBorder()
{

    return 0;
}

int CWidget::getLeftBorder()
{

    return 0;
}

int CWidget::getBottomBorder()
{

    return 0;
}

int CWidget::getRightBorder()
{

    return 0;
}

int CWidget::getTopLeftEdgeY()
{

    return 0;
}

int CWidget::getTopLeftEdgeX()
{

    return 0;
}

int CWidget::getTopRightEdgeY()
{

    return 0;
}

int CWidget::getTopRightEdgeX()
{

    return 0;
}

int CWidget::getBottomLeftEdgeY()
{

    return 0;
}

int CWidget::getBottomLeftEdgeX()
{

    return 0;
}

int CWidget::getBottomRightEdgeY()
{

    return 0;
}

int CWidget::getBottomRightEdgeX()
{

    return 0;
}

bool CWidget::inYAxis(int n)
{

    return false;
}

bool CWidget::inXAxis(int n)
{

    return false;
}

bool CWidget::inElement(int y, int x)
{

    return false;
}