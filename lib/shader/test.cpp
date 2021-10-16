// shader.cpp: 定义应用程序的入口点。
//

#include <iostream>

#include "shader.h"
#include "RuntimeTest.h"

using namespace std;
// using namespace RuntimeTest;
//int main()
//{
//	cout << "Hello CMake." << endl;
//
//	RuntimeTest::RuntimeTest runtime = RuntimeTest::RuntimeTest();
//	Shader shader = Shader(
//		"E:\\workspace\\git-repo\\learn-opengl\\lib\\shader\\test.vs",
//		"E:\\workspace\\git-repo\\learn-opengl\\lib\\shader\\test.fs");
//
//	float vertexs[] = {
//		0.5f, 0.0f, 0.0f,
//		-0.5f, 0.0f, 0.0f,
//		0.0, 0.5f, 0.0f
//	};
//
//	unsigned int vao;
//	glGenVertexArrays(1, &vao);
//	glBindVertexArray(vao);
//
//	unsigned int vbo;
//	glGenBuffers(1, &vbo);
//	glBindBuffer(GL_ARRAY_BUFFER, vbo);
//	glBufferData(GL_ARRAY_BUFFER, sizeof(vertexs), vertexs, GL_STATIC_DRAW);
//	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), NULL);
//	glEnableVertexAttribArray(0);
//
//	auto cb = [&] {
//		shader.Use();
//		glBindVertexArray(vao);
//		glDrawArrays(GL_TRIANGLES, 0, 3);
//	};
//
//	int res = runtime.Run(cb);
//	return res;
//}