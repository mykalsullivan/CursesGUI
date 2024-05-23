//
// Created by msullivan on 5/20/24.
//

#pragma once
#include "ielement.h"

namespace CursesGUI
{
    class Element : public IElement
    {
    public:
        Element();
        explicit Element(IElement* parent);
        ~Element() override;
    public:
        // Prevent copying
        Element(const Element&) = delete;
        Element(Element&&) = delete;
        Element& operator=(const Element&) = delete;
        Element& operator=(Element&&) = delete;
    };
}