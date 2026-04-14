#pragma once

#ifndef ENGINE_H
#define ENGINE_H

#include "App.h"

namespace Engine
{
	class Engine
	{
	private:
		Core::AppData engineData;

		Core::App app;

	public:
		Engine(const Core::AppData& engineData = Core::AppData());
		virtual ~Engine();

		void Render();
		void Update();
	};
}

#endif
