#ifndef _COMMON_H_
#define _COMMON_H_

#include <iostream>
#include <vector>
#include <memory>
#include <cstring>
#include "Vectors.h"
#include "Matrices.h"

using namespace Darker;

#define RAD2ANG 57.29577951308232  // (180. / 3.14159265358979323846)
#define ANG2RAD 0.017453292519943295 //(3.14159265358979323846 / 180.)

class CameraInner{
public:
    typedef std::shared_ptr<CameraInner> ptr;

    CameraInner() = delete;    

    CameraInner(float near, float far, float cx, float cy, float fx, float fy, int width, int height){
        m_near = near;
        m_far = far;
        m_cx = cx;
        m_cy = cy;
        m_fx = fx;
        m_fy = fy;
        m_fov = (float)(atan2(cy, fy) * RAD2ANG * 2.);
        m_width = (float)width;
        m_height = (float)height;
		computeProjectMatrix();
    }

    CameraInner(float near, float far, float cx, float cy, float fov, int width, int height){
        m_near = near;
        m_far = far;
        m_cx = cx;
        m_cy = cy;
        m_fov = fov;
        m_width = width;
        m_height = height;
        m_fx = m_height * 0.5f / tanf(m_fov * 0.5f * ANG2RAD);
        m_fy = m_cx;
		computeProjectMatrix();
    }

    void SetSize(int width, int height){

        m_width = width;
        m_height = height;
        m_fx = m_height * 0.5f / tanf(m_fov * 0.5f * ANG2RAD);
        m_fy = m_cx;
		computeProjectMatrix();
	}

    void SetCameraInner(float near, float far, float fov){
		m_near = near;
		m_far = far;
		m_fov = fov;
		m_cx = m_width * 0.5f;
		m_cy = m_height * 0.5f;
		m_fx = m_height * 0.5f / tanf(m_fov * 0.5f * ANG2RAD);
        m_fy = m_cx;
		computeProjectMatrix();
	}

    void SetCameraInnerFov(float fov){
		m_fov = fov;
		m_fx = m_height * 0.5f / tanf(m_fov * 0.5f * ANG2RAD);
        m_fy = m_cx;
		computeProjectMatrix();
	}

    void SetCameraInnerNear(float near){
		m_near = near;
		computeProjectMatrix();
	}

    void SetCameraInnerFar(float far){
		m_far = far;
		computeProjectMatrix();
	}
	
    float m_near;
    float m_far;
    float m_cx, m_cy;
    float m_fx, m_fy;
    float m_fov;
    float m_width, m_height;
    float m_projectMatrix[16];
private:
    void computeProjectMatrix(){
        float tanHalfFovy = tanf(m_fov / 2.f * DEG2RAD);
        memset(m_projectMatrix, 0, sizeof(float) * 16);
        m_projectMatrix[0] = 1.f / (m_width * 1.f / m_height * tanHalfFovy);
        m_projectMatrix[5] = 1.f / tanHalfFovy;
        m_projectMatrix[10] = -(m_far + m_near) / (m_far - m_near);
        m_projectMatrix[11] = -1.f;
        m_projectMatrix[14] = -(2 * m_far * m_near) / (m_far - m_near);
    }
};

namespace DarkerOGL {

	class Line2D {
	public:
		typedef std::shared_ptr<Line2D> ptr;
		Line2D(const Vector2<float>& s, const Vector2<float>& e,
			const Vector4<float>& c = Vector4<float>(1.f, 1.f, 1.f, 1.f),
			float si = 1.f) {
			start = s;
			end = e;
			color = c;
			size = si;
		}
		Line2D(const Line2D& line) {
			start = line.start;
			end = line.end;
			color = line.color;
			size = line.size;
		}
		Line2D() {
			start = Vector2<float>();
			end = Vector2<float>();
			color = Vector4<float>();
			size = 1.f;
		}
		Vector2<float> start; 
		Vector2<float> end; 
		Vector4<float> color;
		float size;
	};

	class Line3D {
	public:
		typedef std::shared_ptr<Line3D> ptr;
		Line3D(const Vector3<float>& s, const Vector3<float>& e,
			const Vector4<float>& c = Vector4<float>(1.f, 1.f, 1.f, 1.f),
			float si = 1.f) {
			start = s;
			end = e;
			color = c;
			size = si;
		}

		Line3D(const Line3D& line) {
			start = line.start;
			end = line.end;
			color = line.color;
			size = line.size;
		}

		Line3D() {
			start = Vector3<float>();
			end = Vector3<float>();
			color = Vector4<float>();
			size = 1.f;
		}
		
		Vector3<float> start;
		Vector3<float> end; 
		Vector4<float> color; 
		float size;
	};

	class Point2D {
	public:
		typedef std::shared_ptr<Point2D> ptr;

		Point2D(const Vector2<float>& p,
			const Vector4<float>& c = Vector4<float>(1.f, 1.f, 1.f, 1.f),
			float si = 1.f) {
			point = p;
			color = c;
			size = si;
		}
		Point2D(const Point2D& p2d) {
			point = p2d.point;
			color = p2d.color;
			size = p2d.size;
		}
		Point2D() {
			point = Vector2<float>();
			color = Vector4<float>();
			size = 1.f;
		}

		Vector2<float> point;
		Vector4<float> color;
		float size;
	};

	class Point3D {
	public:
		typedef std::shared_ptr<Point3D> ptr;

		Point3D(const Vector3<float>& p,
			const Vector4<float>& c = Vector4<float>(1.f, 1.f, 1.f, 1.f),
			float si = 1.f) {
			point = p;
			color = c;
			size = si;
		}
		Point3D(const Point3D& p3d) {
			point = p3d.point;
			color = p3d.color;
			size = p3d.size;
		}
		Point3D() {
			point = Vector3<float>();
			color = Vector4<float>();
			size = 1.f;
		}

		Vector3<float> point;
		Vector4<float> color;
		float size;
	};
}

namespace DarkerOGL {

std::string FloatToString(float value);

}

#endif
