#include "Graphics.h"
#include "OpenGLRenderer.h"
// #include "VulkanRenderer.h"
// #include "Dx12Renderer.h"

std::unique_ptr<GraphicsRenderer> CreateGraphicsRenderer(GraphicsRenderer::GraphicsAPI api)
{
	switch(api)
	{
	case GraphicsRenderer::GraphicsAPI::OpenGL:
		return std::make_unique<OpenGLRenderer>();
		// case GraphicsRenderer::GraphicsAPI::Vulkan:
			// return std::make_unique<VulkanRenderer>();
		// case GraphicsRenderer::GraphicsAPI::DirectX12:
			// return std::make_unique<Dx12Renderer>();
	default:
		return nullptr;
	}
}