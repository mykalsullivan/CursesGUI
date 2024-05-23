cmake_minimum_required(VERSION 3.25)
set(CMAKE_CXX_STANDARD 23)
project(CursesGUI VERSION 0.0.0
	DESCRIPTION "(Semi) graphical user-interface API library"
        LANGUAGES CXX)

find_package(Curses REQUIRED)
include_directories(${CURESES_INCLUDE_DIR})

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_FLAGS "-Oz -ansi -Wall -Wextra")
set(CMAKE_CXX_FLAGS_DEBUG "-g -Wall -Wextra")

set(VERSION_MAJOR 0)
set(VERSION_MINOR 0)
set(VERSION_REVISION 0)

add_library(CursesGUI_${VERSION_MAJOR}.${VERSION_MINOR}.${VERSION_REVISION}
        STATIC

        # Core
        CursesGUI/src/CursesGUI/Core/ui.cpp

        # ECS
        CursesGUI/src/CursesGUI/ECS/dimensions_system.cpp
        CursesGUI/src/CursesGUI/ECS/render_system.cpp
        CursesGUI/src/CursesGUI/ECS/info_system.cpp
        CursesGUI/src/CursesGUI/ECS/attributes_system.cpp
        CursesGUI/src/CursesGUI/ECS/movement_system.cpp
        CursesGUI/src/CursesGUI/ECS/position_system.cpp
        CursesGUI/src/CursesGUI/ECS/color_system.cpp
        CursesGUI/src/CursesGUI/ECS/utility_system.cpp
        CursesGUI/src/CursesGUI/ECS/listener_system.cpp
        CursesGUI/src/CursesGUI/ECS/child_element_lookup_system.cpp

        # Elements
        CursesGUI/src/CursesGUI/Elements/ielement.cpp
        CursesGUI/src/CursesGUI/Elements/panel.cpp
        CursesGUI/src/CursesGUI/Elements/viewport.cpp
        CursesGUI/src/CursesGUI/Elements/element.cpp
        CursesGUI/src/CursesGUI/Elements/button.cpp
        CursesGUI/src/CursesGUI/Elements/checkbox.cpp
        CursesGUI/src/CursesGUI/Elements/divider.cpp
        CursesGUI/src/CursesGUI/Elements/drop_down.cpp
        CursesGUI/src/CursesGUI/Elements/line_break.cpp
        CursesGUI/src/CursesGUI/Elements/list.cpp
        CursesGUI/src/CursesGUI/Elements/list_item.cpp
        CursesGUI/src/CursesGUI/Elements/number_field.cpp
        CursesGUI/src/CursesGUI/Elements/progress_bar.cpp
        CursesGUI/src/CursesGUI/Elements/scroll_box.cpp
        CursesGUI/src/CursesGUI/Elements/text_box.cpp
        CursesGUI/src/CursesGUI/Elements/text.cpp
        CursesGUI/src/CursesGUI/Elements/text_field.cpp

### DEPRECATED FOR NOW ###
#        # Commands
#        CursesGUI/src/CursesGUI/Commands/add/add_command.cpp
#        CursesGUI/src/CursesGUI/Commands/add/add_window_command.cpp
#        CursesGUI/src/CursesGUI/Commands/add/add_element_command.cpp
#
#        CursesGUI/src/CursesGUI/Commands/destroy/remove_command.cpp
#        CursesGUI/src/CursesGUI/Commands/destroy/remove_window_command.cpp
#        CursesGUI/src/CursesGUI/Commands/destroy/remove_element_command.cpp

#        CursesGUI/src/CursesGUI/Commands/move/move_command.cpp
#        CursesGUI/src/CursesGUI/Commands/move/move_window_command.cpp
#        CursesGUI/src/CursesGUI/Commands/move/move_element_command.cpp
#
#        CursesGUI/src/CursesGUI/Commands/set/set_input_mode_command.cpp
#
#        CursesGUI/src/CursesGUI/Commands/etc/exit_command.cpp
#        CursesGUI/src/CursesGUI/Commands/etc/empty_command.cpp
#        CursesGUI/src/CursesGUI/Commands/etc/invalid_command.cpp
#
#        CursesGUI/src/CursesGUI/Commands/debug/window_count_command.cpp
)

target_include_directories(CursesGUI_${VERSION_MAJOR}.${VERSION_MINOR}.${VERSION_REVISION}
        PRIVATE
        CursesGUI/src)
target_include_directories(CursesGUI_${VERSION_MAJOR}.${VERSION_MINOR}.${VERSION_REVISION}
        PRIVATE
        CursesGUI/include)
target_link_libraries(CursesGUI_${VERSION_MAJOR}.${VERSION_MINOR}.${VERSION_REVISION}
        ${CURSES_LIBRARIES})

set_target_properties(CursesGUI_${VERSION_MAJOR}.${VERSION_MINOR}.${VERSION_REVISION}
        PROPERTIES
        CXX_VISIBILITY_PRESET "hidden"
        VISIBILITY_INLINES_HIDDEN TRUE
)

add_executable(CursesGUI_TestClient_${VERSION_MAJOR}.${VERSION_MINOR}.${VERSION_REVISION}
        CursesGUI_TestClient/main.cpp
        CursesGUI_TestClient/application.cpp
)

target_include_directories(CursesGUI_TestClient_${VERSION_MAJOR}.${VERSION_MINOR}.${VERSION_REVISION}
        PRIVATE CursesGUI/src)
target_link_libraries(CursesGUI_TestClient_${VERSION_MAJOR}.${VERSION_MINOR}.${VERSION_REVISION}
        CursesGUI_${VERSION_MAJOR}.${VERSION_MINOR}.${VERSION_REVISION}
)
