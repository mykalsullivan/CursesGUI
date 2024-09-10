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
        src/components.h
        src/cwidget.h
        src/cwidget.cpp
        src/renderer.h
        src/renderer.cpp
        src/capplication.h
        src/capplication.cpp
        src/cobject.h
        src/cobject.cpp
        src/clayout.h
        src/cviewport.h
        src/cviewport.cpp
        src/clayout.cpp
        src/clist.h
        src/chlayout.h
        src/cvlayout.h
        src/chlayout.cpp
        src/cvlayout.cpp
        src/cstretch.h
        src/capplication.cpp
        src/cwidget_list.h
        src/main.cpp
        src/cinput.h
)

target_link_libraries(CursesGUI
        ${CURSES_LIBRARIES}
)