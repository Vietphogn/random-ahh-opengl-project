#pragma once

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <vector>

class TriangleMesh
{
public:
    TriangleMesh();
    ~TriangleMesh();
    void draw();

private:
    GLuint VAO, vertexCount; 
    std::vector<GLuint> VBOs;
};