#include "Shader.h"

Core::Shader::Shader(VkDevice device, const std::string& vertexPath, const std::string& fragmentPath)
    : device(device)
{
    CreateGraphicsPipeline(vertexPath, fragmentPath);
}

Core::Shader::~Shader()
{
}

std::vector<char> Core::Shader::ReadFile(const std::string& path)
{
    std::ifstream file(path, std::ios::ate | std::ios::binary);

    if (!file.is_open())
        throw std::runtime_error("Failed to open file (File input stream)");

    size_t fileSize = (size_t)file.tellg();

    std::vector<char> buffer(fileSize);
    file.seekg(0);
    file.read(buffer.data(), fileSize);
    file.close();

    return buffer;
}

void Core::Shader::CreateGraphicsPipeline(const std::string& vertexPath, const std::string& fragmentPath)
{
    auto vertexShaderCode = ReadFile(vertexPath);
    auto fragmentShaderCode = ReadFile(fragmentPath);

    VkShaderModule vertexShaderModule = CreateShaderModule(vertexShaderCode);
    VkShaderModule fragmentShaderModule = CreateShaderModule(fragmentShaderCode);

    VkPipelineShaderStageCreateInfo vertexShaderStageInfo{};
    vertexShaderStageInfo.sType = VK_STRUCTURE_TYPE_PIPELINE_SHADER_STAGE_CREATE_INFO;
    vertexShaderStageInfo.stage = VK_SHADER_STAGE_VERTEX_BIT;
    vertexShaderStageInfo.module = vertexShaderModule;
    vertexShaderStageInfo.pName = "main";

    VkPipelineShaderStageCreateInfo fragmentShaderStageInfo{};
    fragmentShaderStageInfo.sType = VK_STRUCTURE_TYPE_PIPELINE_SHADER_STAGE_CREATE_INFO;
    fragmentShaderStageInfo.stage = VK_SHADER_STAGE_FRAGMENT_BIT;
    fragmentShaderStageInfo.module = fragmentShaderModule;
    fragmentShaderStageInfo.pName = "main";

    VkPipelineShaderStageCreateInfo shaderStages[] = { vertexShaderStageInfo, fragmentShaderStageInfo };

    vkDestroyShaderModule(device, vertexShaderModule, nullptr);
    vkDestroyShaderModule(device, fragmentShaderModule, nullptr);
}

VkShaderModule Core::Shader::CreateShaderModule(const std::vector<char>& code)
{
    VkShaderModuleCreateInfo createInfo{};
    createInfo.sType = VK_STRUCTURE_TYPE_SHADER_MODULE_CREATE_INFO;
    createInfo.codeSize = code.size();
    createInfo.pCode = reinterpret_cast<const uint32_t*>(code.data());

    VkShaderModule shaderModule;
    if (vkCreateShaderModule(device, &createInfo, nullptr, &shaderModule) != VK_SUCCESS)
        throw std::runtime_error("Failed to create Vulkan graphics API shader module (Vulkan graphics API)");

    return shaderModule;
}
