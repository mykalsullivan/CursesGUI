//
// Created by msullivan on 5/20/24.
// TODO: Add documentation

#pragma once

namespace CursesGUI
{
    // Forward declarations
    class IElement;
    enum class Color;
    enum class ColorAttribute : unsigned int;

    void setForeground(IElement*, Color);
    void setBackground(IElement*, Color);
    void setColor(IElement*, Color foreground, Color background);
    void setAttribute(IElement*, ColorAttribute, bool);
    void resetAttributes(IElement*);

    Color getForeground(IElement*);
    Color getBackground(IElement*);
    bool hasColorAttribute(IElement*, ColorAttribute);
}