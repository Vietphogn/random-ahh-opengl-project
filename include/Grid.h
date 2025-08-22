#pragma once

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>

#include <iostream>
#include <vector>

#include <Color.h>

class Grid
{
public:
    int grid[20][10];

    Grid();
    Grid(GLuint shaderProgram, glm::mat4 projection);
    ~Grid();

    void init();
    void render();
    bool isCellOutside(int column, int row) const;
    bool isCellEmpty(int column, int row) const;

private:
    const int numRows = 20;
    const int numColumns = 10;
    const int cellSize = 45;

    std::vector<glm::vec4> colors;
    GLuint VAO, VBO, EBO;
    GLuint shaderProgram;
    glm::mat4 projection;

    void drawRectangle(float x, float y, float width, float height, glm::vec4 color);
};