#pragma once

#ifndef VULKAN_API_H
#define VULKAN_API_H

#include <print>
#include <iostream>
#include <cstdio>
#include <optional>
#include <vector>
#include <stdexcept>

#include <vulkan/vulkan.h>
#include <GLFW/glfw3.h>

#include "Graphics.h"

namespace Core
{
	struct QueueFamilyIndices
	{
		std::optional<uint32_t> graphicsFamily;

		bool IsComplete()
		{
			return graphicsFamily.has_value();
		}
	};

	class Vulkan final : public Graphics
	{
	private:
		VkInstance instance;
		VkDebugUtilsMessengerEXT debugMessenger;

		VkPhysicalDevice physicalDevice = VK_NULL_HANDLE;
		VkDevice device;

		VkQueue graphicsQueue;

	public:
		Vulkan();
		virtual ~Vulkan();

		void Render() override;
		void Update() override;

	private:
		void CreateInstance();
		void SetupDebugMessenger();
		void PickPhysicalDevice();
		void CreateLogicalDevice();
		void Cleanup();

		void PopulateDebugMessengerCreateInfo(VkDebugUtilsMessengerCreateInfoEXT& createInfo);
		std::vector<const char*> GetRequiredExtensions();
		bool CheckValidationLayerSupport();
		bool IsDeviceSuitable(VkPhysicalDevice device);
		QueueFamilyIndices FindQueueFamilies(VkPhysicalDevice device);
		static VKAPI_ATTR VkBool32 VKAPI_CALL DebugCallback(VkDebugUtilsMessageSeverityFlagBitsEXT messageSeverity, VkDebugUtilsMessageTypeFlagsEXT messageType, const VkDebugUtilsMessengerCallbackDataEXT* pCallbackData, void* pUserData);
	};
}

#endif
