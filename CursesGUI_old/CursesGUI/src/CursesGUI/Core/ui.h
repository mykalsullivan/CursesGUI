//
// Created by msullivan on 5/7/24.
//

#pragma once
#include "CursesGUI/Elements/ielement.h"
#include <cassert>

#define CURSESGUI_VERSION_MAJOR 0
#define CURSESGUI_VERSION_MINOR 0
#define CURSESGUI_VERSION_REVISION 0

namespace CursesGUI
{
    struct CommandLineArgs
    {
        int count = 0;
        char** args = nullptr;

        const char* operator[](int n) const
        {
            assert(n < count);
            return args[n];
        }
    };

    namespace UI
    {
        void start(int argc, char* argv[]);
        void stop();
        bool isRunning();
    }
}