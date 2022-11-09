#ifndef _ALVASYSTEMS_CAD360_SHADER_H_
#define _ALVASYSTEMS_CAD360_SHADER_H_

#include <string>
#include <fstream>
#include <iostream>
#include <sstream>

#include "glew.h"

class Shader {

public:
	Shader(const char* vertexPath, const char* fragmentPath);

	Shader(std::string vertexShaderStr, std::string fragmentShaderStr);

	~Shader();

	void Use();
	void UnUse();

	void SetBool(const std::string& name, bool value) const;

	void SetInt(const std::string& name, int value) const;

	void SetFloat(const std::string& name, float value) const;

	void SetVec2(const std::string& name, float* value);
	void SetVec2(const std::string& name, float x, float y);

	void SetVec3(const std::string& name, float* value);
	void SetVec3(const std::string& name, float x, float y, float z);

	void SetVec4(const std::string& name, float* value);
	void SetVec4(const std::string& name, float x, float y, float z, float w);

	void SetMat2(const std::string& name, float* mat2x2);

	void SetMat3(const std::string& name, float* mat3x3);

	void SetMat4(const std::string& name, float* mat4x4);

	int isInit() {
		return errCode;
	}
	GLuint programID;
private:
	int checkCompileErrors(GLuint shader, std::string type);
	int errCode = 0;
};

#endif