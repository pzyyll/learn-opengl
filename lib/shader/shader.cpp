#include "shader.h"


Shader::Shader(const GLchar* vertexPath, const GLchar* fragmentPath)
{
    // 1. 读取shader源码
    std::string vertexCode;
    std::string fragmentCode;
    std::ifstream vShaderFile;
    std::ifstream fShaderFile;

    vShaderFile.exceptions(std::ifstream::failbit | std::ifstream::badbit);
    fShaderFile.exceptions(std::ifstream::failbit | std::ifstream::badbit);
    try
    {
        // 打开文件
        vShaderFile.open(vertexPath);
        fShaderFile.open(fragmentPath);
        std::stringstream vShaderStream, fShaderStream;
        vShaderStream << vShaderFile.rdbuf();
        fShaderStream << fShaderFile.rdbuf();
        vShaderFile.close();
        fShaderFile.close();
        vertexCode = vShaderStream.str();
        fragmentCode = fShaderStream.str();
    }
    catch(std::ifstream::failure e)
    {
        std::cout << "ERROR::SHADER::FILE_NOT_SUCCESFULLY_READ" << e.what() << std::endl;
    }

    const char* vShaderCode = vertexCode.c_str();
    const char* fShaderCode = fragmentCode.c_str();

    // 2. 创建着色器
    int success = 0;
    char infoLog[512] = {0};

    unsigned int vID = 0;
    vID = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vID, 1, &vShaderCode, NULL);
    glCompileShader(vID);

    glGetShaderiv(vID, GL_COMPILE_STATUS, &success);
    if (!success)
    {
        glGetShaderInfoLog(vID, 512, NULL, infoLog);
        std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << infoLog << std::endl;
    };

    unsigned int fID;
    fID = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fID, 1, &fShaderCode, NULL);
    glCompileShader(fID);

    glGetShaderiv(fID, GL_COMPILE_STATUS, &success);
    if (!success)
    {
        glGetShaderInfoLog(fID, 512, NULL, infoLog);
        std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << infoLog << std::endl;
    };

    // 3. 着色器程序
    _ID = glCreateProgram();
    glAttachShader(_ID, vID);
    glAttachShader(_ID, fID);
    glLinkProgram(_ID);

    glGetProgramiv(_ID, GL_LINK_STATUS, &success);
    if (!success)
    {
        glGetProgramInfoLog(_ID, 512, NULL, infoLog);
        std::cout << "ERROR::SHADER::PROGRAM::LINKING_FAILED\n" << infoLog << std::endl;
    }

    glDeleteShader(vID);
    glDeleteShader(fID);
};

Shader::~Shader()
{
    glDeleteProgram(_ID);
}

void Shader::Use()
{
    glUseProgram(_ID);
}

void Shader::SetBool(const std::string& name, bool value) const
{
    glUniform1i(glGetUniformLocation(_ID, name.c_str()), static_cast<int>(value));
}

void Shader::SetInt(const std::string& name, int value) const
{
    glUniform1i(glGetUniformLocation(_ID, name.c_str()), value);
}

void Shader::SetFloat(const std::string& name, float value) const 
{
    glUniform1f(glGetUniformLocation(_ID, name.c_str()), value);
}
