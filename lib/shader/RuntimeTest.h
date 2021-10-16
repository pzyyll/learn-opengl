#pragma once

#include <functional>

#include <glad/glad.h>
#include <GLFW/glfw3.h>

namespace RuntimeTest {

class RuntimeTest
{
public:
    RuntimeTest();
    int Run(const std::function<void()>& cb);
private:
    GLFWwindow* window;
};

}