//
// Created by msullivan on 9/7/24.
//

#pragma once
#include "cregistry.h"
#include "clist.h"
#include "../../include/entt.hpp"

extern CRegistry g_Registry;

class CObject;
using CEntityID = entt::entity;
using CObjectList = CList<CObject *>;

class CObject {
public:
    explicit CObject(CObject* parent = nullptr);
    virtual ~CObject() = 0;

    CObject(const CObject&) = delete;
    CObject(CObject&&) = delete;
    CObject &operator=(const CObject &) noexcept;
    CObject &operator=(CObject &&) noexcept;

protected:
    CEntityID m_ID;
    CObject *m_Parent;
    CObjectList m_Children;

private:
    virtual void init();

public:
    [[nodiscard]] virtual CEntityID id() const { return m_ID; }
    [[nodiscard]] virtual CObject *parent() { return m_Parent; }
    [[nodiscard]] virtual CObjectList &children() { return m_Children; }

    // Signals (this will need a LOT of work and may be extraordinarily buggy)
    static void connect(const CObject &sender, void *signal,
                        const CObject &receiver, void *method);
    static void disconnect(const CObject &sender, void *signal,
                           const CObject &receiver, void *method);
};