//
// Created by msullivan on 5/20/24.
//

#pragma once
#include "ielement.h"

namespace CursesGUI
{
    class Panel : public IElement
    {
    public:
        Panel();
        explicit Panel(Panel* parent);
        ~Panel() override;
    public:
        // Prevents copying
        Panel(const Panel&) = delete;
        Panel(Panel&&) = delete;
        Panel& operator=(const Panel&) = delete;
        Panel& operator=(Panel&&) = delete;
    protected:
        std::vector<IElement*> m_Children;
        int m_Focused = -1;
    public:
        int size() { return (int) m_Children.size(); }
        bool empty() { return m_Children.empty(); }
        auto begin() { return m_Children.begin(); }
        auto end() { return m_Children.end(); }
        bool addChild(IElement&);
        bool operator<<(IElement&);

        bool removeChild(IElement&);
        bool removeChild(int n);
        IElement* getChild(int n);
        IElement* operator[](int n);
        bool hasChild(IElement&);
    };
}