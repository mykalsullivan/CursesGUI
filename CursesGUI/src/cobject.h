//
// Created by msullivan on 9/7/24.
//

#pragma once
#include "clist.h"
#include "cgui_string.h"
#include "cdefs.h"

class CObject;
using CObjectList = CList<CObject *>;
class CEvent;

class CObject {
public:
    explicit CObject(CObject *parent = nullptr);
    virtual ~CObject() = 0;

    CObject(const CObject&) = delete;
    CObject(CObject&&) = delete;
    CObject &operator=(const CObject &) noexcept;
    CObject &operator=(CObject &&) noexcept;

protected:
    CObject *m_Parent;
    CObjectList m_Children;

private:
    CString m_ObjectName;

public:
//    [[nodiscard]] virtual CObject *parent() { return m_Parent; }
//    [[nodiscard]] virtual CObjectList &children() { return m_Children; }
//
//    // Signals (this will need a LOT of work and may be extraordinarily buggy)
//    static void connect(const CObject &sender, void *signal,
//                        const CObject &receiver, void *method);
//    static void disconnect(const CObject &sender, void *signal,
//                           const CObject &receiver, void *method);

public:
    [[nodiscard]] const CString &objectName() const noexcept { return m_ObjectName; }
    bool blockSignals(bool block);
    const CObjectList &children();
    virtual bool event(CEvent *e);
    virtual bool eventFilter(CObject *watched, CEvent *event);
    /* Find child methods */
    bool inherits(const char *className) const;
    void installEventFilter(CObject *filterObj);
    bool isQuickItemType() const;
    bool isWidgetType() const;
    bool isWindowType() const;
    void killTimer(int id);
    CObject *parent() const;
    void removeEventFilter(CObject *obj);
    void setObjectName(const CString &name);
    void setParent(CObject *parent);
    bool signalsBlocked() const;
    int startTimer(int interval, CursesGUI::TimerType timerType = CursesGUI::CoarseTimer);
    int startTimer(std::chrono::milliseconds interval, CursesGUI::TimerType timerType = CursesGUI::CoarseTimer);
    CThread *thread() const;

public slots:
    void deleteLater();

signals:
    void destroyed(CObject *obj = nullptr);
    void objectNameChanged(const CString &objectName);

public:
    /* Connect/disconnect methods; all static */

protected:
    virtual void childEvent(CChildEvent *event);
    virtual void connectNotify(cnost CMetaMethod &signal);
    virtual void customEvent(CEvent *event);
    virtual void disconnectNotify(const CMetaMethod &signal);
    bool isSignalConnected(const CMetaMethod &signal) const;
    int receivers(const char *signal) const;
    CObject *sender() const;
    int senderSignalIndex() const;
    virtual void timerEvent(CTimerEvent *event);
};