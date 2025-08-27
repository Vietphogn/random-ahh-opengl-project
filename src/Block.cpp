#include <Block.h>

Block::Block()
{
    
}

Block::Block(GLuint shaderProgram, glm::mat4 projection)
{
    this->shaderProgram = shaderProgram;
    this->projection = projection;

    colors = getCellColor();
    rotationState = 1;
    rowOffset = 0;
    columnOffset = 0;

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

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

    glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, sizeof(float) * 2, (void *)(0));
    glEnableVertexAttribArray(0);
    glBindVertexArray(0);
}

Block::~Block()
{
    glDeleteVertexArrays(1, &VAO);
    glDeleteBuffers(1, &VBO);
    glDeleteBuffers(1, &EBO);
}

void Block::drawRectangle(float x, float y, float width, float height, glm::vec4 color)
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

void Block::update()
{
}

void Block::render()
{
    std::vector<glm::vec2> tiles = getCellPositions();
    for (glm::vec2 &tile : tiles)
    {
        drawRectangle(tile.x * cellSize + 1, tile.y * cellSize + 1, cellSize - 1, cellSize - 1, colors[id]);
    }
}

void Block::move(int rows, int columns)
{
    rowOffset += columns;
    columnOffset += rows;
}

void Block::rotate()
{
    rotationState = (rotationState + 1) % 4;
}

bool Block::isBlockOutside(const Grid &grid)
{
    std::vector<glm::vec2> tiles = cells[rotationState];
    for (glm::vec2 &tile : tiles)
    {
        if (grid.isCellOutside(tile.x + columnOffset, tile.y + rowOffset))
        {
            return true;
        }
    }
    return false;
}

void Block::undoRotation()
{
    rotationState = (rotationState - 1) % 4;
}

std::vector<glm::vec2> Block::getCellPositions()
{
    std::vector<glm::vec2> tiles = cells[rotationState];

    for (glm::vec2 &tile : tiles)
    {
        tile.y += rowOffset;
        tile.x += columnOffset;
    }

    return tiles;
}