#include <TriangleMesh.h>

TriangleMesh::TriangleMesh()
{
    std::vector<float> positions = {
        -0.5f, -0.5f,
        0.5f, -0.5f,
        0.0f, 0.5f
    };

    std::vector<int> colorIndices = {
        0, 1, 2
    };

    glGenVertexArrays(1, &VAO);
    glBindVertexArray(VAO);

    VBOs.resize(2);

    glGenBuffers(2, VBOs.data());

    glBindBuffer(GL_ARRAY_BUFFER, VBOs[0]);

    glBufferData(GL_ARRAY_BUFFER, positions.size() * sizeof(float), positions.data(), GL_STATIC_DRAW);
    glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(float), (void *)(0));
    glEnableVertexAttribArray(0);

    glVertexAttribIPointer(1, 1, GL_INT, sizeof(float), (void *)(0));
    glEnableVertexAttribArray(1);

    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);
}

void TriangleMesh::draw()
{
    glBindVertexArray(VAO);
    glDrawArrays(GL_TRIANGLES, 0, 3);    
}

TriangleMesh::~TriangleMesh()
{
    glDeleteVertexArrays(1, &VAO);
    glDeleteBuffers(VBOs.size(), VBOs.data());
}