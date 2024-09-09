//
// Created by msullivan on 5/20/24.
// TODO: Add documentation
#pragma once

namespace CursesGUI
{
    // Forward declaration
    class IElement;

    void setHeight(IElement&, int);
    void setWidth(IElement&, int);
    void setDimensions(IElement&, int h, int w);
    void setMinimumHeight(IElement&, int);
    void setMinimumWidth(IElement&, int);
    void setMinimumDimensions(IElement&, int h, int w);
    void setMaximumHeight(IElement&, int);
    void setMaximumWidth(IElement&, int);
    void setMaximumDimensions(IElement&, int h, int w);

    int getHeight(IElement&);
    int getWidth(IElement&);
    int getRelativeHeight(IElement&);
    int getRelativeWidth(IElement&);
    int getMinimumHeight(IElement&);
    int getMinimumWidth(IElement&);
    int getMaximumHeight(IElement&);
    int getMaximumWidth(IElement&);

    bool lockHeight(IElement&);
    bool lockWidth(IElement&);
    int lock(IElement&);
    bool unlockHeight(IElement&);
    bool unlockWidth(IElement&);
    int unlock(IElement&);

    bool extendTop(IElement&, int);
    bool extendRight(IElement&, int);
    bool extendBottom(IElement&, int);
    bool extendLeft(IElement&, int);
    bool extendVertical(IElement&, int);
    bool extendHorizontal(IElement&, int);
    int extendTopLeft(IElement&, int h, int w);
    int extendTopRight(IElement&, int h, int w);
    int extendBottomLeft(IElement&, int h, int w);
    int extendBottomRight(IElement&, int h, int w);
}