//
// Created by msullivan on 5/7/24.
//

#include "application.h"
#include "CursesGUI/Elements/panel.h"
#include "CursesGUI/Elements/element.h"
#include "CursesGUI/ECS/position_system.h"
#include "CursesGUI/ECS/dimensions_system.h"
#include "CursesGUI/ECS/render_system.h"
#include "CursesGUI/ECS/movement_system.h"

Application& Application::get()
{
    static Application instance;
    return instance;
}

int Application::run(int argc, char* argv[])
{
    using namespace CursesGUI;

    UI::start(argc, argv);

    Panel panel;
    setPosition(panel, 5, 5);
    setDimensions(panel, 20, 40);
    panel.show();

    Element element;
    setPosition(element, 1, 2);
    setDimensions(element, 5, 10);
    element.show();

    panel.addChild(element);

    while (UI::isRunning())
    {
        UI::refresh();

        static int x = 0;
        if (x < 70) moveHorizontal(panel, 1);
        x++;
    }
    UI::stop();
    return 0;
}