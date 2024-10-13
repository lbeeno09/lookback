#include "App.h"

App::App()
{

}

App::~App()
{

}

void App::Init()
{
	// Our state
	bool showDemoWindow = false;
	PDFViewer_.Init("autofoley.pdf");
}

void App::Update()
{
	ImGui::DockSpaceOverViewport(0, ImGui::GetMainViewport());

	ShowMenubar();

	{
		ImGui::Begin("Side Menu");

		ImGui::End();
	}

	if(showDemoWindow_)
	{
		ImGui::ShowDemoWindow(&showDemoWindow_);
	}

	{
		static float f = 0.0f;
		static int counter = 0;

		ImGui::Begin("Hello, world!");

		ImGui::Text("This is some useful text.");
		ImGui::Checkbox("Demo Window", &showDemoWindow_);

		ImGui::SliderFloat("float", &f, 0.0f, 1.0f);
		ImGui::ColorEdit3("clear color", (float *)&clearColor);

		if(ImGui::Button("Button"))
		{
			counter++;
		}
		ImGui::SameLine();
		ImGui::Text("counter = %d", counter);

		ImGui::Text("Application average %.3f ms/frame (%.1f FPS)", 1000.0f / ImGui::GetIO().Framerate, ImGui::GetIO().Framerate);

		ImGui::End();
	}

	PDFViewer_.Update();
}
