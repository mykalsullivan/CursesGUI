//
// Created by msullivan on 5/18/24.
//

#include "position_system.h"
#include "attributes_system.h"
#include "CursesGUI/ECS/components.h"
#include "CursesGUI/Elements/ielement.h"

namespace CursesGUI
{
    extern entt::registry g_Registry;

    bool setY(IElement& element, int n)
    {
        assert(element.valid() && "Must use valid element");

        auto& positionComponent = g_Registry.get<Position>(element.getEntity());
        positionComponent.y = n;

        setAttribute(element, PanelAttribute::MODIFIED, true);
        return true;
    }

    bool setX(IElement& element, int n)
    {
        assert(element.valid() && "Must use valid element");

        auto& positionComponent = g_Registry.get<Position>(element.getEntity());
        positionComponent.x = n;

        setAttribute(element, PanelAttribute::MODIFIED, true);
        return true;
    }

    int setPosition(IElement& element, int y, int x)
    {
        assert(element.valid() && "Must use valid element");

        auto& positionComponent = g_Registry.get<Position>(element.getEntity());
        positionComponent.y = y;
        positionComponent.x = x;

        setAttribute(element, PanelAttribute::MODIFIED, true);
        return true;
    }

    int getY(IElement& element)
    {
        assert(element.valid() && "Must use valid element");

        auto& positionComponent = g_Registry.get<Position>(element.getEntity());
        return positionComponent.y;
    }

    int getX(IElement& element)
    {
        assert(element.valid() && "Must use valid element");

        auto& positionComponent = g_Registry.get<Position>(element.getEntity());
        return positionComponent.x;
    }

    int getTopBorder(IElement& element) { return getY(element); }
    int getLeftBorder(IElement& element) { return getX(element); }

    int getBottomBorder(IElement& element)
    {
        assert(element.valid() && "Must use valid element");

        auto& positionComponent = g_Registry.get<Position>(element.getEntity());
        int y = positionComponent.y;

        auto& dimensionsComponent = g_Registry.get<Dimensions>(element.getEntity());
        int height = dimensionsComponent.height;

        return y+height;
    }

    int getRightBorder(IElement& element)
    {
        assert(element.valid() && "Must use valid element");

        auto& positionComponent = g_Registry.get<Position>(element.getEntity());
        int x = positionComponent.x;

        auto& dimensionsComponent = g_Registry.get<Dimensions>(element.getEntity());
        int width = dimensionsComponent.width;

        return x+width;
    }

    int getTopLeftEdgeY(IElement& element) { return getTopBorder(element); }
    int getTopLeftEdgeX(IElement& element) { return getLeftBorder(element); }
    int getTopRightEdgeY(IElement& element) { return getTopBorder(element); }
    int getTopRightEdgeX(IElement& element) { return getRightBorder(element); }
    int getBottomLeftEdgeY(IElement& element) { return getBottomBorder(element); }
    int getBottomLeftEdgeX(IElement& element) { return getLeftBorder(element); }
    int getBottomRightEdgeY(IElement& element) { return getBottomBorder(element); }
    int getBottomRightEdgeX(IElement& element) { return getRightBorder(element); }

    bool inYAxis(IElement& element, int n)
    {
        assert(element.valid() && "Must use valid element");

        int leftBorder = getLeftBorder(element);
        int rightBorder = getRightBorder(element);

        if (n >= leftBorder && n <= rightBorder) return true;
        return false;
    }

    bool inXAxis(IElement& element, int n)
    {
        assert(element.valid() && "Must use valid element");

        int topBorder = getTopBorder(element);
        int bottomBorder = getBottomBorder(element);

        if (n >= topBorder && n <= bottomBorder) return true;
        return false;
    }

    bool inElement(IElement& element, int y, int x)
    {
        assert(element.valid() && "Must use valid element");

        bool inY = inYAxis(element, y);
        bool inX = inXAxis(element, x);

        if (inY && inX) return true;
        return false;
    }
}