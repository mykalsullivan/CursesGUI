//
// Created by msullivan on 5/18/24.
//

#include "color_system.h"
#include "CursesGUI/ECS/components.h"
#include "CursesGUI/Elements/ielement.h"

namespace CursesGUI
{
    extern entt::registry g_Registry;

    void setForeground(IElement* element, Color color)
    {
         // Return if element->getEntity() is null
        if (!element->valid()) return;

        auto& colorComponent = g_Registry.get<Colors>(element->getEntity());
        colorComponent.foreground = color;
    }

    void setBackground(IElement* element, Color color)
    {
        // Return if element is null
        if (!element->valid()) return;

        auto& colorComponent = g_Registry.get<Colors>(element->getEntity());
        colorComponent.background = color;
    }

    void setColor(IElement* element, Color foreground, Color background)
    {
        // Return if element is null
        if (!element->valid()) return;

        auto& colorComponent = g_Registry.get<Colors>(element->getEntity());
        colorComponent.foreground = foreground;
        colorComponent.background = background;
    }

    Color getForeground(IElement* element)
    {
        // Return if element is null
        if (!element->valid()) return Color::UNSET;

        auto& colorComponent = g_Registry.get<Colors>(element->getEntity());
        return colorComponent.foreground;
    }

    Color getBackground(IElement* element)
    {
        // Return if element is null
        if (!element->valid()) return Color::UNSET;

        auto& colorComponent = g_Registry.get<Colors>(element->getEntity());
        return colorComponent.background;
    }

    void setAttribute(IElement* element, ColorAttribute colorAttribute, bool b)
    {
        // Return if element is null
        if (!element->valid()) return;

        auto& colorComponent = g_Registry.get<Colors>(element->getEntity());

        switch (colorAttribute)
        {
            case ColorAttribute::BOLD:
                colorComponent.bold = b;
                break;
            case ColorAttribute::ITALIC:
                colorComponent.italic = b;
                break;
            case ColorAttribute::UNDERLINE:
                colorComponent.underline = b;
                break;
            case ColorAttribute::DIM:
                colorComponent.dim = b;
                break;
            case ColorAttribute::BLINKING:
                colorComponent.blink = b;
                break;
            case ColorAttribute::REVERSE:
                colorComponent.reverse = b;
                break;
            default:
                break;
        }
    }

    void resetAttributes(IElement* element)
    {
        // Return if element is null
        if (!element->valid()) return;

        // Set all attributes to false
        auto& colorComponent = g_Registry.get<Colors>(element->getEntity());
        colorComponent.bold = false;
        colorComponent.italic = false;
        colorComponent.underline = false;
        colorComponent.dim = false;
        colorComponent.blink = false;
        colorComponent.reverse = false;
    }

    bool hasColorAttribute(IElement* element, ColorAttribute colorAttribute)
    {
        // Return if element is null
        if (!element->valid()) return false;

        auto& colorComponent = g_Registry.get<Colors>(element->getEntity());
        bool bold = colorComponent.bold;
        bool italic = colorComponent.italic;
        bool underline = colorComponent.underline;
        bool dim = colorComponent.dim;
        bool blink = colorComponent.blink;
        bool reverse = colorComponent.reverse;
        bool unset = !bold && !italic && !underline && !dim && !blink && !reverse;

        switch (colorAttribute)
        {
            case ColorAttribute::BOLD: return bold;
            case ColorAttribute::ITALIC: return italic;
            case ColorAttribute::UNDERLINE: return underline;
            case ColorAttribute::DIM: return dim;
            case ColorAttribute::BLINKING: return blink;
            case ColorAttribute::REVERSE: return reverse;
        }
        return unset;
    }
}