//
// Created by msullivan on 5/21/24.
//

#include "viewport.h"
#include "CursesGUI/ECS/components.h"
#include "CursesGUI/Elements/ielement.h"

namespace CursesGUI
{
    extern entt::registry g_Registry;
    
    Viewport::Viewport()
    {
        m_ElementType = ElementType::VIEWPORT;

        // Set up components that all elements share
        m_Entity = g_Registry.create();
        g_Registry.emplace<Lookup>(m_Entity) = { this, nullptr };
        g_Registry.emplace<CursesWindow>(m_Entity);
        g_Registry.emplace<Position>(m_Entity);
        g_Registry.emplace<Dimensions>(m_Entity);
        g_Registry.emplace<Attributes>(m_Entity);
        g_Registry.emplace<Colors>(m_Entity);
        g_Registry.emplace<Stats>(m_Entity);

        auto& attributes = g_Registry.get<Attributes>(m_Entity);
        attributes.border = true;
        attributes.lockedHeight = true;
        attributes.lockedWidth = true;
        attributes.unlockableHeight = false;
        attributes.unlockableWidth = false;
        attributes.hidden = false;
        attributes.paused = false;
        attributes.moveable = false;
        attributes.modified = true;
    }

    Viewport& Viewport::get()
    {
        static Viewport instance;
        return instance;
    }
}