#include "ObservedObject.h"

ObservedObject::ObservedObject(std::string modelPath){
    m_modelPath = modelPath;
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

    m_shininess = 32.f;
    m_direction[0] = -1.f; m_direction[1] = -1.f; m_direction[2] = -1.f;
    m_ambient[0] = 0.8f; m_ambient[1] = 0.8f; m_ambient[2] = 0.8f;
    m_diffuse[0] = 0.8f; m_diffuse[1] = 0.8f; m_diffuse[2] = 0.8f;
    m_specular[0] = 0.8f; m_specular[1] = 0.8f; m_specular[2] = 0.8f;
}

ObservedObject::~ObservedObject(){
    Unit();
}

void ObservedObject::Init(){
    std::string modelVs = "#version 330         \n"
                          "layout (location = 0) in vec3 aPos;                        \n"
                          "layout (location = 1) in vec3 aNormal;                     \n"
                          "layout (location = 2) in vec2 aTexCoords;                  \n"
                          "out vec2 TexCoords;                                        \n"
                          "out vec3 FragPos;                                          \n"
                          "out vec3 Normal;                                           \n"
                          "uniform mat4 model;                                        \n"
                          "uniform mat4 view;                                         \n"
                          "uniform mat4 projection;                                   \n"
                          "void main(){                                               \n"
                          "    TexCoords = aTexCoords;                                \n"
                          "    FragPos = vec3(model * vec4(aPos, 1.f));               \n"
                          "    Normal = mat3(model) * aNormal;                        \n"
                          "    gl_Position = projection * view * model * vec4(aPos, 1.f); \n"
                          "}";
    std::string modelFs = "#version 330 core\n"
    "out vec4 FragColor;                                                      \n"
    "struct DirLight{                                                         \n"
    "    vec3 direction;                                                      \n"
    "    vec3 ambient;                                                        \n"
    "    vec3 diffuse;                                                        \n"
    "    vec3 specular;                                                       \n"
    "};                                                                       \n"
    "in vec3 FragPos;                                                         \n"
    "in vec3 Normal;                                                          \n"
    "in vec2 TexCoords;                                                       \n"
    "uniform sampler2D texture_diffuse1;                                      \n"
    "uniform sampler2D texture_specular1;                                     \n"
    "uniform sampler2D texture_normal1;                                       \n"
    "uniform vec3 viewPos;                                                    \n"
    "uniform float shininess;                                                 \n"
    "uniform DirLight dirLight;                                               \n"
    "void main(){                                                             \n"
    "    //vec3 norm = normalize(Normal);                                       \n"
    "    vec3 norm = normalize(vec3(texture(texture_normal1, TexCoords)));          \n"
    "    vec3 viewDir = normalize(viewPos - FragPos);                         \n"
    "                                                                         \n"
    "    vec3 lightDir = normalize(-dirLight.direction);                      \n"
    "    float diff = max(dot(norm, lightDir), 0.f);                          \n"
    "                                                                         \n"
    "    vec3 reflectDir = reflect(-lightDir, norm);                          \n"
    "    float spec = pow(max(dot(viewDir, reflectDir), 0.f), shininess);     \n"
    "                                                                         \n"
    "    vec3 colorDiffuse = vec3(texture(texture_diffuse1, TexCoords));   \n"
    "    vec3 colorSpecular = vec3(texture(texture_specular1, TexCoords)); \n"
    "    //vec3 colorDiffuse = vec3(1.f, 0.f, 0.f);                             \n"
    "    //vec3 colorSpecular = vec3(1.f, 0.f, 0.f);                            \n"
    "                                                                         \n"
    "                                                                         \n"
    "    vec3 ambient = dirLight.ambient * colorDiffuse;                      \n"
    "    vec3 diffuse = dirLight.diffuse * colorDiffuse;                      \n"
    "    vec3 specular = dirLight.specular * spec * colorSpecular;            \n"
    "                                                                         \n"
    "    FragColor = vec4(ambient+diffuse+specular, 1.f);              \n"
    "    // FragColor = vec4(norm, 1.f);                                         \n"
    "    // FragColor = vec4(ambient, 1.f);                                   \n"
    "    // FragColor = vec4(diffuse, 1.f);                                   \n"
    "    // FragColor = vec4(specular, 1.f);                                  \n"
    "}";

    m_shader = new Shader(modelVs, modelFs);

    if(!m_modelPath.empty() && m_model){
        m_model = new Model(m_modelPath);
    }

    mObjectMutex.lock();
    mType = OBJECTTYPE::INITED;
    mObjectMutex.unlock();
}

void ObservedObject::Draw(){

    glEnable(GL_DEPTH_TEST);
    m_shader->Use();
    m_shader->SetMat4("model", m_modelMatrix);
    m_shader->SetMat4("view", m_viewMatrix);
    m_shader->SetMat4("projection", m_projectMatrix);
    m_shader->SetVec3("dirLight.direction", m_direction);
    m_shader->SetVec3("dirLight.ambient", m_ambient);
    m_shader->SetVec3("dirLight.diffuse", m_diffuse);
    m_shader->SetVec3("dirLight.specular", m_specular);
    m_shader->SetFloat("shininess", m_shininess);
    //std::cout << "meshSize: " << m_model->meshes.size() << std::endl;
    for (unsigned int i = 0; i < m_model->meshes.size(); ++i) {
        m_model->meshes[i].Draw(*m_shader);
    }
    m_shader->UnUse();

    glDisable(GL_DEPTH_TEST);
}

void ObservedObject::Unit(){
    if(m_shader) delete m_shader;
    if(m_model) delete m_model;
    mObjectMutex.lock();
    mType = OBJECTTYPE::UNITED;
    mObjectMutex.unlock();
}