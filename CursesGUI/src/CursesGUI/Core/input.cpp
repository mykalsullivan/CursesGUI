//
// Created by msullivan on 5/19/24.
//

#include "input.h"
#include "ui.h"

namespace CursesGUI
{
    Input getInput()
    {
        Input input;
        MEVENT mouseEvent;

        input.key = keyname(getch());
        input.mouse = mouseEvent.bstate;
        input.mouseY = mouseEvent.y;
        input.mouseX = mouseEvent.x;

        return input;
    }
}