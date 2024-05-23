//
// Created by msullivan on 5/7/24.
//

#include "application.h"

int main(int argc, char* argv[])
{
    auto& app = Application::get();
    return app.run(argc, argv);
}