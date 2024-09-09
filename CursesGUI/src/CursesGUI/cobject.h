//
// Created by msullivan on 9/7/24.
//

#pragma once
#include "cregistry.h"
#include "../../include/entt.hpp"

extern CRegistry g_Registry;

class CListener;
using CEntityID = entt::entity;

class CObject {
public:
    explicit CObject(CObject* parent = nullptr);
    virtual ~CObject() = 0;

    CObject(const CObject&) = delete;
    CObject(CObject&&) = delete;
    CObject& operator=(const CObject&) = delete;
    CObject& operator=(CObject&&) = delete;

protected:
    CObject* m_Parent;
    CEntityID m_ID;

private:
    virtual void init();

public:
    [[nodiscard]] virtual CEntityID getID() const { return m_ID; }

    // Listener
    virtual bool attach(CListener*);
    virtual bool detach(CListener*);
    virtual void notify(CListener*);
};