//
// Created by msullivan on 9/9/24.
//

#pragma once

// Forward declaration(s)
class CObject;

class CEventLoop {
public:
    CEventLoop(CObject *parent = nullptr);
    ~CEventLoop();

private:
    bool m_Running;
    bool m_Paused;

public:
    void exec();
    void quit();

    void pause();
    void unpause();
    bool isPaused() const { return m_Paused; }
};