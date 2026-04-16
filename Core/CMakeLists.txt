set(SOURCES
	"Source/App.h"
	"Source/App.cpp"
	"Source/Window/Window.h"
	"Source/Window/Window.cpp"
	"Source/Graphics/Graphics.h"
	"Source/Graphics/Graphics.cpp"
	"Source/Graphics/Vulkan.h"
	"Source/Graphics/Vulkan.cpp"
	"Source/Graphics/Shader/Shader.h"
	"Source/Graphics/Shader/Shader.cpp"
)

add_library(Core STATIC)
target_sources(Core PRIVATE ${SOURCES})

add_definitions(-DProjectDirectory=\"${PROJECT_SOURCE_DIR}\")

source_group(TREE ${CMAKE_CURRENT_SOURCE_DIR} FILES ${SOURCES})

add_compile_definitions(
	GLFW_INCLUDE_NONE
	GLM_ENABLE_EXPERIMENTAL
)

target_link_libraries(Core glfw Vulkan::Vulkan glm)
target_include_directories(Core PUBLIC "Source")
