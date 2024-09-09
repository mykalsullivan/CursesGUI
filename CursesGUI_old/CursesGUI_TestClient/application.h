//
// Created by msullivan on 5/7/24.
//

#pragma once

class Application
{
private:
    Application() = default;
public:
    // Returns create/get singleton instance
    static Application& get();
    // Prevents copying
    Application(const Application&) = delete;
    Application(Application&&) = delete;
    Application& operator=(const Application&) = delete;
    Application& operator=(Application&&) = delete;

    int run(int argc, char* argv[]);
};