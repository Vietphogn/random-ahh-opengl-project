#include <Game.h>

Game *Game::instance = nullptr;

Game::Game(GLFWwindow *window, GLuint shaderProgram, glm::mat4 projection) : grid(shaderProgram, projection)
{
    instance = this;

    blocks = {
        IBlock(shaderProgram, projection),
        JBlock(shaderProgram, projection),
        LBlock(shaderProgram, projection),
        OBlock(shaderProgram, projection),
        SBlock(shaderProgram, projection),
        TBlock(shaderProgram, projection),
        ZBlock(shaderProgram, projection),
    };
    allBlocks = blocks;

    currentBlock = getRandomBlock();
    nextBlock = getRandomBlock();

    glfwSetKeyCallback(window, [](GLFWwindow *window, int key, int scancode, int action, int mods) {
        if (instance)
        {
            instance->keyCallback(window, key, scancode, action, mods);
        }
    });
}

void Game::update()
{
    currentBlock.update();
}

Block Game::getRandomBlock()
{
    if (blocks.empty())
    {
        getAllBlocks();
    }
    int randomIndex = generateRandomNumber(0, int(blocks.size() - 1));
    Block block = blocks[randomIndex];
    blocks.erase(blocks.begin() + randomIndex);
    return block;
}

int Game::generateRandomNumber(int minValue, int maxValue)
{
    std::random_device randomDevice;
    std::mt19937 generate(randomDevice());
    std::uniform_int_distribution distance(minValue, maxValue);

    return distance(generate);
}

void Game::getAllBlocks()
{
    blocks = allBlocks;
}

void Game::render()
{
    grid.render();
    currentBlock.render();
}

void Game::moveLeft()
{
    currentBlock.move(-1, 0);
    /*if (currentBlock.isBlockOutside(grid))
    {
        currentBlock.move(1, 0);
    }*/
}

void Game::moveRight()
{
    currentBlock.move(1, 0);
    /*if (currentBlock.isBlockOutside(grid))
    {
        currentBlock.move(-1, 0);
    }*/
}

void Game::moveDown()
{
    currentBlock.move(0, 1);
    /*if (currentBlock.isBlockOutside(grid))
    {
        currentBlock.move(0, -1);
    }*/
}

void Game::keyCallback(GLFWwindow *window, int key, int scancode, int action, int mods)
{
    if ((key == GLFW_KEY_LEFT || key == GLFW_KEY_A) && action == GLFW_PRESS)
    {
        moveLeft();
    }
    if ((key == GLFW_KEY_RIGHT || key == GLFW_KEY_D) && action == GLFW_PRESS)
    {
        moveRight();
    }
    if ((key == GLFW_KEY_DOWN || key == GLFW_KEY_S) && action == GLFW_PRESS)
    {
        moveDown();
    }
}

void Game::handleInput(GLFWwindow *window)
{
}