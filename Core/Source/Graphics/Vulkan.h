#pragma once

#ifndef VULKAN_API_H
#define VULKAN_API_H

#include <print>
#include <iostream>
#include <cstdio>
#include <vector>
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
		VkDebugUtilsMessengerEXT debugMessenger;

	public:
		Vulkan();
		virtual ~Vulkan();

		void Render() override;
		void Update() override;

	private:
		void CreateInstance();
		void SetupDebugMessenger();
		void Cleanup();

		void PopulateDebugMessengerCreateInfo(VkDebugUtilsMessengerCreateInfoEXT& createInfo);
		std::vector<const char*> GetRequiredExtensions();
		bool CheckValidationLayerSupport();
		static VKAPI_ATTR VkBool32 VKAPI_CALL DebugCallback(VkDebugUtilsMessageSeverityFlagBitsEXT messageSeverity, VkDebugUtilsMessageTypeFlagsEXT messageType, const VkDebugUtilsMessengerCallbackDataEXT* pCallbackData, void* pUserData);
	};
}

#endif
