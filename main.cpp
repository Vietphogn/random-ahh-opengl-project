#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

#include <Grid.h>

int screenWidth = 450;
int screenHeight = 900;
glm::mat4 projection;

void framebufferSizeCallback(GLFWwindow *window, int width, int height);
std::string loadShaderSource(const char *path);
GLuint compileShader(GLenum type, const char *source);
GLuint createShaderProgram();

int main()
{
    if (!glfwInit())
    {
        std::cout << "GLFW failed to start\n";
        return 1;
    }

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    GLFWwindow *window = glfwCreateWindow(
        screenWidth, screenHeight,
        "GLFW Tetris",
        nullptr, nullptr
    );

    if (!window)
    {
        std::cout << "Failed to create window\n";
        glfwTerminate();
        return 1;
    }

    glfwSetFramebufferSizeCallback(window, framebufferSizeCallback);
    glfwMakeContextCurrent(window);

    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        std::cout << "Failed to load GLAD\n";
        glfwDestroyWindow(window);
        glfwTerminate();
        return 1;
    }

    glViewport(0, 0, screenWidth, screenHeight);
    projection = glm::ortho(0.0f, float(screenWidth), float(screenHeight), 0.0f, -1.0f, 1.0f);
    
    GLuint shaderProgram = createShaderProgram();

    glClearColor(0.17f, 0.17f, 0.498f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    Grid grid = Grid(shaderProgram, projection); 

    while (!glfwWindowShouldClose(window))
    {
        glfwPollEvents();
        glClear(GL_COLOR_BUFFER_BIT);

        glUseProgram(shaderProgram);
        grid.render();

        glfwSwapBuffers(window);
    }

    glfwDestroyWindow(window);
    glfwTerminate();

    return 0;
}

void framebufferSizeCallback(GLFWwindow *window, int width, int height)
{
    screenWidth = width;
    screenHeight = height;
    glViewport(0, 0, width, height);

    projection = glm::ortho(0.0f, float(width), float(height), 0.0f, -1.0f, 1.0f);
}

GLuint compileShader(GLenum type, const char *source)
{
    GLuint shader = glCreateShader(type);
    glShaderSource(shader, 1, &source, nullptr);
    glCompileShader(shader);

    int success;
    glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
    if (!success)
    {
        char info[512];
        glGetShaderInfoLog(shader, 512, nullptr, info);
        std::cout << "Shader compilation error: " << info << "\n";
    }

    return shader;
}

std::string loadShaderSource(const char *path)
{
    std::ifstream file;
    std::stringstream bufferedLines;
    std::string line;

    file.open(path);
    while (std::getline(file, line))
    {
        bufferedLines << line << "\n";
    }

    std::string shaderSource = bufferedLines.str();
    bufferedLines.str("");
    file.close();

    return shaderSource;
}

GLuint createShaderProgram()
{
    GLuint shaderProgram = glCreateProgram();

    std::string vertexShaderSource = loadShaderSource("shaders/vertex.vert");
    std::string fragmentShaderSource = loadShaderSource("shaders/fragment.frag");

    GLuint vertexShader = compileShader(GL_VERTEX_SHADER, vertexShaderSource.c_str());
    GLuint fragmentShader = compileShader(GL_FRAGMENT_SHADER, fragmentShaderSource.c_str());

    glAttachShader(shaderProgram, vertexShader);
    glAttachShader(shaderProgram, fragmentShader);
    glLinkProgram(shaderProgram);

    int success;
    glGetProgramiv(shaderProgram, GL_LINK_STATUS, &success);
    if (!success)
    {
        char info[512];
        glGetProgramInfoLog(shaderProgram, 512, nullptr, info);
        std::cout << "Program link error: " << info << "\n";
    }

    glDeleteShader(vertexShader);
    glDeleteShader(fragmentShader);

    return shaderProgram;
}