//
// Created by msullivan on 5/20/24.
//

#include "element.h"

#include <CursesGUI/Core/ui.h>
#include "CursesGUI/ECS/components.h"

namespace CursesGUI
{
    extern entt::registry g_Registry;

    Element::Element()
    {
        m_ElementType = ElementType::NULL_ELEMENT;

        // Set up components that all elements share
        g_Registry.emplace_or_replace<Lookup>(m_Entity);
        g_Registry.emplace_or_replace<Position>(m_Entity);
        g_Registry.emplace_or_replace<Dimensions>(m_Entity);
        g_Registry.emplace_or_replace<Attributes>(m_Entity);
        g_Registry.emplace_or_replace<Colors>(m_Entity);
        g_Registry.emplace_or_replace<Stats>(m_Entity);

        // Set up attributes component
        auto& attributes = g_Registry.get<Attributes>(m_Entity);
        attributes.hidden = false;
        attributes.border = true;
    }

    Element::Element(IElement* parent)
    {
        m_ElementType = ElementType::NULL_ELEMENT;

        // Set up components that all elements share
        g_Registry.emplace<Lookup>(m_Entity);
        g_Registry.emplace<CursesWindow>(m_Entity);
        g_Registry.emplace<Position>(m_Entity);
        g_Registry.emplace<Dimensions>(m_Entity);
        g_Registry.emplace<Attributes>(m_Entity);
        g_Registry.emplace<Colors>(m_Entity);
        g_Registry.emplace<Stats>(m_Entity);

        // Set up attributes component
        auto& attributes = g_Registry.get<Attributes>(m_Entity);
        attributes.hidden = false;
        attributes.border = true;
    }

    Element::~Element()
    {
        if (!UI::isRunning()) return;

        // Delete Curses window
        if (g_Registry.get<CursesWindow>(m_Entity) != nullptr)
            delwin(g_Registry.get<CursesWindow>(m_Entity));

        // Remove panel from registry
        if (m_Entity != entt::null)
            g_Registry.destroy(m_Entity);

        // Remove pointer to this entity in registry
        delete g_Registry.get<Lookup>(m_Entity).self;
    }
}