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
    // ³ÌÐòid
    unsigned int getID() { return _ID; };

    Shader(const GLchar* vertexPath, const GLchar* fragmentPath);
    ~Shader();

    void Use();

    // uniform ¹¤¾ß
    void SetBool(const std::string& name, bool value) const;
    void SetInt(const std::string& name, int value) const;
    void SetFloat(const std::string& name, float value) const;
    void SetMatrix4fv(const std::string& name, GLsizei count, GLboolean transpose, const GLfloat* value) const;

    unsigned int GetUniformLocation(const std::string& name) const;

private:
    unsigned int _ID;
};


#endif  // SHADER_H