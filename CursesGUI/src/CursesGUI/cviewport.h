//
// Created by msullivan on 9/7/24.
//

#pragma once
#include "cwidget.h"

// Foward declaration(s)
class CApplication;

class CViewport final : public CWidget {
    friend CApplication;
    CViewport();

public:
    ~CViewport() override;

private:
    void init() override;
};