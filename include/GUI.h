#pragma once

#include <GLFW/glfw3.h>

class GUI
{
public:
    GLFWwindow* window;

public:
    GUI();
    ~GUI();

    void Run();

protected:
    virtual void Init();
    void MainLoop();
    virtual void Loop() = 0;
    virtual void Render() = 0;
    virtual void CleanUp();
};