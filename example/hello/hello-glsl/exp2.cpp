#include "main.h"

#include <RuntimeTest.h>
#include <shader.h>

int exp2() 
{
    RuntimeTest::RuntimeTest runtime = RuntimeTest::RuntimeTest();
    
    float vertices[] = {
        // λ��              // ��ɫ
         0.5f, -0.5f, 0.0f,  1.0f, 0.0f, 0.0f,   // ����
        -0.5f, -0.5f, 0.0f,  0.0f, 1.0f, 0.0f,   // ����
         0.0f,  0.5f, 0.0f,  0.0f, 0.0f, 1.0f    // ����
    };

    Shader shader = Shader(
        "E:\\workspace\\git-repo\\learn-opengl\\example\\hello\\hello-glsl\\exp.vs",
        "E:\\workspace\\git-repo\\learn-opengl\\example\\hello\\hello-glsl\\exp.fs");

    unsigned int vao;
    glGenVertexArrays(1, &vao);
    glBindVertexArray(vao);

    unsigned int vbo;
    // �������㻺��������
    glGenBuffers(1, &vbo);
    // �󶨶��㻺��������
    glBindBuffer(GL_ARRAY_BUFFER, vbo);
    // �����㻺����������������
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    // ��δ����㻺�������������
    // vao pointer 0 ���λ����Ϣ
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)0);
    // vao pointer 1 �����ɫ��Ϣ
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