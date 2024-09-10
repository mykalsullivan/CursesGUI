//
// Created by msullivan on 9/9/24.
//

#pragma once
#include <ncurses.h>

using CKeyInput = unsigned int;
using CMouseInput = MEVENT;

struct CInput {
    CKeyInput key;
    CMouseInput mouse;
};

struct CBinds {

};