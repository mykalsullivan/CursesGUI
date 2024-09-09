//
// Created by msullivan on 9/7/24.
//

#pragma once
#include <cassert>
#include "../entt.hpp"

// Forward declaration(s)
class CInput {};
class CBinds {};

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
    CApplication() = default;
    CApplication(int argc, char *argv[]);
    ~CApplication();

    CApplication(const CApplication&) = delete;
    CApplication(CApplication&&) = delete;
    CApplication& operator=(const CApplication&) = delete;
    CApplication& operator=(CApplication&&) = delete;

private:
    CCommandLineArgs m_Args;
    CInput m_InputBuffer;
    CBinds m_Binds;
    bool m_Running;

public:
    static CApplication &instance();
    int run();
    void exit();

    [[nodiscard]] long widgetCount() const;
    [[nodiscard]] long objectCount() const;
};
