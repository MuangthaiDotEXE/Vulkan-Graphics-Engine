#include "App.h"

Core::App::App(const AppData& appData)
	: appData(appData)
{
	if (this->appData.windowData.title.empty() && !this->appData.appName.empty())
		this->appData.windowData.title = this->appData.appName;

	window = std::make_unique<Window>(appData.windowData);
	graphics = std::make_unique<Vulkan>(window->GetWindow());
}

Core::App::~App()
{
}

void Core::App::Render()
{
	window->Render();
	graphics->Render();
}

void Core::App::Update()
{
	window->Update();
	window->Input();
	graphics->Update();
}
