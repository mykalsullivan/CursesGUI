//
// Created by msullivan on 5/17/24.
//

#pragma once
#include <string>
#include <functional>
#include <unordered_set>
#include <curses.h>

namespace CursesGUI
{
    using CursesWindow = WINDOW*;

    struct Lookup
    {
        CursesWindow self, parent;
    };

    struct Stats
    {
        long ticks = 0l;
    };

    using Title = std::string;

    struct Border
    {
        bool border;
    };

    struct Position
    {
        int y = -1, x = -1;
    };

    struct Dimensions
    {
        int height = -1, width = -1;
        int minHeight = -1, minWidth = -1;
        int maxHeight = -1, maxWidth = -1;
    };

    enum class PanelAttribute
    {
        HIDDEN,
        PAUSED,
        BORDER,
        MODIFIED,
        LOCKED_HEIGHT,
        LOCKED_WIDTH,
        UNLOCKABLE_HEIGHT,
        UNLOCKABLE_WIDTH,
        MOVEABLE,
        RESIZEABLE
    };

    struct Attributes
    {
        bool hidden = true;
        bool paused = false;
        bool border = false;
        bool lockedHeight = false;
        bool lockedWidth = false;
        bool unlockableHeight = true;
        bool unlockableWidth = true;
        bool moveable = true;
        bool resizeable = true;
        bool modified = true;
    };

    enum class Color
    {
        BLACK       = COLOR_BLACK,
        BLUE        = COLOR_BLUE,
        CYAN        = COLOR_CYAN,
        GREEN       = COLOR_GREEN,
        MAGENTA     = COLOR_MAGENTA,
        RED         = COLOR_RED,
        WHITE       = COLOR_WHITE,
        YELLOW      = COLOR_YELLOW,
        INHERIT,
        UNSET
    };

    enum class ColorAttribute : unsigned int
    {
        BOLD        = A_BOLD,
        ITALIC      = A_ITALIC,
        UNDERLINE   = A_UNDERLINE,
        DIM         = A_DIM,
        BLINKING    = A_BLINK,
        REVERSE     = A_REVERSE
    };

    struct Colors
    {
        Color foreground = Color::INHERIT;
        Color background = Color::INHERIT;
        bool bold = false;
        bool italic = false;
        bool underline = false;
        bool dim = false;
        bool blink = false;
        bool reverse = false;
    };

    // Forward declaration
    struct Input;

    struct TextString
    {
        std::string text;
        std::string defaultText;
    };

    using Output = void*;

    struct Parameters
    {
        int min = -1, max = -1;
    };
}