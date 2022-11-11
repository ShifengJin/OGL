#ifndef _DRAWTEXTURE_H_
#define _DRAWTEXTURE_H_

#include <memory>
#include "glew.h"
#include "Shader.h"

class DrawTexture {
public:
	typedef std::shared_ptr<DrawTexture> ptr;
	DrawTexture(int imgWidth, int imgHeight);
	~DrawTexture();

	void SetRGBData(unsigned char* data);
	void Draw();

private:
	Shader* pShader;

	GLuint vertexArray;
	GLuint vertexBuffer;
	GLuint texture;
	unsigned char* rgb;
	int imgWidth;
	int imgHeight;
};
#endif