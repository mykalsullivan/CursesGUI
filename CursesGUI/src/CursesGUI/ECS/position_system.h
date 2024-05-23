//
// Created by msullivan on 5/20/24.
// TODO: Add documentation

#pragma once

namespace CursesGUI
{
    // Forward declaration
    class IElement;

    bool setY(IElement&, int);
    bool setX(IElement&, int);
    int setPosition(IElement&, int y, int x);

    int getY(IElement&);
    int getX(IElement&);
    int getTopBorder(IElement&);
    int getLeftBorder(IElement&);
    int getBottomBorder(IElement&);
    int getRightBorder(IElement&);

    int getTopLeftEdgeY(IElement&);
    int getTopLeftEdgeX(IElement&);
    int getTopRightEdgeY(IElement&);
    int getTopRightEdgeX(IElement&);
    int getBottomLeftEdgeY(IElement&);
    int getBottomLeftEdgeX(IElement&);
    int getBottomRightEdgeY(IElement&);
    int getBottomRightEdgeX(IElement&);

    bool inYAxis(IElement&, int);
    bool inXAxis(IElement&, int);
    bool inElement(IElement&, int y, int x);
}