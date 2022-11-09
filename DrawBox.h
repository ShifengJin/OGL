#ifndef _DRAWBOX_H_
#define _DRAWBOX_H_

#include <iostream>
#include <vector>
#include <string.h>
#include "Common.h"
#include "DrawLines.h"

namespace DarkerOGL {

class DrawBox {
public:
	typedef std::shared_ptr<DrawBox> ptr;

	DrawBox();
	~DrawBox();

	void SetBoxInfo(DarkerOGL::Vector3<float> center, float scale,
		DarkerOGL::Vector4<float> edgeColor = DarkerOGL::Vector4<float>(0.f, 0.f, 1.f, 1.f),
		DarkerOGL::Vector4<float> faceColor = DarkerOGL::Vector4<float>(0.f, 1.f, 0.f, 0.3f));

	void SetModelMatrix(float* modelMatrix) {
		memcpy(m_modelMatrix, modelMatrix, 16 * sizeof(float));
	}
	void SetViewMatrix(float* viewMatrix) {
		memcpy(m_viewMatrix, viewMatrix, 16 * sizeof(float));
	}
	void SetProjectMatrix(float* projectMatrix) {
		memcpy(m_projectMatrix, projectMatrix, 16 * sizeof(float));
	}

	void Draw();

private:
	float m_scale;
	DarkerOGL::Vector3<float> m_center;
	DarkerOGL::Vector4<float> m_edgeColor;
	DarkerOGL::Vector4<float> m_faceColor;
	Draw3DLines::ptr m_pDrawLines;

	DarkerOGL::Vector3<float> m_srcBox[8];
	DarkerOGL::Vector3<float> m_dstBox[8];
	DarkerOGL::Line3D m_edges[12];

	DarkerOGL::Vector3<float> m_triangle[12 * 3];
	float m_buffer[12 * 21];

	float m_modelMatrix[16];
	float m_viewMatrix[16];
	float m_projectMatrix[16];

	// opengl parameter
	Shader* m_pShader;

	GLuint VAO;
	GLuint VBO;

	Draw3DLines::ptr m_Draw3DLines;

};

class DrawBoxes {
public:
	typedef std::shared_ptr<DrawBoxes> ptr;

	DrawBoxes();
	~DrawBoxes();
	
private:

	float m_modelMatrix[16];
	float m_viewMatrix[16];
	float m_projectMatrix[16];

	// opengl parameter
	Shader* m_pShader;

	GLuint VAO;
	GLuint VBO;

};

}

#endif