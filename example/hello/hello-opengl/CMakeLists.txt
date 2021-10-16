# CMakeList.txt: hello-cmake 的 CMake 项目，在此处包括源代码并定义
# 项目特定的逻辑。
#
cmake_minimum_required (VERSION 3.8)

project ("hello-opengl")

SET(ROOT_DIR ${CMAKE_SOURCE_DIR})
SET(LIB_DIR ${ROOT_DIR}/../../../lib)

message(${ROOT_DIR})
message(${LIB_DIR})

# 将源代码添加到此项目的可执行文件。

# 第三方源代码
aux_source_directory(${LIB_DIR}/glad/src GLABSRC)
aux_source_directory(${ROOT_DIR} ROOT_SRC)

message("${ROOT_SRC}")
message("${GLABSRC}")

add_executable(hello-opengl ${ROOT_SRC} ${GLABSRC})

include_directories(${LIB_DIR}/glfw-3.3.4/include ${LIB_DIR}/glad/include)

find_library(GLFW glfw3 ${LIB_DIR}/glfw-3.3.4)

message(${GLFW})

# link_libraries(${GLFW})
target_link_libraries(hello-opengl ${GLFW})

# TODO: 如有需要，请添加测试并安装目标。
