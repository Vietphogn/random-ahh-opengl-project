#pragma once

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>

#include <vector>
#include <map>

#include <Color.h>
#include <Grid.h>

class Block
{
public:
    int id;
    
    Block();
    Block(GLuint shaderProgram, glm::mat4 projection);
    ~Block();

    void move(int rows, int columns);
    void render();
    void update();
    void rotate();
    void undoRotation();
    bool isBlockOutside(const Grid &grid);
    std::vector<glm::vec2> getCellPositions();
    
protected:
    std::map<int, std::vector<glm::vec2>> cells;

private:
    static constexpr int cellSize = 45;

    int rotationState;
    int rowOffset, columnOffset;

    GLuint shaderProgram;
    GLuint VAO, VBO, EBO; 

    glm::mat4 projection;

    std::vector<glm::vec4> colors;

    void drawRectangle(float x, float y, float width, float height, glm::vec4 color);
};