#include "DrawBox.h"

namespace DarkerOGL {

DrawBox::DrawBox()
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

    m_srcBox[0] = DarkerOGL::Vector3<float>(-0.5f, -0.5f, 0.0f);
    m_srcBox[1] = DarkerOGL::Vector3<float>(-0.5f,  0.5f, 0.0f);
    m_srcBox[2] = DarkerOGL::Vector3<float>( 0.5f, -0.5f, 0.0f);
    m_srcBox[3] = DarkerOGL::Vector3<float>( 0.5f,  0.5f, 0.0f);
    m_srcBox[4] = DarkerOGL::Vector3<float>(-0.5f, -0.5f, 1.f);
    m_srcBox[5] = DarkerOGL::Vector3<float>(-0.5f,  0.5f, 1.f);
    m_srcBox[6] = DarkerOGL::Vector3<float>( 0.5f, -0.5f, 1.f);
    m_srcBox[7] = DarkerOGL::Vector3<float>( 0.5f,  0.5f, 1.f);

    m_Draw3DLines = Draw3DLines::ptr(new Draw3DLines());
}

DrawBox::~DrawBox()
{
    glDeleteVertexArrays(1, &VAO);
    glDeleteBuffers(1, &VBO);

    delete m_pShader;
    m_pShader = NULL;

    m_Draw3DLines.reset();
}

void DrawBox::SetBoxInfo(DarkerOGL::Vector3<float> center, 
	float scale, DarkerOGL::Vector4<float> edgeColor, DarkerOGL::Vector4<float> faceColor)
{
	m_center = center;
	m_scale = scale;
	m_edgeColor = edgeColor;
	m_faceColor = faceColor;

    for (int i = 0; i < 8; ++i) {
        m_dstBox[i] = m_srcBox[i] * m_scale + m_center;
    }
    m_edges[0] = DarkerOGL::Line3D(m_dstBox[0], m_dstBox[1], m_edgeColor, 1.f);
    m_edges[1] = DarkerOGL::Line3D(m_dstBox[1], m_dstBox[3], m_edgeColor, 1.f);
    m_edges[2] = DarkerOGL::Line3D(m_dstBox[3], m_dstBox[2], m_edgeColor, 1.f);
    m_edges[3] = DarkerOGL::Line3D(m_dstBox[2], m_dstBox[0], m_edgeColor, 1.f);
    m_edges[4] = DarkerOGL::Line3D(m_dstBox[4], m_dstBox[5], m_edgeColor, 1.f);
    m_edges[5] = DarkerOGL::Line3D(m_dstBox[5], m_dstBox[7], m_edgeColor, 1.f);
    m_edges[6] = DarkerOGL::Line3D(m_dstBox[7], m_dstBox[6], m_edgeColor, 1.f);
    m_edges[7] = DarkerOGL::Line3D(m_dstBox[6], m_dstBox[4], m_edgeColor, 1.f);
    m_edges[8] = DarkerOGL::Line3D(m_dstBox[0], m_dstBox[4], m_edgeColor, 1.f);
    m_edges[9] = DarkerOGL::Line3D(m_dstBox[2], m_dstBox[6], m_edgeColor, 1.f);
    m_edges[10] = DarkerOGL::Line3D(m_dstBox[3], m_dstBox[7], m_edgeColor, 1.f);
    m_edges[11] = DarkerOGL::Line3D(m_dstBox[1], m_dstBox[5], m_edgeColor, 1.f);

    m_Draw3DLines->Clean();
    for (int i = 0; i < 12; ++i) {
        m_Draw3DLines->AddLine(m_edges[i]);
    }
    // down
    m_triangle[0] = m_dstBox[0]; 
    m_triangle[1] = m_dstBox[1]; 
    m_triangle[2] = m_dstBox[2];
    m_triangle[3] = m_dstBox[1]; 
    m_triangle[4] = m_dstBox[3]; 
    m_triangle[5] = m_dstBox[2];
    // up
    m_triangle[6] = m_dstBox[5];
    m_triangle[7] = m_dstBox[4];
    m_triangle[8] = m_dstBox[6];
    m_triangle[9] = m_dstBox[6];
    m_triangle[10] = m_dstBox[7];
    m_triangle[11] = m_dstBox[5];

    // left
    m_triangle[12] = m_dstBox[4];
    m_triangle[13] = m_dstBox[5];
    m_triangle[14] = m_dstBox[1];
    m_triangle[15] = m_dstBox[1];
    m_triangle[16] = m_dstBox[0];
    m_triangle[17] = m_dstBox[4];
    // right
    m_triangle[18] = m_dstBox[2];
    m_triangle[19] = m_dstBox[3];
    m_triangle[20] = m_dstBox[7];
    m_triangle[21] = m_dstBox[7];
    m_triangle[22] = m_dstBox[6];
    m_triangle[23] = m_dstBox[2];

    // front
    m_triangle[24] = m_dstBox[5];
    m_triangle[25] = m_dstBox[7];
    m_triangle[26] = m_dstBox[3];
    m_triangle[27] = m_dstBox[3];
    m_triangle[28] = m_dstBox[1];
    m_triangle[29] = m_dstBox[5];
    // back
    m_triangle[30] = m_dstBox[0];
    m_triangle[31] = m_dstBox[2];
    m_triangle[32] = m_dstBox[6];
    m_triangle[33] = m_dstBox[6];
    m_triangle[34] = m_dstBox[4];
    m_triangle[35] = m_dstBox[0];
}


