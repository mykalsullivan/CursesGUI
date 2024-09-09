//
// Created by msullivan on 5/18/24.
//

#include "info_system.h"
#include "CursesGUI/ECS/components.h"
#include "CursesGUI/Elements/ielement.h"

namespace CursesGUI
{
    extern entt::registry g_Registry;

    void incrementTickCounter(IElement& element)
    {
        // Return if element is invalid
        if (!element.valid()) return;
        g_Registry.get<Stats>(element.getEntity()).ticks++;
    }

    long getTicks(IElement& element)
    {
        // Return if element is invalid
        if (!element.valid()) return -1;
        return g_Registry.get<Stats>(element.getEntity()).ticks;
    }
}