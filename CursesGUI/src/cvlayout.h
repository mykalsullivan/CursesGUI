//
// Created by msullivan on 9/7/24.
//

#pragma once
#include "clayout.h"

// Forward declaration(s)
class CWidget;

class CVLayout : public CLayout {
public:
    explicit CVLayout(CWidget *parent = nullptr);
    ~CVLayout() override;
};