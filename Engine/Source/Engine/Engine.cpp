#include "Engine.h"

Engine::Engine::Engine(const Core::AppData& engineData)
	: app(engineData)
{
	Core::Vulkan* vulkan = dynamic_cast<Core::Vulkan*>(app.graphics.get());
	if (vulkan)
		shader = std::make_unique<Core::Shader>(vulkan->GetLogicalDevice(), ProjectDirectory "/Resource/Shader/MeshVert.spv", ProjectDirectory "/Resource/Shader/MeshFrag.spv");
}

Engine::Engine::~Engine()
{
}

void Engine::Engine::Render()
{
	app.Render();
}

void Engine::Engine::Update()
{
	while (!app.window->ShouldClose())
	{
		app.Update();
	}
}
