//
// Created by msullivan on 5/21/24.
//

#pragma once
#include "ielement.h"

namespace CursesGUI
{
    class Viewport : public IElement
    {
    private:
        Viewport();
        ~Viewport() override = default;
    public:
        // Prevents copying
        Viewport(const Viewport&) = delete;
        Viewport(Viewport&&) = delete;
        Viewport& operator=(const Viewport&) = delete;
        Viewport& operator=(Viewport&&) = delete;

        // There can only be one viewport instance
        static Viewport& get();
    };
}