#include "main.h"

#include <RuntimeTest.h>
#include <shader.h>

int exp2() 
{
    RuntimeTest::RuntimeTest runtime = RuntimeTest::RuntimeTest();
    
    float vertices[] = {
        // 位置              // 颜色
         0.5f, -0.5f, 0.0f,  1.0f, 0.0f, 0.0f,   // 右下
        -0.5f, -0.5f, 0.0f,  0.0f, 1.0f, 0.0f,   // 左下
         0.0f,  0.5f, 0.0f,  0.0f, 0.0f, 1.0f    // 顶部
    };

    Shader shader = Shader(
        "E:\\workspace\\git-repo\\learn-opengl\\example\\hello\\hello-glsl\\exp.vs",
        "E:\\workspace\\git-repo\\learn-opengl\\example\\hello\\hello-glsl\\exp.fs");

    unsigned int vao;
    glGenVertexArrays(1, &vao);
    glBindVertexArray(vao);

    unsigned int vbo;
    // 创建顶点缓冲区对象
    glGenBuffers(1, &vbo);
    // 绑定顶点缓冲区类型
    glBindBuffer(GL_ARRAY_BUFFER, vbo);
    // 往顶点缓冲区对象输入数据
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    // 如何处理顶点缓冲区对象的数据
    // vao pointer 0 存放位置信息
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)0);
    // vao pointer 1 存放颜色信息
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)(3 * sizeof(float)));

    glEnableVertexAttribArray(0);
    glEnableVertexAttribArray(1);

    float xoffset = 0;
    float xstep = -0.01;
    auto drawcall = [&]() {
        shader.Use();
        xoffset += xstep;
        if (xoffset <= -0.5 || xoffset >= 0.5) {
            xstep = -xstep;
        }

        // shader.SetFloat("xoffset", xoffset);
        glBindVertexArray(vao);
        glDrawArrays(GL_TRIANGLES, 0, 3);
    };
    int res = runtime.Run(drawcall);
    glDeleteBuffers(1, &vbo);
    glDeleteVertexArrays(1, &vao);
    return res;
}