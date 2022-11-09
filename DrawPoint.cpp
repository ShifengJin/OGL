#include "DrawPoint.h"

namespace DarkerOGL {

Draw3DPoints::Draw3DPoints() {
    memset(m_modelMatrix, 0, 16 * sizeof(float));
    m_modelMatrix[0] = 1.f;
    m_modelMatrix[5] = 1.f;
    m_modelMatrix[10] = 1.f;
    m_modelMatrix[15] = 1.f;
    memset(m_viewMatrix, 0, 16 * sizeof(float));
    m_viewMatrix[0] = 1.f;
    m_viewMatrix[5] = 1.f;
    m_viewMatrix[10] = 1.f;
    m_viewMatrix[15] = 1.f;
    memset(m_projectMatrix, 0, 16 * sizeof(float));
    m_projectMatrix[0] = 1.f;
    m_projectMatrix[5] = 1.f;
    m_projectMatrix[10] = 1.f;
    m_projectMatrix[15] = 1.f;

    std::string vsCode =
        "#version 330 core                                             \n"
        "layout (location = 0) in vec3 aPos;                           \n"
        "layout (location = 1) in vec4 aColor;                         \n"
        "layout (location = 2) in float aSize;                         \n"
        "out vec4 bColor;                                              \n"
        "uniform mat4 view;                                            \n"
        "uniform mat4 model;                                           \n"
        "uniform mat4 project;                                         \n"
        "void main(){                                                  \n"
        "    gl_Position = project * view * model * vec4(aPos, 1.f);   \n"
        "    bColor = aColor;                                          \n"
        "    gl_PointSize = aSize;                                     \n"
        "}";

    std::string fsCode =
        "#version 330 core                                             \n"
        "out vec4 FragColor;                                           \n"
        "in vec4 bColor;                                               \n"
        "void main(){                                                  \n"
        "    FragColor = bColor;                                       \n"
        "}";

    m_pShader = new Shader(vsCode, fsCode);

    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);

    glBindVertexArray(VAO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, 0, NULL, GL_DYNAMIC_DRAW);
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), 0);
    glEnableVertexAttribArray(1);
    glVertexAttribPointer(0, 4, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(3 * sizeof(float)));
    glEnableVertexAttribArray(2);
    glVertexAttribPointer(2, 1, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(7 * sizeof(float)));
}

Draw3DPoints::~Draw3DPoints() {
    glDeleteVertexArrays(1, &VAO);
    glDeleteBuffers(1, &VBO);
    Clean();
    delete m_pShader;
    m_pShader = NULL;
}

void Draw3DPoints::Draw() {

    glEnable(GL_DEPTH_TEST);
    glEnable(GL_PROGRAM_POINT_SIZE);

    m_pShader->Use();

    int pointNumber = (int)(m_point3Ds.size());
    m_pointInfosBuffer = new float[(int)(8 * pointNumber)];
    m_points_mutex.lock();
    int i = 0;
    for (std::list<Point3D::ptr>::iterator iter = m_point3Ds.begin(); iter != m_point3Ds.end(); ++iter) {
        
        m_pointInfosBuffer[i * 8 + 0] = (*iter)->point.X();
        m_pointInfosBuffer[i * 8 + 1] = (*iter)->point.Y();
        m_pointInfosBuffer[i * 8 + 2] = (*iter)->point.Z();
        
        m_pointInfosBuffer[i * 8 + 3] = (*iter)->color.X();
        m_pointInfosBuffer[i * 8 + 4] = (*iter)->color.Y();
        m_pointInfosBuffer[i * 8 + 5] = (*iter)->color.Z();
        m_pointInfosBuffer[i * 8 + 6] = (*iter)->color.W();

        m_pointInfosBuffer[i * 8 + 7] = (*iter)->size;
        i++;
    }
    m_points_mutex.unlock();
    glBindVertexArray(VAO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(float) * pointNumber * 8,
        m_pointInfosBuffer, GL_DYNAMIC_DRAW);
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), 0);
    glEnableVertexAttribArray(1);
    glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(3 * sizeof(float)));
    glEnableVertexAttribArray(2);
    glVertexAttribPointer(2, 1, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(7 * sizeof(float)));

    m_pShader->SetMat4("view", m_viewMatrix);
    m_pShader->SetMat4("model", m_modelMatrix);
    m_pShader->SetMat4("project", m_projectMatrix);

    glDrawArrays(GL_POINTS, 0, pointNumber);
    glBindVertexArray(0);

    delete[] m_pointInfosBuffer;
    m_pointInfosBuffer = NULL;
    
    m_pShader->UnUse();

    glDisable(GL_PROGRAM_POINT_SIZE);
}
}