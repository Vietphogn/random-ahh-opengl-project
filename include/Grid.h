#pragma once

#include <iostream>
#include <vector>
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>

class Grid
{
public:
    int grid[20][10];

    Grid(GLuint shaderProgram);
    ~Grid();
    void init();
    void render();

private:
    static constexpr int numRows = 20;
    static constexpr int numColumns = 10;
    static constexpr int cellSize = 45;

    std::vector<glm::vec4> colors;
    GLuint colorLocation;
    GLuint VAO, VBO, EBO;

    std::vector<glm::vec4> getCellColor();
    glm::vec4 toVec4(glm::vec4 color);
    void drawRectangle(float x, float y, float width, float height, glm::vec4 color);
};