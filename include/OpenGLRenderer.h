#pragma once

#include "Graphics.h"
#include <GLFW/glfw3.h>

class OpenGLRenderer : public GraphicsRenderer
{
public:
	OpenGLRenderer();
	~OpenGLRenderer() override;

	bool Initialize(void *windowHandle, int windowWidth, int windowHeight) override;
	void Shutdown() override;

	void NewFrame() override;
	void EndFrame() override;

	// ImGui Integration
	void ImGuiInit(void *glfwWindow) override;
	void ImGuiNewFrame() override;
	void ImGuiRenderDrawData(ImDrawData *drawData) override;
	void ImGuiShutdown() override;

	// Texture management for PDF
	unsigned int CreateTexture(int width, int height, const unsigned char *pixels, int channels) override;
	void UpdateTexture(unsigned int textureID, int width, int height, const unsigned char *pixels, int channels) override;
	void DestroyTexture(unsigned int textureID) override;
	// new drawing functions will go here

	GraphicsAPI GetAPI() const override { return GraphicsAPI::OpenGL; };

private:
	GLFWwindow *m_glfwWindow = nullptr;
	float m_clearColor[4];
};