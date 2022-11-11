#include "DrawLines.h"

namespace DarkerOGL {

Draw2DLines::Draw2DLines()
{
    std::string vsCode =
        "#version 330 core                                             \n"
        "layout (location = 0) in vec2 aPos;                           \n"
        "layout (location = 1) in vec3 aColor;                         \n"
        "out vec3 bColor;                                              \n"
        "void main(){                                                  \n"
        "    gl_Position = vec4(aPos, 0.f, 1.f);   \n"
        "    bColor = aColor;                                          \n"
        "}";

    std::string fsCode =
        "#version 330 core                                             \n"
        "out vec4 FragColor;                                           \n"
        "in vec3 bColor;                                               \n"
        "void main(){                                                  \n"
        "    FragColor = vec4(bColor, 1.f);                            \n"
        "}";

    m_pShader = new Shader(vsCode, fsCode);

    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);

    glBindVertexArray(VAO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, 0, NULL, GL_DYNAMIC_DRAW);
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(float), 0);
    glEnableVertexAttribArray(1);
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)(2 * sizeof(float)));

    m_linesInfosBuffer = NULL;
}

Draw2DLines::~Draw2DLines()
{
    glDeleteVertexArrays(1, &VAO);
    glDeleteBuffers(1, &VBO);

    delete m_pShader;
    m_pShader = NULL;

    Clean();
}

void Draw2DLines::Draw()
{
    m_pShader->Use();

    m_lines_mutex.lock();
    for (std::list<Line2D::ptr>::iterator iter = m_plines.begin(); iter != m_plines.end(); ++iter) {
        m_linesInfosBuffer = new float[14];
        m_linesInfosBuffer[0] = (*iter)->start.X();
        m_linesInfosBuffer[1] = (*iter)->start.Y();
        m_linesInfosBuffer[2] = (*iter)->color.X();
        m_linesInfosBuffer[3] = (*iter)->color.Y();
        m_linesInfosBuffer[4] = (*iter)->color.Z();

        m_linesInfosBuffer[5 + 0] = (*iter)->end.X();
        m_linesInfosBuffer[5 + 1] = (*iter)->end.Y();
        m_linesInfosBuffer[5 + 2] = (*iter)->color.X();
        m_linesInfosBuffer[5 + 3] = (*iter)->color.Y();
        m_linesInfosBuffer[5 + 4] = (*iter)->color.Z();

        glLineWidth((*iter)->size);
        glBindVertexArray(VAO);
        glBindBuffer(GL_ARRAY_BUFFER, VBO);
        glBufferData(GL_ARRAY_BUFFER, sizeof(float) * 10, m_linesInfosBuffer, GL_DYNAMIC_DRAW);
        glEnableVertexAttribArray(0);
        glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(float), 0);
        glEnableVertexAttribArray(1);
        glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)(2 * sizeof(float)));

        glDrawArrays(GL_LINE_STRIP, 0, 2);
        glBindVertexArray(0);

        delete m_linesInfosBuffer;
    }

    m_lines_mutex.unlock();

    m_pShader->UnUse();
}

Draw3DLines::Draw3DLines()
{
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
        "out vec4 bColor;                                              \n"
        "uniform mat4 view;                                            \n"
        "uniform mat4 model;                                           \n"
        "uniform mat4 project;                                         \n"
        "void main(){                                                  \n"
        "    gl_Position = project * view * model * vec4(aPos, 1.f);   \n"
        "    bColor = aColor;                                          \n"
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
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 7 * sizeof(float), 0);
    glEnableVertexAttribArray(1);
    glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE, 7 * sizeof(float), (void*)(3 * sizeof(float)));

    m_linesInfosBuffer = NULL;
}

Draw3DLines::~Draw3DLines()
{
    glDeleteVertexArrays(1, &VAO);
    glDeleteBuffers(1, &VBO);

    delete m_pShader;
    m_pShader = NULL;
    
    Clean();
}

void Draw3DLines::Draw()
{
    glEnable(GL_DEPTH_TEST);
    m_pShader->Use();

    m_lines_mutex.lock();
    for (std::list<Line3D::ptr>::iterator iter = m_plines.begin(); iter != m_plines.end(); ++iter) {
        m_linesInfosBuffer = new float[14];
        m_linesInfosBuffer[0] = (*iter)->start.X();
        m_linesInfosBuffer[1] = (*iter)->start.Y();
        m_linesInfosBuffer[2] = (*iter)->start.Z();
        m_linesInfosBuffer[3] = (*iter)->color.X();
        m_linesInfosBuffer[4] = (*iter)->color.Y();
        m_linesInfosBuffer[5] = (*iter)->color.Z();
        m_linesInfosBuffer[6] = (*iter)->color.W();

        m_linesInfosBuffer[7 + 0] = (*iter)->end.X();
        m_linesInfosBuffer[7 + 1] = (*iter)->end.Y();
        m_linesInfosBuffer[7 + 2] = (*iter)->end.Z();
        m_linesInfosBuffer[7 + 3] = (*iter)->color.X();
        m_linesInfosBuffer[7 + 4] = (*iter)->color.Y();
        m_linesInfosBuffer[7 + 5] = (*iter)->color.Z();
        m_linesInfosBuffer[7 + 6] = (*iter)->color.W();


        glLineWidth((*iter)->size);
        glBindVertexArray(VAO);
        glBindBuffer(GL_ARRAY_BUFFER, VBO);
        glBufferData(GL_ARRAY_BUFFER, sizeof(float) * 14, m_linesInfosBuffer, GL_DYNAMIC_DRAW);
        glEnableVertexAttribArray(0);
        glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 7 * sizeof(float), 0);
        glEnableVertexAttribArray(1);
        glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE, 7 * sizeof(float), (void*)(3 * sizeof(float)));

        m_pShader->SetMat4("view", m_viewMatrix);
        m_pShader->SetMat4("model", m_modelMatrix);
        m_pShader->SetMat4("project", m_projectMatrix);

        glDrawArrays(GL_LINE_STRIP, 0, 2);
        glBindVertexArray(0);

        delete m_linesInfosBuffer;
        m_linesInfosBuffer = NULL;
    }

    m_lines_mutex.unlock();

    m_pShader->UnUse();

    glDisable(GL_DEPTH_TEST);
}

}