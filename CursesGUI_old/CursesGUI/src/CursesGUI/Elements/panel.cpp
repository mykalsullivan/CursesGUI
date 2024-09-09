//
// Created by msullivan on 5/20/24.
//

#include "panel.h"

#include <CursesGUI/Core/ui.h>

#include "viewport.h"
#include "CursesGUI/ECS/components.h"
#include "CursesGUI/ECS/child_element_lookup_system.h"

namespace CursesGUI
{
    extern entt::registry g_Registry;
    extern Viewport& g_Viewport;

    Panel::Panel()
    {
        m_ElementType = ElementType::PANEL;

        // Set up components that all elements share
        m_Entity = g_Registry.create();
        g_Registry.emplace<Lookup>(m_Entity) = { this, &g_Viewport };
        g_Registry.emplace<CursesWindow>(m_Entity);
        g_Registry.emplace<Position>(m_Entity);
        g_Registry.emplace<Dimensions>(m_Entity);
        g_Registry.emplace<Attributes>(m_Entity);
        g_Registry.emplace<Colors>(m_Entity);
        g_Registry.emplace<Stats>(m_Entity);

        // Set up attributes component
        auto& attributes = g_Registry.get<Attributes>(m_Entity);
        attributes.border = true;
    }

    Panel::Panel(Panel* parent)
    {
        m_ElementType = ElementType::PANEL;

        // Set up components that all elements share
        m_Entity = g_Registry.create();
        g_Registry.emplace<Lookup>(m_Entity) = { this, parent };
        g_Registry.emplace<CursesWindow>(m_Entity);
        g_Registry.emplace<Position>(m_Entity);
        g_Registry.emplace<Dimensions>(m_Entity);
        g_Registry.emplace<Attributes>(m_Entity);
        g_Registry.emplace<Colors>(m_Entity);
        g_Registry.emplace<Stats>(m_Entity);

        // Set up attributes component
        auto& attributes = g_Registry.get<Attributes>(m_Entity);
        attributes.border = true;
    }

    Panel::~Panel()
    {
        if (!UI::isRunning()) return;

        // Remove all children from registry
        for (auto child : m_Children)
            g_Registry.destroy(child->getEntity());

        // Delete Curses window
        if (g_Registry.get<CursesWindow>(m_Entity) != nullptr)
            delwin(g_Registry.get<CursesWindow>(m_Entity));

        // Remove panel from registry
        if (m_Entity != entt::null)
            g_Registry.destroy(m_Entity);

        // Remove pointer to this entity in registry
        delete g_Registry.get<Lookup>(m_Entity).self;
    }

    bool Panel::addChild(IElement& element)
    {
        if (!element.valid()) return false;
        if (&element == this) return false;

        element.setParent(*this);

        m_Children.emplace_back(&element);
        return true;
    }

    bool Panel::operator<<(IElement& element)
    {
        if (!element.valid()) return false;
        element.setParent(*this);

        m_Children.emplace_back(&element);
        return true;
    }

    bool Panel::removeChild(IElement& element)
    {
        auto result = std::remove(m_Children.begin(), m_Children.end(), &element);
        if (result != m_Children.end()) return true;
        return false;
    }

    bool Panel::removeChild(int n)
    {
        if (n < 0 || n >= size()) return false;
        m_Children.erase(m_Children.begin() + n);
        return true;
    }

    IElement* Panel::getChild(int n)
    {
        if (n < 0 || n >= size()) return {};
        return m_Children[n];
    }

    IElement* Panel::operator[](int n)
    {
        if (n < 0 || n >= size()) return {};
        return m_Children[n];
    }

    bool Panel::hasChild(IElement& element)
    {
        auto result = std::find(m_Children.begin(), m_Children.end(), &element);
        if (result != m_Children.end()) return true;
        return false;
    }
}