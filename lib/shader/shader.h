#ifndef SHADER_H
#define SHADER_H

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <string>
#include <fstream>
#include <sstream>
#include <iostream>


class Shader
{
public:
    // ����id
    unsigned int getID() { return _ID; };

    Shader(const GLchar* vertexPath, const GLchar* fragmentPath);
    ~Shader();

    void Use();

    // uniform ����
    void SetBool(const std::string& name, bool value) const;
    void SetInt(const std::string& name, int value) const;
    void SetFloat(const std::string& name, float value) const;

private:
    unsigned int _ID;
};


#endif  // SHADER_H