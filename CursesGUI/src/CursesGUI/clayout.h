//
// Created by msullivan on 9/7/24.
//

#pragma once
#include "cobject.h"
#include "clist.h"

// Foward declaration(s)
class CWidget;

class CLayout : public CObject {
public:
    explicit CLayout(CWidget* parent = nullptr);
    ~CLayout() override = 0;

protected:
    CWidget* m_Parent;
    CList<CWidget*> m_Widgets;
    CList<CLayout*> m_Layouts;

public:
    virtual bool addWidget(CWidget*);
    virtual bool removeWidget(CWidget*);
    virtual bool addLayout(CLayout*);
    virtual bool removeLayout(CLayout*);
    virtual void addStretch();
};