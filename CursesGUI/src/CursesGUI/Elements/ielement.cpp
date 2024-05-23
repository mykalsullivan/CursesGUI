//
// Created by msullivan on 5/21/24.
//

#include "ielement.h"
#include "CursesGUI/ECS/components.h"
#include "CursesGUI/ECS/attributes_system.h"

namespace CursesGUI
{
    extern entt::registry g_Registry;

    IElement* IElement::getParent()
    {
        return g_Registry.get<Lookup>(m_Entity).parent;
    }

    bool IElement::setParent(IElement& target)
    {
        if (!valid() || !target.valid()) return false;
        if (target.getType() != ElementType::PANEL) return false;
        g_Registry.get<Lookup>(m_Entity).parent = &target;
        return true;
    }

    bool IElement::hasParent()
    {
        return g_Registry.get<Lookup>(m_Entity).parent != nullptr && g_Registry.get<Lookup>(m_Entity).parent->valid();
    }

    void IElement::show()
    {
        setAttribute(*this, PanelAttribute::HIDDEN, false);
    }

    void IElement::hide()
    {
        setAttribute(*this, PanelAttribute::HIDDEN, true);
    }
}