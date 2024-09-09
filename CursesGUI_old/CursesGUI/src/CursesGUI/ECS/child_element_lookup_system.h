//
// Created by msullivan on 5/21/24.
//

#pragma once
#include <vector>

namespace CursesGUI
{
    // Forward declaration
    class IElement;

    /*
     * Looks up all elements with children and returns a vector of pointers to child elements
     * TODO: Move into 'panel' class
     */
    std::vector<IElement*> getChildren(IElement&);
}