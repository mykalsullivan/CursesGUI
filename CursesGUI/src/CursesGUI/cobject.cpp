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

CObject &CObject::operator=(const CObject &)
{
    // Copy everything from the original object and make a new one
}

CObject &CObject::operator=(CObject &&)
{
    // Copy everything from the original object and make a new one
}

void CObject::init()
{
    m_ID = g_Registry.create();
    g_Registry.emplace<Data>(m_ID);
    auto& dataComponent = g_Registry.get<Data>(m_ID);
    dataComponent.framesLapsed = 0l;
}

void CObject::connect(const CObject &sender, void *signal,
                        const CObject &receiver, void *method)
{

}

void CObject::disconnect(const CObject &sender, void *signal,
                           const CObject &receiver, void *method)
{

}
