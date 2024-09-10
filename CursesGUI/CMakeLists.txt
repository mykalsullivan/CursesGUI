cmake_minimum_required(VERSION 3.25)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_FLAGS "-Oz -ansi -Wall -Wextra")
set(CMAKE_CXX_FLAGS_DEBUG "-g -Wall -Wextra")

set(VERSION_MAJOR 0)
set(VERSION_MINOR 0)
set(VERSION_REVISION 0)
project(CursesGUI VERSION ${VERSION_MAJOR}.${VERSION_MINOR}.${VERSION_REVISION}
        DESCRIPTION "(Semi) graphical user-interface API library that aims to bring Qt to the command-line."
        LANGUAGES CXX)

find_package(Curses REQUIRED)

add_executable(CursesGUI
        src/ECS/components.h
        src/CursesGUI/cwidget.h
        src/CursesGUI/cwidget.cpp
        src/ECS/render_system.h
        src/ECS/render_system.cpp
        src/ECS/dimensions_system.h
        src/ECS/dimensions_system.cpp
        src/ECS/attributes_system.h
        src/ECS/attributes_system.cpp
        src/ECS/position_system.h
        src/ECS/position_system.cpp
        src/ECS/utility_system.h
        src/ECS/utility_system.cpp
        src/ECS/color_system.h
        src/ECS/color_system.cpp
        src/CursesGUI/capplication.h
        src/CursesGUI/capplication.cpp
        src/CursesGUI/cobject.h
        src/CursesGUI/cobject.cpp
        src/CursesGUI/clayout.h
        src/CursesGUI/cviewport.h
        src/CursesGUI/cviewport.cpp
        src/CursesGUI/cregistry.cpp
        src/CursesGUI/cregistry.h
        src/CursesGUI/clayout.cpp
        src/CursesGUI/clist.h
        src/CursesGUI/chlayout.h
        src/CursesGUI/cvlayout.h
        src/CursesGUI/chlayout.cpp
        src/CursesGUI/cvlayout.cpp
        src/CursesGUI/cstretch.h
        src/CursesGUI/capplication.cpp
        src/CursesGUI/cwidget_list.h
        src/main.cpp
        src/CursesGUI/cinput.h
)

target_link_libraries(CursesGUI
        ${CURSES_LIBRARIES}
)