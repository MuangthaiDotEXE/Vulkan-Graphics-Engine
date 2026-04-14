set(SOURCES
	"Source/Main.cpp"
	"Source/Engine/Engine.h"
	"Source/Engine/Engine.cpp"
)

add_executable(Engine)
target_sources(Engine PRIVATE ${SOURCES})

source_group(TREE ${CMAKE_CURRENT_SOURCE_DIR} FILES ${SOURCES})

add_compile_definitions(
	GLFW_INCLUDE_NONE
	GLM_ENABLE_EXPERIMENTAL
)

target_link_libraries(Engine Core)
target_include_directories(Engine PRIVATE "Source")

if (MSVC)
	set_target_properties(Engine PROPERTIES VS_DEBUGGER_WORKING_DIRECTORY "${CMAKE_SOURCE_DIR}/Engine")
endif()
