cmake_minimum_required(VERSION 3.10)
set(PROJECT_NAME lookback)
project(${PROJECT_NAME} VERSION 1.0)

# C++ Standard
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

set(DEPS_DIR ${CMAKE_SOURCE_DIR}/deps)

# integrable modules
find_package(OpenGL REQUIRED)

# GLFW
set(GLFW_INCLUDE_DIR ${DEPS_DIR}/glfw/include)
set(GLFW_LIB_DIR ${DEPS_DIR}/glfw/build/src/$<CONFIG>)

# imgui
set(IMGUI_SOURCE_DIR ${DEPS_DIR}/imgui)
set(IMGUI_BACKENDS_DIR ${IMGUI_SOURCE_DIR}/backends)

# mupdf
set(MUPDF_INCLUDE_DIR ${DEPS_DIR}/mupdf/include)
set(MUPDF_LIB_DIR ${DEPS_DIR}/mupdf/platform/win32/x64/$<CONFIG>)

# Add source/header files for the app
file(GLOB_RECURSE SOURCES "src/*.cpp")
include_directories(include)
# file(GLOB_RECURSE HEADERS "include/*.h")

# Add executable
add_executable(${PROJECT_NAME} ${HEADERS} ${SOURCES})

# Set Include Directories
target_include_directories(${PROJECT_NAME} PRIVATE
	${GLFW_INCLUDE_DIR}
	${IMGUI_SOURCE_DIR}
	${IMGUI_BACKENDS_DIR}
	${MUPDF_INCLUDE_DIR}
)

# Set Lib Directories
target_sources(${PROJECT_NAME} PRIVATE
	${IMGUI_SOURCE_DIR}/imgui_demo.cpp
	${IMGUI_SOURCE_DIR}/imgui_draw.cpp
	${IMGUI_SOURCE_DIR}/imgui_tables.cpp
	${IMGUI_SOURCE_DIR}/imgui_widgets.cpp
	${IMGUI_SOURCE_DIR}/imgui.cpp
	${IMGUI_BACKENDS_DIR}/imgui_impl_opengl3.cpp
	${IMGUI_BACKENDS_DIR}/imgui_impl_glfw.cpp
)


# Link libraries
target_link_libraries(${PROJECT_NAME} PRIVATE
	OpenGL::GL
	${GLFW_LIB_DIR}/glfw3.lib
	${MUPDF_LIB_DIR}/libmupdf.lib
)