#include <Grid.h>

Grid::Grid()
{

}

Grid::Grid(GLuint shaderProgram, glm::mat4 projection)
{
    init();

    this->shaderProgram = shaderProgram;
    this->projection = projection;
    colors = getCellColor();

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

    GLuint colorLocation = glGetUniformLocation(shaderProgram, "aColor"); 
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

bool Grid::isCellOutside(int column, int row) const
{
    return !(row >= 0 && row < numRows && column >= 0 && column < numColumns);
}