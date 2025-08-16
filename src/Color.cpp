#include <Color.h>

glm::vec4 toVec4(glm::vec4 color)
{
    return glm::vec4(color.r / 255.0f, color.g / 255.0f, color.b / 255.0f, color.a / 255.0f);
}

std::vector<glm::vec4> getCellColor()
{
    return {darkGray, green, red, orange, yellow, purple, cyan, blue};
}