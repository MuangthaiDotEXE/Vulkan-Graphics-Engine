#include "Window.h"

static void ErrorCallback(int error, const char* description)
{
	std::print(stderr, "\033[1;31mGLFW error {}: {} (GLFW windowing API)\033[0m\n", error, description);
}

Core::Window::Window(const WindowData& windowData)
	: windowData(windowData)
{
	glfwSetErrorCallback(ErrorCallback);

	if (!glfwInit())
		throw std::runtime_error("Failed to initialize window library (GLFW windowing library)");

	if (!glfwVulkanSupported())
		throw std::runtime_error("Vulkan graphics API is not supported on this machine (GLFW windowing API)");

	glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
	glfwWindowHint(GLFW_RESIZABLE, windowData.resizable);
	glfwWindowHint(GLFW_DECORATED, windowData.decorated);
	glfwWindowHint(GLFW_VISIBLE, GLFW_FALSE);

	window = glfwCreateWindow(windowData.width, windowData.height, windowData.title.c_str(), nullptr, nullptr);
	if (!window || window == nullptr)
	{
		glfwTerminate();
		throw std::runtime_error("Failed to create window (GLFW windowing library)");
	}

	if (glfwRawMouseMotionSupported())
		glfwSetInputMode(window, GLFW_RAW_MOUSE_MOTION, GLFW_TRUE);
}

Core::Window::~Window()
{
	if (window != nullptr) glfwDestroyWindow(window);

	glfwTerminate();
}

void Core::Window::Render()
{
	glfwShowWindow(window);
}

void Core::Window::Update()
{
	glfwPollEvents();
}

void Core::Window::Input()
{
	if (glfwGetKey(window, GLFW_KEY_ESCAPE))
		glfwSetWindowShouldClose(window, true);
}

bool Core::Window::ShouldClose() const
{
	return glfwWindowShouldClose(window);
}

GLFWwindow* Core::Window::GetWindow() const
{
	assert(window);
	return window;
}

glm::vec2 Core::Window::GetWindowSize() const
{
	int width, height;
	glfwGetWindowSize(window, &width, &height);

	return glm::vec2(width, height);
}

glm::vec2 Core::Window::GetFramebufferSize() const
{
	int width, height;
	glfwGetFramebufferSize(window, &width, &height);

	return glm::vec2(width, height);
}

glm::vec2 Core::Window::GetPosition() const
{
	int x, y;
	glfwGetWindowPos(window, &x, &y);

	return glm::vec2(x, y);
}
