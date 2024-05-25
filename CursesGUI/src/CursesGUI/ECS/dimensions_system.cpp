//
// Created by msullivan on 5/17/24.
//

#include "dimensions_system.h"
#include "position_system.h"
#include "attributes_system.h"
#include "CursesGUI/ECS/components.h"
#include "CursesGUI/Elements/ielement.h"

namespace CursesGUI
{
    extern entt::registry g_Registry;

    void setHeight(IElement& element, int n)
    {
        // Return if element is invalid
        if (!element.valid()) return;

        // Set height on element
        auto& dimensions = g_Registry.get<Dimensions>(element.getEntity());
        dimensions.height = n;

        setAttribute(element, PanelAttribute::MODIFIED, true);
    }

    void setWidth(IElement& element, int n)
    {
        // Return if element is invalid
        if (!element.valid()) return;

        // Set width on element
        auto& dimensions = g_Registry.get<Dimensions>(element.getEntity());
        dimensions.width = n;

        setAttribute(element, PanelAttribute::MODIFIED, true);
    }

    void setDimensions(IElement& element, int h, int w)
    {
        // Return if element is invalid
        if (!element.valid()) return;

        // Set dimensions on element
        auto& dimensions = g_Registry.get<Dimensions>(element.getEntity());
        dimensions.height = h;
        dimensions.width = w;

        setAttribute(element, PanelAttribute::MODIFIED, true);
    }

    void setMinimumHeight(IElement& element, int n)
    {
        // Return if element is invalid
        if (!element.valid()) return;

        // Set minimum height on element
        auto& dimensions = g_Registry.get<Dimensions>(element.getEntity());
        dimensions.minHeight = n;
    }

    void setMinimumWidth(IElement& element, int n)
    {
        // Return if element is invalid
        if (!element.valid()) return;

        // Set minimum width on element
        auto& dimensions = g_Registry.get<Dimensions>(element.getEntity());
        dimensions.minWidth = n;
    }

    void setMinimumDimensions(IElement& element, int h, int w)
    {
        // Return if element is invalid
        if (!element.valid()) return;

        // Set minimum dimensions on element
        auto& dimensions = g_Registry.get<Dimensions>(element.getEntity());
        dimensions.minHeight = h;
        dimensions.minWidth = w;
    }

    void setMaximumHeight(IElement& element, int n)
    {
        // Return if element is invalid
        if (!element.valid()) return;

        // Set maximum height on element
        auto& dimensions = g_Registry.get<Dimensions>(element.getEntity());
        dimensions.maxHeight = n;
    }

    void setMaximumWidth(IElement& element, int n)
    {
        // Return if element is invalid
        if (!element.valid()) return;

        // Set maximum width on element
        auto& dimensions = g_Registry.get<Dimensions>(element.getEntity());
        dimensions.maxWidth = n;
    }

    void setMaximumDimensions(IElement& element, int h, int w)
    {
        // Return if element is invalid
        if (!element.valid()) return;

        // Set maximum dimensions on element
        auto& dimensions = g_Registry.get<Dimensions>(element.getEntity());
        dimensions.maxHeight = h;
        dimensions.maxWidth = w;
    }

    int getHeight(IElement& element)
    {
        // Return if element is invalid
        if (!element.valid()) return -1;

        // Return height
        auto& dimensions = g_Registry.get<Dimensions>(element.getEntity());
        return dimensions.height;
    }

    int getWidth(IElement& element)
    {
        // Return if element is invalid
        if (!element.valid()) return -1;

        // Return width
        auto& dimensions = g_Registry.get<Dimensions>(element.getEntity());
        return dimensions.width;
    }

    int getRelativeHeight(IElement& element)
    {
        // Return if element is invalid
        if (!element.valid()) return -1;

        // Return relative height
        auto& positionComponent = g_Registry.get<Position>(element.getEntity());
        return getHeight(element) + positionComponent.y;
    }

    int getRelativeWidth(IElement& element)
    {
         // Return if element is invalid
        if (!element.valid()) return -1;

        // Return relative width
        auto& positionComponent = g_Registry.get<Position>(element.getEntity());
        return getWidth(element) + positionComponent.x;
    }

    int getMinimumHeight(IElement& element)
    {
        // Return if element is invalid
        if (!element.valid()) return -1;

        // Return minimum height
        auto& dimensions = g_Registry.get<Dimensions>(element.getEntity());
        return dimensions.minHeight;
    }

    int getMinimumWidth(IElement& element)
    {
        // Return if element is invalid
        if (!element.valid()) return -1;

        // Return minimum width
        auto& dimensions = g_Registry.get<Dimensions>(element.getEntity());
        return dimensions.minWidth;
    }

    int getMaximumHeight(IElement& element)
    {
        // Return if element is invalid
        if (!element.valid()) return -1;

        // Return maximum height
        auto& dimensions = g_Registry.get<Dimensions>(element.getEntity());
        return dimensions.maxHeight;
    }

    int getMaximumWidth(IElement& element)
    {
        // Return if element is invalid
        if (!element.valid()) return -1;

        // Return maximum width
        auto& dimensions = g_Registry.get<Dimensions>(element.getEntity());
        return dimensions.maxWidth;
    }

    bool lockHeight(IElement& element)
    {
        // Return if element is invalid
        if (!element.valid()) return false;

        if (getAttribute(element, PanelAttribute::UNLOCKABLE_HEIGHT))
        {
            setAttribute(element, PanelAttribute::LOCKED_HEIGHT, true);
            return true;
        }
        return false;
    }

