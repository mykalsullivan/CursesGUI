//
// Created by msullivan on 9/7/24.
//

#include "clayout.h"

CLayout::CLayout(CWidget *parent)
{
    m_Parent = parent;
    m_Layouts = CList<CLayout *>();
}

CLayout::~CLayout()
{

}

bool CLayout::addWidget(CWidget *widget)
{

    return false;
}

bool CLayout::removeWidget(CWidget *widget)
{

    return false;
}

bool CLayout::addLayout(CLayout *)
{

    return false;
}

bool CLayout::removeLayout(CLayout *)
{

    return false;
}

void CLayout::addStretch()
{

}