#include "OpenGLRenderer.h"

OpenGLRenderer();
~OpenGLRenderer() override;

bool Initialize(void *windowHandle, int windowWidth, int windowHeight) override;
void Shutdown() override;

void NewFrame() override;
void EndFrame() override;

void ImGuiInit(void *glfwWindow) override;
void ImGuiNewFrame() override;
void ImGuiRenderDrawData(ImDrawData *drawData) override;
void ImGuiShutdown() override;

unsigned int CreateTexture(int width, int height, const unsigned char *pixels, int channels) override;
void UpdateTexture(unsigned int textureID, int width, int height, const unsigned char *pixels, int channels) override;
void DestroyTexture(unsigned int textureID) override;