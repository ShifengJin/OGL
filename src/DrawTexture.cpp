#include <iostream>
#include <string.h>
#include "DrawTexture.h"

DrawTexture::DrawTexture(int imgWidth, int imgHeight) : imgWidth(imgWidth), imgHeight(imgHeight), rgb(NULL), texture(0)
{
	std::string vShaderCode = 
		"#version 330 core                                               \n"
		"layout(location = 0) in vec3 aVertexPosition;                   \n"
		"layout(location = 1) in vec2 aTexCoord;                         \n"
		"out vec2 TexCoord;                                              \n"
		"void main(){                                                    \n"
		"    gl_Position = vec4(aVertexPosition, 1.f);                   \n"
		"    TexCoord = aTexCoord;                                       \n"
		"}";
	std::string fShaderCode = 
		"#version 330 core                                               \n"
		"out vec4 FragColor;                                             \n"
		"in vec2 TexCoord;                                               \n"
		"uniform sampler2D texture1;                                     \n"
		"void main() {                                                   \n"
		"    FragColor = vec4(texture(texture1, TexCoord).rgb, 1.f);     \n"
		"}";

	pShader = new Shader(vShaderCode, fShaderCode);

	rgb = (unsigned char*)calloc(imgWidth* imgHeight * 3, 1);

	float vertices[] = {
		-1.f, -1.f, 0.f,  0.f, 1.f,
		-1.f,  1.f, 0.f,  0.f, 0.f,
		 1.f, -1.f, 0.f,  1.f, 1.f,
		 1.f,  1.f, 0.f,  1.f, 0.f
	};

	glGenVertexArrays(1, &vertexArray);
	glGenBuffers(1, &vertexBuffer);

	glBindVertexArray(vertexArray);
	glBindBuffer(GL_ARRAY_BUFFER, vertexBuffer);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

	//GLint vtloc = glGetAttribLocation(pShader->programID, "aVertexPosition");
	//GLint txloc = glGetAttribLocation(pShader->programID, "aTexCoord");

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)(3 * sizeof(float)));
	glEnableVertexAttribArray(1);

	glGenTextures(1, &texture);
	glBindTexture(GL_TEXTURE_2D, texture);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, imgWidth, imgHeight, 0, GL_RGB, GL_UNSIGNED_BYTE, NULL);
	//glGenerateMipmap(GL_TEXTURE_2D);
}

DrawTexture::~DrawTexture()
{
	delete pShader;
	glDeleteTextures(1, &texture);
	glDeleteVertexArrays(1, &vertexArray);
	glDeleteBuffers(1, &vertexBuffer);
	if (rgb) {
		free(rgb);
		rgb = NULL;
	}
}

void DrawTexture::SetRGBData(unsigned char* data)
{
	memcpy(rgb, data, imgWidth * imgHeight * 3);
}

void DrawTexture::Draw()
{
	glUseProgram(0);
	glDisable(GL_DEPTH_TEST);
	pShader->Use();

	pShader->SetInt("texture1", 0);
	glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_2D, texture);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, imgWidth, imgHeight, 0, GL_RGB, GL_UNSIGNED_BYTE, rgb);

	glBindVertexArray(vertexArray);
	glBindBuffer(GL_ARRAY_BUFFER, vertexBuffer);

	//GLint vtloc = glGetAttribLocation(pShader->programID, "aVertexPosition");
	//GLint txloc = glGetAttribLocation(pShader->programID, "aTexCoord");

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)(3 * sizeof(float)));
	glEnableVertexAttribArray(1);

	glDrawArrays(GL_TRIANGLE_STRIP, 0, 4);

	glBindVertexArray(0);
	glBindTexture(GL_TEXTURE_2D, 0);
	glActiveTexture(0);

	pShader->UnUse();

	glEnable(GL_DEPTH_TEST);

}
