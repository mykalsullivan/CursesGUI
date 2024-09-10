//
// Created by msullivan on 9/7/24.
//

#pragma once
#include "CursesGUI/clist.h"

class CObject;
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
    CObject *m_Parent;
    CObjectList m_Children;

public:
    [[nodiscard]] virtual CObject *parent() { return m_Parent; }
    [[nodiscard]] virtual CObjectList &children() { return m_Children; }

    // Signals (this will need a LOT of work and may be extraordinarily buggy)
    static void connect(const CObject &sender, void *signal,
                        const CObject &receiver, void *method);
    static void disconnect(const CObject &sender, void *signal,
                           const CObject &receiver, void *method);
};