//
// Created by msullivan on 9/7/24.
//

#pragma once
#include "cinput.h"
#include <cassert>

// Forward declaration(s)
class CWidget;
class CWidgetList;
class CPoint;
class CPalette;
class CEvent;

struct CCommandLineArgs
{
    int count = 0;
    char **args = nullptr;

    const char* operator[](int n) const
    {
        assert(n < count);
        return args[n];
    }
};

class CApplication {
public:
    explicit CApplication(int argc = 0, char *argv[] = nullptr);
    ~CApplication();

    CApplication(const CApplication&) = delete;
    CApplication(CApplication&&) = delete;
    CApplication& operator=(const CApplication&) = delete;
    CApplication& operator=(CApplication&&) = delete;

    static CApplication &instance();

private:
    CCommandLineArgs m_Args;
    bool m_Running;

public:
    int run();
    void exit();

    [[nodiscard]] CCommandLineArgs args() const { return m_Args; }
    [[nodiscard]] bool isRunning() const { return m_Running; }
    [[nodiscard]] static unsigned long widgetCount();
    [[nodiscard]] static unsigned long objectCount();

    CWidget *activeModalWidget();
    CWidget *activePopupWidget();
    CWidgetList allWidgets();
    void alert(CWidget *widget);
    int doubleClickInterval();
    int exec();
    CWidget *focusWidget();
    int keyboardInputInterval();
    CPalette palette(const CWidget *widget);
    void setDoubleClickInterval(int);
    void setStartDragDistance(int l);
    void setStartDragTime(int ms);
    int startDragDistance();
    int startDragTime();
    CWidget *topLevelAt(const CPoint &point);
    CWidget *topLevelAt(int x, int y);
    CWidgetList topLevelWidgets();
    CWidget *widgetAt(const CPoint &point);
    CWidget *widgetAt(int x, int y);
    virtual bool event(CEvent *e) override;
};
