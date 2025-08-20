#include <Blocks.h>

LBlock::LBlock(GLuint shaderProgram, glm::mat4 projection) : Block(shaderProgram, projection)
{
    id = 1;
    cells[0] = {glm::vec2(0, 2), glm::vec2(1, 0), glm::vec2(1, 1), glm::vec2(1, 2)};
    cells[1] = {glm::vec2(0, 1), glm::vec2(1, 1), glm::vec2(2, 1), glm::vec2(2, 2)};
    cells[2] = {glm::vec2(1, 0), glm::vec2(1, 1), glm::vec2(1, 2), glm::vec2(2, 0)};
    cells[3] = {glm::vec2(0, 0), glm::vec2(0, 1), glm::vec2(1, 1), glm::vec2(2, 1)};
    move(3, -1);
}

JBlock::JBlock(GLuint shaderProgram, glm::mat4 projection) : Block(shaderProgram, projection)
{
    id = 2;
    cells[0] = {glm::vec2(0, 0), glm::vec2(1, 0), glm::vec2(1, 1), glm::vec2(1, 2)};
    cells[1] = {glm::vec2(0, 1), glm::vec2(0, 2), glm::vec2(1, 1), glm::vec2(2, 1)};
    cells[2] = {glm::vec2(1, 0), glm::vec2(1, 1), glm::vec2(1, 2), glm::vec2(2, 2)};
    cells[3] = {glm::vec2(0, 1), glm::vec2(1, 1), glm::vec2(2, 0), glm::vec2(2, 1)};
    move(3, -1);
}

IBlock::IBlock(GLuint shaderProgram, glm::mat4 projection) : Block(shaderProgram, projection)
{
    id = 3;
    cells[0] = {glm::vec2(1, 0), glm::vec2(1, 1), glm::vec2(1, 2), glm::vec2(1, 3)};
    cells[1] = {glm::vec2(0, 2), glm::vec2(1, 2), glm::vec2(2, 2), glm::vec2(3, 2)};
    cells[2] = {glm::vec2(2, 0), glm::vec2(2, 1), glm::vec2(2, 2), glm::vec2(2, 3)};
    cells[3] = {glm::vec2(0, 1), glm::vec2(1, 1), glm::vec2(2, 1), glm::vec2(3, 1)};
    move(3, -2);
}

OBlock::OBlock(GLuint shaderProgram, glm::mat4 projection) : Block(shaderProgram, projection)
{
    id = 4;
    cells[0] = {glm::vec2(0, 0), glm::vec2(0, 1), glm::vec2(1, 0), glm::vec2(1, 1)};
    cells[1] = {glm::vec2(0, 0), glm::vec2(0, 1), glm::vec2(1, 0), glm::vec2(1, 1)};
    cells[2] = {glm::vec2(0, 0), glm::vec2(0, 1), glm::vec2(1, 0), glm::vec2(1, 1)};
    cells[3] = {glm::vec2(0, 0), glm::vec2(0, 1), glm::vec2(1, 0), glm::vec2(1, 1)};
    move(4, 0);
}

SBlock::SBlock(GLuint shaderProgram, glm::mat4 projection) : Block(shaderProgram, projection)
{
    id = 5;
    cells[0] = {glm::vec2(0, 1), glm::vec2(0, 2), glm::vec2(1, 0), glm::vec2(1, 1)};
    cells[1] = {glm::vec2(0, 1), glm::vec2(1, 1), glm::vec2(1, 2), glm::vec2(2, 2)};
    cells[2] = {glm::vec2(1, 1), glm::vec2(1, 2), glm::vec2(2, 0), glm::vec2(2, 1)};
    cells[3] = {glm::vec2(0, 0), glm::vec2(1, 0), glm::vec2(1, 1), glm::vec2(2, 1)};
    move(3, -1);
}

TBlock::TBlock(GLuint shaderProgram, glm::mat4 projection) : Block(shaderProgram, projection)
{
    id = 6;
    cells[0] = {glm::vec2(0, 1), glm::vec2(1, 0), glm::vec2(1, 1), glm::vec2(1, 2)};
    cells[1] = {glm::vec2(0, 1), glm::vec2(1, 1), glm::vec2(1, 2), glm::vec2(2, 1)};
    cells[2] = {glm::vec2(1, 0), glm::vec2(1, 1), glm::vec2(1, 2), glm::vec2(2, 1)};
    cells[3] = {glm::vec2(0, 1), glm::vec2(1, 0), glm::vec2(1, 1), glm::vec2(2, 1)};
    move(3, -1);
}

ZBlock::ZBlock(GLuint shaderProgram, glm::mat4 projection) : Block(shaderProgram, projection)
{
    id = 7;
    cells[0] = {glm::vec2(0, 0), glm::vec2(0, 1), glm::vec2(1, 1), glm::vec2(1, 2)};
    cells[1] = {glm::vec2(0, 2), glm::vec2(1, 1), glm::vec2(1, 2), glm::vec2(2, 1)};
    cells[2] = {glm::vec2(1, 0), glm::vec2(1, 1), glm::vec2(2, 1), glm::vec2(2, 2)};
    cells[3] = {glm::vec2(0, 1), glm::vec2(1, 0), glm::vec2(1, 1), glm::vec2(2, 0)};
    move(3, -1);
}