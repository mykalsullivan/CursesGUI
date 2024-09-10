//
// Created by msullivan on 9/7/24.
//

#pragma once
#include "cinput.h"
#include <cassert>

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
    CInput m_InputBuffer;
    CBinds m_Binds;
    bool m_Running;

public:
    int run();
    void exit();

    [[nodiscard]] CCommandLineArgs args() const { return m_Args; }
    [[nodiscard]] CInput input() const { return m_InputBuffer; }
    [[nodiscard]] CBinds binds() const { return m_Binds; }
    [[nodiscard]] bool isRunning() const { return m_Running; }
    [[nodiscard]] static unsigned long widgetCount();
    [[nodiscard]] static unsigned long objectCount();
};
