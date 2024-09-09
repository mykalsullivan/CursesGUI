//
// Created by msullivan on 9/7/24.
//

#include "clayout.h"

CLayout::CLayout(CWidget *parent)
{
    m_Parent = parent;
    m_ID = g_Registry.create();
    m_Layouts = CList<CLayout *>();
}

CLayout::~CLayout()
{
    // Remove from registry
    if (m_ID != entt::null)
        g_Registry.destroy(m_ID);
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