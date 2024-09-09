//
// Created by msullivan on 5/20/24.
//

#pragma once

namespace CursesGUI
{
    // Forward declaration
    class IElement;

    /*
     * Moves element on the vertical axis (y-axis) relative to its current position
     * Returns false if element cannot be moved
     */
    bool moveVertical(IElement&, int);

    /*
     * Moves element on the horizontal axis (x-axis) relative to its current position
     * Returns false if element cannot be moved
     */
    bool moveHorizontal(IElement&, int);

    /*
     * Moves element on vertical and horizontal axes relative to its current position
     */
    int move(IElement&, int y, int x);
}