//
// Created by msullivan on 9/7/24.
//

#include "cobject.h"
#include "components.h"

CObject::CObject(CObject* parent) : m_Parent(parent)
{

}

CObject::~CObject()
{

}

CObject &CObject::operator=(const CObject &) noexcept
{
    // Copy everything from the original object and make a new one
}

CObject &CObject::operator=(CObject &&) noexcept
{
    // Copy everything from the original object and make a new one
}

void CObject::connect(const CObject &sender, void *signal,
                        const CObject &receiver, void *method)
{

}

void CObject::disconnect(const CObject &sender, void *signal,
                           const CObject &receiver, void *method)
{

}
