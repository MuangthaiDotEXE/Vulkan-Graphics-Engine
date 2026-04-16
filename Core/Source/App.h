#pragma once

#ifndef APP_H
#define APP_H

#include <string>
#include <memory>
#include <array>

#include "Window/Window.h"
#include "Graphics/Graphics.h"
#include "Graphics/Vulkan.h"
#include "Graphics/Shader/Shader.h"

namespace Core
{
	struct AppData
	{
		WindowData windowData;
		std::array<unsigned int, 3> appVersion = { 0, 0, 0 };
		std::array<unsigned int, 3> engineVersion = { 0, 0, 0 };
		std::string appName = "App";
		std::string engineName = "Engine";
	};

	class App
	{
	private:
		AppData appData;

	public:
		std::unique_ptr<Window> window;
		std::unique_ptr<Graphics> graphics;

	public:
		App(const AppData& appData);
		virtual ~App();

		void Render();
		void Update();
	};
}

#endif
