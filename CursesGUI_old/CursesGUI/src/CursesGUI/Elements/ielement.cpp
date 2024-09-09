//
// Created by msullivan on 5/21/24.
//

#include "ielement.h"
#include "CursesGUI/ECS/components.h"
#include "CursesGUI/ECS/attributes_system.h"

namespace CursesGUI
{
    extern entt::registry g_Registry;

    bool IElement::equalTo(IElement& target)
    {
        assert(target.valid() && "Cannot compare to invalid target");
        if (m_Entity == target.getEntity()) return true;
        return false;
    }

    IElement* IElement::getParent()
    {
        if (g_Registry.get<Lookup>(m_Entity).parent == nullptr) return nullptr;
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