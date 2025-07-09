#include "Application.h"
#include "Graphics.h"

int main()
{
	Application app;
	if(app.Initialize(GraphicsRenderer::GraphicsAPI::OpenGL))
	{
		app.Run();
	}
	app.Shutdown();

	return 0;
}