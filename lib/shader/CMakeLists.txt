# CMakeList.txt: shader 的 CMake 项目，在此处包括源代码并定义
# 项目特定的逻辑。
#
cmake_minimum_required (VERSION 3.8)

project ("shader_test")

SET(ROOT_DIR ${CMAKE_SOURCE_DIR})
SET(LIB_DIR ${ROOT_DIR}/..)

message(${ROOT_DIR})
message(${LIB_DIR})

# 第三方源代码
aux_source_directory(${LIB_DIR}/glad/src GLABSRC)
aux_source_directory(${ROOT_DIR} ROOT_SRC)

message("{ROOT_SRC}")
message("${GLABSRC}")

# 将源代码添加到此项目的可执行文件。
add_executable(shader_test ${ROOT_SRC} ${GLABSRC})

# TODO: 如有需要，请添加测试并安装目标。

include_directories(${LIB_DIR}/glfw-3.3.4/include ${LIB_DIR}/glad/include)

find_library(GLFW glfw3 ${LIB_DIR}/glfw-3.3.4)

message(${GLFW})

# link_libraries(${GLFW})
target_link_libraries(shader_test ${GLFW})

# TODO: 如有需要，请添加测试并安装目标。