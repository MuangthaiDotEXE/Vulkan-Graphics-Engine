#pragma once

#ifndef ENGINE_H
#define ENGINE_H

#include <memory>

#include "App.h"
#include "Graphics/Graphics.h"
#include "Graphics/Shader/Shader.h"

namespace Engine
{
	class Engine
	{
	private:
		Core::AppData engineData;

		Core::App app;
		std::unique_ptr<Core::Shader> shader;

	public:
		Engine(const Core::AppData& engineData = Core::AppData());
		virtual ~Engine();

		void Render();
		void Update();
	};
}

#endif
