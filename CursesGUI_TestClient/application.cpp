//
// Created by msullivan on 5/7/24.
//

#include "application.h"
#include "CursesGUI/Elements/panel.h"
#include "CursesGUI/ECS/position_system.h"
#include "CursesGUI/ECS/dimensions_system.h"
#include "CursesGUI/ECS/render_system.h"
#include "CursesGUI/Elements/element.h"

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
    setPosition(panel, 5, getWidth(panel)+2);
    setDimensions(panel, getHeight(panel)/2, getWidth(panel));
    panel.show();

    Element element;
    setPosition(element, 1, 2);
    setDimensions(element, 5, 10);
    element.setParent(panel);
    element.show();

    panel.addChild(element);

    while (UI::isRunning())
    {
        UI::reset();
        UI::update();
        UI::draw();
    }
    UI::stop();
    return 0;
}