    bool lockWidth(IElement& element)
    {
        // Return if element is invalid
        if (!element.valid()) return false;

        if (getAttribute(element, PanelAttribute::UNLOCKABLE_WIDTH))
        {
            setAttribute(element, PanelAttribute::LOCKED_WIDTH, true);
            return true;
        }
        return false;
    }

    int lock(IElement& element)
    {
         // Return if element is invalid
        if (!element.valid()) return -1;

        int lockedHeightResult = 0, lockedWidthResult = 0;

        if (lockHeight(element)) lockedHeightResult = 1;
        if (lockWidth(element)) lockedWidthResult = 2;

        return lockedHeightResult + lockedWidthResult;
    }

    bool unlockHeight(IElement& element)
    {
        // Return if element is invalid
        if (!element.valid()) return false;

        if (getAttribute(element, PanelAttribute::UNLOCKABLE_HEIGHT))
            setAttribute(element, PanelAttribute::LOCKED_HEIGHT, false);
        return true;
    }

    bool unlockWidth(IElement& element)
    {
        // Return if element is invalid
        if (!element.valid()) return false;

        if (getAttribute(element, PanelAttribute::UNLOCKABLE_WIDTH))
            setAttribute(element, PanelAttribute::LOCKED_WIDTH, false);

        return true;
    }

    int unlock(IElement& element)
    {
        // Return if element is invalid
        if (!element.valid()) return -1;

        int unlockedHeightResult = 0, unlockedWidthResult = 0;
        if (unlockHeight(element)) unlockedHeightResult = 1;
        if (unlockWidth(element)) unlockedHeightResult = 2;

        return unlockedHeightResult + unlockedWidthResult;
    }

    bool extendTop(IElement& element, int n)
    {
        // Return if element is invalid
        if (!element.valid()) return false;

        // Return if element cannot be resized
        if (!getAttribute(element, PanelAttribute::RESIZEABLE)) return false;

        int y = getY(element);
        int newY = y-n;

        int height = getHeight(element);
        int newHeight = height+n;

        setY(element, newY);
        setHeight(element, newHeight);
        return true;
    }

    bool extendRight(IElement& element, int n)
    {
        // Return if element is invalid
        if (!element.valid()) return false;

        // Return if element cannot be resized
        if (!getAttribute(element, PanelAttribute::RESIZEABLE)) return false;

        int width = getWidth(element);
        int newWidth = width+n;

        setWidth(element, newWidth);
        return true;
    }

    bool extendBottom(IElement& element, int n)
    {
        // Return if element is invalid
        if (!element.valid()) return false;

        // Return if element cannot be resized
        if (!getAttribute(element, PanelAttribute::RESIZEABLE)) return false;

        int height = getHeight(element);
        int newHeight = height+n;

        setWidth(element, newHeight);
        return true;
    }

    bool extendLeft(IElement& element, int n)
    {
        // Return if element is invalid
        if (!element.valid()) return false;

        // Return if element cannot be resized
        if (!getAttribute(element, PanelAttribute::RESIZEABLE)) return false;

        // Return false if the element will extend past the parent left border
        if (getX(element)-n <= getLeftBorder(*element.getParent())) return false;

        // Return false if the new width surpasses the max width
        //if (getWidth(element)+n >= getMaximumWidth(element)) return false;

        setX(element, getX(element)-n);
        setWidth(element, getWidth(element)+n);
        return true;
    }

    bool extendVertical(IElement& element, int n)
    {
        // Return if element is invalid
        if (!element.valid()) return false;

        // Return if element cannot be resized
        if (!getAttribute(element, PanelAttribute::RESIZEABLE)) return false;

        extendTop(element, n);
        extendBottom(element, (n*2));
        return true;
    }

    bool extendHorizontal(IElement& element, int n)
    {
        // Return if element is invalid
        if (!element.valid()) return false;

        // Return if element cannot be resized
        if (!getAttribute(element, PanelAttribute::RESIZEABLE)) return false;

        extendLeft(element, n);
        extendRight(element, (n*2));
        return true;
    }

    int extendTopLeft(IElement& element, int h, int w)
    {
        // Return if element is invalid
        if (!element.valid()) return -1;

        int extendedTop = 0, extendedLeft = 0;

        if (extendTop(element, h)) extendedTop = 1;
        if (extendLeft(element, w)) extendedLeft = 2;
        return extendedTop + extendedLeft;
    }

    int extendTopRight(IElement& element, int h, int w)
    {
        // Return if element is invalid
        if (!element.valid()) return -1;

        int extendedTop = 0, extendedRight = 0;

        if (extendTop(element, h)) extendedTop = 1;
        if (extendRight(element, w)) extendedRight = 2;
        return extendedTop + extendedRight;
    }

    int extendBottomLeft(IElement& element, int h, int w)
    {
        // Return if element is invalid
        if (!element.valid()) return -1;

        int extendedBottom = 0, extendedLeft = 0;

        if (extendBottom(element, h)) extendedBottom = 1;
        if (extendLeft(element, w)) extendedLeft = 2;
        return extendedBottom + extendedLeft;
    }

    int extendBottomRight(IElement& element, int h, int w)
    {
        // Return if element is invalid
        if (!element.valid()) return -1;

        int extendedBottom = 0, extendedRight = 0;

        if (extendBottom(element, h)) extendedBottom = 1;
        if (extendLeft(element, w)) extendedRight = 2;
        return extendedBottom + extendedRight;
    }
}