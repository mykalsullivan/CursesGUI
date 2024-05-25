//
// Created by msullivan on 5/21/24.
//

#include "child_element_lookup_system.h"
#include "CursesGUI/ECS/components.h"
#include "CursesGUI/Elements/ielement.h"

namespace CursesGUI
{
    extern entt::registry g_Registry;

    std::vector<IElement*> getChildren(IElement& element)
    {
        assert(element.valid() && "Cannot retrieve children of invalid element");

        std::vector<IElement*> children;

        auto entitiesWithParents = g_Registry.view<Lookup>();
        for (auto entity : entitiesWithParents)
        {
            auto elementWithParent = g_Registry.get<Lookup>(entity).self;
            auto parentElement = g_Registry.get<Lookup>(entity).parent;

            if (elementWithParent == nullptr || parentElement == nullptr) continue;

            if (parentElement->equalTo(element))
                children.emplace_back(elementWithParent);
        }
        return children;
    }
}