//
// Created by msullivan on 5/18/24.
//

#include "movement_system.h"
#include "position_system.h"
#include "CursesGUI/Elements/ielement.h"

namespace CursesGUI
{
    bool moveVertical(IElement& element, int n)
    {
        assert(element.valid() && "Must use valid element");

        if (getTopBorder(element)+n == getTopBorder(*element.getParent()) ||
            getBottomBorder(element)-n == getBottomBorder(*element.getParent()))
            return false;

        setY(element, getY(element)+n);
        return true;
    }

    bool moveHorizontal(IElement& element, int n)
    {
        assert(element.valid() && "Must use valid element");

        if (getLeftBorder(element)+n == getLeftBorder(*element.getParent()) ||
            getRightBorder(element)-n == getRightBorder(*element.getParent()))
            return false;

        setX(element, getX(element)+n);
        return true;
    }
}