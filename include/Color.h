#pragma once

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>

#include <vector>

glm::vec4 toVec4(glm::vec4 color);

const glm::vec4 darkGray     = toVec4({26, 31, 40, 255});
const glm::vec4 green        = toVec4({47, 230, 23, 255});
const glm::vec4 red          = toVec4({232, 18, 18, 255});
const glm::vec4 orange       = toVec4({226, 116, 17, 255});
const glm::vec4 yellow       = toVec4({237, 234, 4, 255});
const glm::vec4 purple       = toVec4({166, 0, 247, 255});
const glm::vec4 cyan         = toVec4({21, 204, 209, 255});
const glm::vec4 blue         = toVec4({13, 64, 216, 255});

std::vector<glm::vec4> getCellColor();