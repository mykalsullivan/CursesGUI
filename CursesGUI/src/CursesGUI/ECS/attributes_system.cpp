//
// Created by msullivan on 5/21/24.
//

#include "attributes_system.h"
#include "CursesGUI/ECS/components.h"
#include "CursesGUI/Elements/ielement.h"

namespace CursesGUI
{
    extern entt::registry g_Registry;

    void setAttribute(IElement& element, PanelAttribute attribute, bool b)
    {
        // Return if element is invalid
        if (!element.valid()) return;

        auto& attributes = g_Registry.get<Attributes>(element.getEntity());
        switch (attribute)
        {
            case PanelAttribute::HIDDEN:
                attributes.hidden = b;
                break;
            case PanelAttribute::PAUSED:
                attributes.paused = b;
                break;
            case PanelAttribute::BORDER:
                attributes.border = b;
                break;
            case PanelAttribute::LOCKED_HEIGHT:
                attributes.lockedHeight = b;
                break;
            case PanelAttribute::LOCKED_WIDTH:
                attributes.lockedWidth = b;
                break;
            case PanelAttribute::UNLOCKABLE_HEIGHT:
                attributes.unlockableHeight = b;
                break;
            case PanelAttribute::UNLOCKABLE_WIDTH:
                attributes.unlockableWidth = b;
                break;
            case PanelAttribute::MOVEABLE:
                attributes.moveable = b;
                break;
            case PanelAttribute::RESIZEABLE:
                attributes.resizeable = b;
                break;
            case PanelAttribute::MODIFIED:
                attributes.modified = b;
                break;
        }
    }

    bool getAttribute(IElement& element, PanelAttribute attribute)
    {
        // Return if element is invalid
        if (!element.valid()) return false;

        auto& attributes = g_Registry.get<Attributes>(element.getEntity());
        bool hidden = attributes.hidden;
        bool paused = attributes.paused;
        bool border = attributes.border;
        bool lockedHeight = attributes.lockedHeight;
        bool lockedWidth = attributes.lockedWidth;
        bool unlockableHeight = attributes.unlockableHeight;
        bool unlockableWidth = attributes.unlockableWidth;
        bool moveable = attributes.moveable;
        bool resizeable = attributes.resizeable;
        bool modified = attributes.modified;

        switch (attribute)
        {
            case PanelAttribute::HIDDEN: return hidden;
            case PanelAttribute::PAUSED: return paused;
            case PanelAttribute::BORDER: return border;
            case PanelAttribute::LOCKED_HEIGHT: return lockedHeight;
            case PanelAttribute::LOCKED_WIDTH: return lockedWidth;
            case PanelAttribute::UNLOCKABLE_HEIGHT: return unlockableHeight;
            case PanelAttribute::UNLOCKABLE_WIDTH: return unlockableWidth;
            case PanelAttribute::MOVEABLE: return moveable;
            case PanelAttribute::RESIZEABLE: return resizeable;
            case PanelAttribute::MODIFIED: return modified;
        }
        return false;
    }
}