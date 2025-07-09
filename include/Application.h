#pragma once

#include "Graphics.h"

// #include "imgui.h"
// #include "imgui_impl_glfw.h"
// #include "imgui_impl_opengl3.h"


struct GLFWwindow;
class GraphicsRenderer;

class Application
{
public:
	Application();
	~Application();

	bool Initialize(GraphicsRenderer::GraphicsAPI api);
	void Run();
	void Shutdown();

private:
	static void GlfwErrorCallback(int error, const char *descripition);
	static void GlfwFramebufferSizieCallback(GLFWwindow *window, int width, int height);

	GLFWwindow *m_window = nullptr;
	std::unique_ptr<GraphicsRenderer> m_graphicsRenderer;
	GraphicsRenderer::GraphicsAPI m_selectedGraphicsAPI;

	bool m_showDemoWindow = true;
	bool m_showAnotherWindow = false;
	ImVec4 m_clearColor;
};