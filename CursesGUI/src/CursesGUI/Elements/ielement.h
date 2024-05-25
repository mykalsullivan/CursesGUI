//
// Created by msullivan on 5/17/24.
//

#pragma once
#include "CursesGUI/Core/ui.h"
#include <entt.hpp>

namespace CursesGUI
{
    enum ElementType
    {
        NULL_ELEMENT,
        VIEWPORT,
        PANEL,
        TEXT,
        DECORATION,
        BUTTON,
        LIST,
        INPUT,
    };

    class IElement
    {
    protected:
        entt::entity m_Entity  = entt::null;
        ElementType m_ElementType = ElementType::NULL_ELEMENT;
    public:
        IElement() = default;
        virtual ~IElement() = default;
    public:
        IElement(const IElement&) = delete;
        IElement(IElement&&) = delete;
        IElement& operator=(const IElement&) = delete;
        IElement& operator=(IElement&&) = delete;
    public:
        virtual entt::entity getEntity() { return m_Entity; }
        virtual bool valid() { return m_Entity != entt::null; }
        virtual bool equalTo(IElement&);

        virtual IElement* getParent();
        virtual bool setParent(IElement&);
        virtual bool hasParent();

        virtual ElementType getType() { return m_ElementType; }
        virtual bool isType(ElementType elementType) { return m_ElementType == elementType; }

        virtual void show();
        virtual void hide();
    };
}