void DrawBox::Draw()
{
    glEnable(GL_DEPTH_TEST);

    glDepthMask(GL_FALSE);
    glEnable(GL_BLEND);

    m_pShader->Use();
    for (int i = 0; i < 12; ++i) {
        m_buffer[i * 21 + 0] = m_triangle[i * 3 + 0].X();
        m_buffer[i * 21 + 1] = m_triangle[i * 3 + 0].Y();
        m_buffer[i * 21 + 2] = m_triangle[i * 3 + 0].Z();
        m_buffer[i * 21 + 3] = m_faceColor.X();
        m_buffer[i * 21 + 4] = m_faceColor.Y();
        m_buffer[i * 21 + 5] = m_faceColor.Z();
        m_buffer[i * 21 + 6] = m_faceColor.W();
    
        m_buffer[i * 21 + 7] = m_triangle[i * 3 + 1].X();
        m_buffer[i * 21 + 8] = m_triangle[i * 3 + 1].Y();
        m_buffer[i * 21 + 9] = m_triangle[i * 3 + 1].Z();
        m_buffer[i * 21 + 10] = m_faceColor.X();
        m_buffer[i * 21 + 11] = m_faceColor.Y();
        m_buffer[i * 21 + 12] = m_faceColor.Z();
        m_buffer[i * 21 + 13] = m_faceColor.W();
    
        m_buffer[i * 21 + 14] = m_triangle[i * 3 + 2].X();
        m_buffer[i * 21 + 15] = m_triangle[i * 3 + 2].Y();
        m_buffer[i * 21 + 16] = m_triangle[i * 3 + 2].Z();
        m_buffer[i * 21 + 17] = m_faceColor.X();
        m_buffer[i * 21 + 18] = m_faceColor.Y();
        m_buffer[i * 21 + 19] = m_faceColor.Z();
        m_buffer[i * 21 + 20] = m_faceColor.W();
    }
    
    glBindVertexArray(VAO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(float) * 12 * 21, m_buffer, GL_DYNAMIC_DRAW);
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 7 * sizeof(float), 0);
    glEnableVertexAttribArray(1);
    glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE, 7 * sizeof(float), (void*)(3 * sizeof(float)));
    
    m_pShader->SetMat4("view", m_viewMatrix);
    m_pShader->SetMat4("model", m_modelMatrix);
    m_pShader->SetMat4("project", m_projectMatrix);
    
    glDrawArrays(GL_TRIANGLES, 0, 36);
    glBindVertexArray(0);
    m_pShader->UnUse();

    glDisable(GL_BLEND);
    glDepthMask(GL_TRUE);

    m_Draw3DLines->SetProjectMatrix(m_projectMatrix);
    m_Draw3DLines->SetModelMatrix(m_modelMatrix);
    m_Draw3DLines->SetViewMatrix(m_viewMatrix);
    m_Draw3DLines->Draw();
}

}