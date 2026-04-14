#include "Engine.h"

Engine::Engine::Engine(const Core::AppData& engineData)
	: app(engineData)
{
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
