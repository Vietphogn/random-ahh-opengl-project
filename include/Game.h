#pragma once

#include <random>

#include <Grid.h>
#include <Blocks.h>

class Game
{
public:
    Game(GLFWwindow *window, GLuint shaderProgram, glm::mat4 projection);

    void handleInput(GLFWwindow *window);
    void render();
    void update();

private:
    std::vector<Block> blocks;
    std::vector<Block> allBlocks;

    Block currentBlock;
    Block nextBlock;
    Grid grid; 

    static Game *instance;

    Block getRandomBlock();
    void getAllBlocks();
    int generateRandomNumber(int minValue, int maxValue);

    void moveLeft();
    void moveRight();
    void moveDown();
    void rotateBlock();
    void keyCallback(GLFWwindow *window, int key, int scancode, int action, int mods);
};