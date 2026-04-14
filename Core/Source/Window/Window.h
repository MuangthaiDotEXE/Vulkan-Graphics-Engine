#pragma once

#ifndef WINDOW_H
#define WINDOW_H

#include <cstdio>
#include <print>
#include <string>
#include <stdexcept>

#include <vulkan/vulkan.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>

namespace Core
{
	struct WindowData
	{
		unsigned int width = 640u, height = 480u;
		std::string title;
		bool resizable = true;
		bool decorated = true;
		//bool vSync = true;
	};

	class Window
	{
	private:
		WindowData windowData;
		GLFWwindow* window;

	public:
		Window(const WindowData& windowData);
		virtual ~Window();

		void Render();
		void Update();

		[[nodiscard]] bool ShouldClose() const;
		GLFWwindow* GetWindow() const;
		glm::vec2 GetWindowSize() const;
		glm::vec2 GetFramebufferSize() const;
		glm::vec2 GetPosition() const;
	};
}

#endif
