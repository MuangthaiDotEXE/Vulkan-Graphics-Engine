#pragma once

#ifndef VULKAN_API_H
#define VULKAN_API_H

#include <stdexcept>

#include <vulkan/vulkan.h>
#include <GLFW/glfw3.h>

#include "Graphics.h"

namespace Core
{
	class Vulkan final : public Graphics
	{
	private:
		VkInstance instance;

	public:
		Vulkan();
		virtual ~Vulkan();

		void Render() override;
		void Update() override;

	private:
		void CreateInstance();
		void Cleanup();
	};
}

#endif
