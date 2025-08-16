#include <Grid.h>

Grid::Grid(GLuint shaderProgram, glm::mat4 projection)
{
    init();

    colors = getCellColor();
    this->shaderProgram = shaderProgram;
    this->projection = projection;
    colorLocation = glGetUniformLocation(shaderProgram, "aColor"); 

    unsigned int indices[] = {
        0, 1, 2,
        2, 3, 0
    };

    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);
    glGenBuffers(1, &EBO);

    glBindVertexArray(VAO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(float) * 8, nullptr, GL_DYNAMIC_DRAW);
    glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, sizeof(float) * 2, (void *)(0));

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

    glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, sizeof(float) * 2, (void *)(0));
    glEnableVertexAttribArray(0);
    glBindVertexArray(0);
}

void Grid::init()
{
    for (int row = 0; row < numRows; ++row)
    {
        for (int column = 0; column < numColumns; ++column)
        {
            grid[row][column] = 0;
        }
    }
}

glm::vec4 Grid::toVec4(glm::vec4 color)
{
    return glm::vec4(color.r / 255.0f, color.g / 255.0f, color.b / 255.0f, color.a / 255.0f);
}

std::vector<glm::vec4> Grid::getCellColor()
{
    glm::vec4 darkGray = toVec4({26, 31, 40, 255});
    glm::vec4 green = toVec4({47, 230, 23, 255});
    glm::vec4 red = toVec4({232, 18, 18, 255});
    glm::vec4 orange = toVec4({226, 116, 17, 255});
    glm::vec4 yellow = toVec4({237, 234, 4, 255});
    glm::vec4 purple = toVec4({166, 0, 247, 255});
    glm::vec4 cyan = toVec4({21, 204, 209, 255});
    glm::vec4 blue = toVec4({13, 64, 216, 255});
    
    return {darkGray, green, red, orange, yellow, purple, cyan, blue};
}

void Grid::drawRectangle(float x, float y, float width, float height, glm::vec4 color)
{
    float vertices[] = {
        x, y,
        x + width, y,
        x + width, y + height,
        x, y + height
    };

    glBindVertexArray(VAO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferSubData(GL_ARRAY_BUFFER, 0, sizeof(vertices), vertices);

    glUseProgram(shaderProgram);

    GLuint projectionLocation = glGetUniformLocation(shaderProgram, "uProjection");
    glUniformMatrix4fv(projectionLocation, 1, GL_FALSE, glm::value_ptr(projection));

    glUniform4fv(colorLocation, 1, glm::value_ptr(color));
    glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
}

void Grid::render()
{
    for (int row = 0; row < numRows; ++row)
    {
        for (int column = 0; column < numColumns; ++column)
        {
            int cellValue = grid[row][column];
            drawRectangle(column * cellSize + 1, row * cellSize + 1, cellSize - 1, cellSize - 1, colors[cellValue]);
        }
    }            
}

Grid::~Grid()
{
    glDeleteVertexArrays(1, &VAO);
    glDeleteBuffers(1, &VBO);
    glDeleteBuffers(1, &EBO);
}