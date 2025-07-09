#pragma once

#include <imgui.h>
#include <memory>

class GraphicsRenderer
{
public:
	enum class GraphicsAPI
	{
		OpenGL,
		Vulkan,
		DirectX12
	};

	virtual ~GraphicsRenderer() = default;

	virtual bool Initialize(void *windowHandle, int windowWidth, int windowHeight) = 0;
	virtual void Shutdown() = 0;

	virtual void NewFrame() = 0;
	virtual void EndFrame() = 0;

	// ImGui Integration
	virtual void ImGuiInit(void *glfwWindow) = 0;
	virtual void ImGuiNewFrame() = 0;
	virtual void ImGuiRenderDrawData(ImDrawData *drawData) = 0;
	virtual void ImGuiShutdown() = 0;

	// Texture management for PDF
	virtual unsigned int CreateTexture(int width, int height, const unsigned char *pixels, int channels) = 0;
	virtual void UpdateTexture(unsigned int textureID, int width, int height, const unsigned char *pixels, int channels) = 0;
	virtual void DestroyTexture(unsigned int textureID) = 0;
	// new drawing functions will go here

	virtual GraphicsAPI GetAPI() const = 0;
};

std::unique_ptr<GraphicsRenderer> CreateGraphicsRenderer(GraphicsRenderer::GraphicsAPI api);