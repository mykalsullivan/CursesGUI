//
// Created by msullivan on 9/7/24.
//

#include "cobject.h"
#include "../ECS/components.h"

CObject::CObject(CObject* parent) : m_Parent(parent), m_ID(g_Registry.create())
{
    init();
}

CObject::~CObject()
{
    // Remove from registry
    if (m_ID != entt::null)
        g_Registry.destroy(m_ID);
}

void CObject::init()
{
    m_ID = g_Registry.create();
    g_Registry.emplace<Data>(m_ID);
    auto& dataComponent = g_Registry.get<Data>(m_ID);
    dataComponent.framesLapsed = 0l;
}

bool CObject::attach(CListener* listener)
{

    return false;
}

bool CObject::detach(CListener* listener)
{

    return false;
}

void CObject::notify(CListener* listener)
{

}