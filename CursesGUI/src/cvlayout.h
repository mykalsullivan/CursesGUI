//
// Created by msullivan on 9/7/24.
//

#pragma once
#include "clayout.h"

class CVLayout : public CLayout {
public:
    explicit CVLayout(QWidget *parent = nullptr);
    ~CVLayout() override;
};