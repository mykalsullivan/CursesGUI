//
// Created by msullivan on 5/21/24.
//

#pragma once

namespace CursesGUI
{
    // Forward declaration
    class IElement;
    enum class PanelAttribute;

    /*
     * Sets the value of an element attribute
     */
    void setAttribute(IElement&, PanelAttribute, bool);

    /*
     * Returns true if an element has a specific attribute (false otherwise)
     */
    bool getAttribute(IElement&, PanelAttribute);
}