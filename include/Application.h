#pragma once

#include "GUI.h"
#include <imgui.h>

class Application : public GUI
{
public:
    // Our state
    bool show_demo_window;
    bool show_another_window;
    ImVec4 clear_color;

    void Init() override;
    void Loop() override;
    void Render() override;
    void CleanUp() override;
};