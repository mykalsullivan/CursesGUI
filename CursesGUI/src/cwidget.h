//
// Created by msullivan on 9/6/24.
//

#pragma once
#include "cobject.h"
#include "clist.h"
#include "crect.h"

// Forward declaration(s)
class CLayout;

class CWidgetData {

};

class CWidget : public CObject {
public:
    explicit CWidget(CWidget *parent = nullptr);
    ~CWidget() override;

    CWidget &operator=(const CWidget &);
    CWidget &operator=(CWidget &&);

protected:
    CWidget *m_Parent;
    CLayout *m_Layout;

public:
    virtual CLayout* layout() { return m_Layout; }

    virtual void show();
    virtual void hide();
};