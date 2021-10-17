# CMakeList.txt: hello-cmake 的 CMake 项目，在此处包括源代码并定义
# 项目特定的逻辑。
#
cmake_minimum_required (VERSION 3.8)

project ("hello-trans")

SET(ROOT_DIR ${CMAKE_SOURCE_DIR})
SET(LIB_DIR ${ROOT_DIR}/../../../lib)

message(${ROOT_DIR})
message(${LIB_DIR})

# 将源代码添加到此项目的可执行文件。

# 第三方源代码
aux_source_directory(${LIB_DIR}/glad/src GLABSRC)
aux_source_directory(${ROOT_DIR} ROOT_SRC)
aux_source_directory(${LIB_DIR}/shader SHADER_SRC)
aux_source_directory(${LIB_DIR}/stb STB_SRC)

message("${ROOT_SRC}")
message("${GLABSRC}")
message("${SHADER_SRC}")
message("${STB_SRC}")

add_executable(hello-trans ${ROOT_SRC} ${GLABSRC} ${SHADER_SRC} ${STB_SRC})

include_directories(
	${LIB_DIR}/glfw-3.3.4/include 
	${LIB_DIR}/glad/include 
	${LIB_DIR}/shader
	${LIB_DIR}/stb
	${LIB_DIR}/glm)

find_library(GLFW glfw3 ${LIB_DIR}/glfw-3.3.4)

message(${GLFW})

# link_libraries(${GLFW})
target_link_libraries(hello-trans ${GLFW})

# TODO: 如有需要，请添加测试并安装目标。
