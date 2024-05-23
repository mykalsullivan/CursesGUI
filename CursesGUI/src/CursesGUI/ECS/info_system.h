//
// Created by msullivan on 5/20/24.
//

#pragma once

namespace CursesGUI
{
    // Forward declaration
    class IElement;

    /*
     * Increments the frame counter on an element
     */
    void incrementTickCounter(IElement&);

    /*
     * Returns the frame counter on an element
     */
    long getTicks(IElement&);
}