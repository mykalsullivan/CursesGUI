//
// Created by msullivan on 9/6/24.
//

#pragma once
#include <ncurses.h>

using CursesWindow = WINDOW*;

struct Data {
    long framesLapsed;
};

struct CursesWindowComponent {
    CursesWindow self, parent;
};

struct Position {
    short *y, *x;
};

struct Dimensions {
    short *height, *width, minHeight, minWidth, maxHeight, maxWidth;
};

struct Colors {
    short foreground, background;
};

struct WidgetCursor {
    short *y, *x;
    short type;
};

struct WidgetAttributes {
    bool hidden;
    bool underlined;
    bool bold;
};