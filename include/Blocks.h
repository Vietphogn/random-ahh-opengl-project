#pragma once

#include <Block.h>
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>

class LBlock : public Block
{
public:
    LBlock(GLuint shaderProgram, glm::mat4 projection);
};

class JBlock : public Block
{
public:
    JBlock(GLuint shaderProgram, glm::mat4 projection);
};

class IBlock : public Block
{
public:
    IBlock(GLuint shaderProgram, glm::mat4 projection);
};

class OBlock : public Block
{
public:
    OBlock(GLuint shaderProgram, glm::mat4 projection);
};

class SBlock : public Block
{
public:
    SBlock(GLuint shaderProgram, glm::mat4 projection);
};

class TBlock : public Block
{
public:
    TBlock(GLuint shaderProgram, glm::mat4 projection);
};

class ZBlock : public Block
{
public:
    ZBlock(GLuint shaderProgram, glm::mat4 projection);
};