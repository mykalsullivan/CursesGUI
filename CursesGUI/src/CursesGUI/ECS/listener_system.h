//
// Created by msullivan on 5/20/24.
//

#pragma once

namespace CursesGUI
{
    // Forward declarations
    class IElement;
    class Listener;

    /*
     * Attaches a listener to an element
     * Returns false if listener cannot be attached
     */
    bool attach(IElement&, Listener*);

    /*
     * Detaches a listener from an element
     * Returns false if listener cannot be detached
     */
    bool detach(IElement&, Listener*);

    /*
     * Notifies a listener attached to an element
     * TODO: Implement
     */
    void notify(IElement&, Listener*);

    /*
     * Notifies all listeners attached to an element
     * TODO: Implement
     */
    void notifyAll(IElement&);
}