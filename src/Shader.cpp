#include "Shader.h"

Shader::Shader(const char* vertexPath, const char* fragmentPath) : programID(0){

	std::string vertexCode;
	std::string fragmentCode;

	std::ifstream vShaderFile;
	std::ifstream fShaderFile;

	vShaderFile.open(vertexPath);
	fShaderFile.open(fragmentPath);

	std::stringstream vShaderStream, fShaderStream;

	vShaderStream << vShaderFile.rdbuf();
	fShaderStream << fShaderFile.rdbuf();

	vShaderFile.close();
	fShaderFile.close();

	vertexCode = vShaderStream.str();
	fragmentCode = fShaderStream.str();

	const char* vShaderCode = vertexCode.c_str();
	const char* fShaderCode = fragmentCode.c_str();

	GLuint vertex, fragment;
	vertex = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(vertex, 1, &vShaderCode, NULL);
	glCompileShader(vertex);
	checkCompileErrors(vertex, "VERTEX");

	fragment = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(fragment, 1, &fShaderCode, NULL);
	glCompileShader(fragment);
	checkCompileErrors(fragment, "FRAGMENT");

	programID = glCreateProgram();
	glAttachShader(programID, vertex);
	glAttachShader(programID, fragment);

	glLinkProgram(programID);
	checkCompileErrors(programID, "PROGRAM");

	glDeleteShader(vertex);
	glDeleteShader(fragment);
}

Shader::Shader(std::string vertexShaderStr, std::string fragmentShaderStr) : programID(0){

	const char* vShaderCode = vertexShaderStr.c_str();
	const char* fShaderCode = fragmentShaderStr.c_str();

	GLuint vertex, fragment;
	vertex = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(vertex, 1, &vShaderCode, NULL);
	glCompileShader(vertex);
	errCode = checkCompileErrors(vertex, "VERTEX");
	if (errCode) {
		return;
	}

	fragment = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(fragment, 1, &fShaderCode, NULL);
	glCompileShader(fragment);
	errCode = checkCompileErrors(fragment, "FRAGMENT");
	if (errCode) {
		return;
	}
	programID = glCreateProgram();
	glAttachShader(programID, vertex);
	glAttachShader(programID, fragment);

	glLinkProgram(programID);
	errCode = checkCompileErrors(programID, "PROGRAM");
	if (errCode) {
		return;
	}

	glDeleteShader(vertex);
	glDeleteShader(fragment);
}

Shader::~Shader(){
	glDeleteProgram(programID);
}

void Shader::Use(){
	glUseProgram(programID);
}

void Shader::UnUse(){
	glUseProgram(0);
}

void Shader::SetBool(const std::string& name, bool value) const{
	glUniform1i(glGetUniformLocation(programID, name.c_str()), (int)value);
}

void Shader::SetInt(const std::string& name, int value) const{
	glUniform1i(glGetUniformLocation(programID, name.c_str()), value);
}

void Shader::SetFloat(const std::string& name, float value) const{
	glUniform1f(glGetUniformLocation(programID, name.c_str()), value);
}

void Shader::SetVec2(const std::string& name, float* value){
	glUniform2fv(glGetUniformLocation(programID, name.c_str()), 1, value);
}

void Shader::SetVec2(const std::string& name, float x, float y){
	glUniform2f(glGetUniformLocation(programID, name.c_str()), x, y);
}

void Shader::SetVec3(const std::string& name, float* value){
	glUniform3fv(glGetUniformLocation(programID, name.c_str()), 1, value);
}

void Shader::SetVec3(const std::string& name, float x, float y, float z){
	glUniform3f(glGetUniformLocation(programID, name.c_str()), x, y, z);
}

void Shader::SetVec4(const std::string& name, float* value){
	glUniform4fv(glGetUniformLocation(programID, name.c_str()), 1, value);
}

void Shader::SetVec4(const std::string& name, float x, float y, float z, float w){
	glUniform4f(glGetUniformLocation(programID, name.c_str()), x, y, z, w);
}

void Shader::SetMat2(const std::string& name, float* mat2x2){
	glUniformMatrix2fv(glGetUniformLocation(programID, name.c_str()), 1, GL_FALSE, mat2x2);
}

void Shader::SetMat3(const std::string& name, float* mat3x3){
	glUniformMatrix3fv(glGetUniformLocation(programID, name.c_str()), 1, GL_FALSE, mat3x3);
}

void Shader::SetMat4(const std::string& name, float* mat4x4){
	glUniformMatrix4fv(glGetUniformLocation(programID, name.c_str()), 1, GL_FALSE, mat4x4);
}

int Shader::checkCompileErrors(GLuint shader, std::string type){
	GLint success;
	GLchar infoLog[1024];

	if (type != "PROGRAM") {
		glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
		if (!success) {
			glGetShaderInfoLog(shader, 1024, NULL, infoLog);
			std::cout << "Error::SHADER_COMPILATION_ERROR of type: " << type << "\n" << infoLog << std::endl;
			return -1;
		}
	}
	else {
		glGetProgramiv(shader, GL_LINK_STATUS, &success);
		if (!success) {
			glGetProgramInfoLog(shader, 1024, NULL, infoLog);
			std::cout << "Error::PROGRAM_LINKING_ERROR of type: " << type << "\n" << infoLog << std::endl;
			return -2;
		}
	}
	return 0;
}
