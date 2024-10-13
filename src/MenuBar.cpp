#include "App.h"

void App::ShowMenubar()
{
	// Menu bar
	if(ImGui::BeginMainMenuBar())
	{
		// File menu
		if(ImGui::BeginMenu("File"))
		{
			if(ImGui::MenuItem("New"))
			{

			}

			if(ImGui::MenuItem("Open"))
			{

			}

			if(ImGui::MenuItem("Save"))
			{

			}

			if(ImGui::MenuItem("Exit"))
			{

			}

			ImGui::EndMenu();
		}

		// Edit menu
		if(ImGui::BeginMenu("Edit"))
		{
			if(ImGui::MenuItem("Undo"))
			{

			}

			if(ImGui::MenuItem("Redo"))
			{

			}

			if(ImGui::MenuItem("Cut"))
			{

			}

			if(ImGui::MenuItem("Copy"))
			{

			}

			if(ImGui::MenuItem("Paste"))
			{

			}

			ImGui::EndMenu();
		}

		// View menu
		if(ImGui::BeginMenu("View"))
		{
			if(ImGui::MenuItem("Show ImGUI Demo", nullptr, showDemoWindow_))
			{
				showDemoWindow_ = !showDemoWindow_;
			}

			ImGui::EndMenu();
		}

		// Help menu
		if(ImGui::BeginMenu("Help"))
		{
			if(ImGui::MenuItem("Documentation"))
			{

			}

			if(ImGui::MenuItem("Support"))
			{

			}

			if(ImGui::MenuItem("About"))
			{

			}

			ImGui::EndMenu();
		}

		ImGui::EndMainMenuBar();
	}
}
