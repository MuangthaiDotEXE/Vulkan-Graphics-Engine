#pragma once

#ifndef SHADER_H
#define SHADER_H

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <stdexcept>

#include <vulkan/vulkan.h>

namespace Core
{
	class Shader
	{
	private:
		VkDevice device;

		VkPipelineLayout pipelineLayout;

	public:
		Shader(VkDevice device, const std::string& vertexPath, const std::string& fragmentPath);
		virtual ~Shader();

	private:
		static std::vector<char> ReadFile(const std::string& path);

		void CreateGraphicsPipeline(const std::string& vertexPath, const std::string& fragmentPath);
		VkShaderModule CreateShaderModule(const std::vector<char>& code);
	};
}

#endif
