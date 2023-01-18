#ifndef _COMMON_H_
#define _COMMON_H_

#include <iostream>
#include <vector>
#include <memory>
#include "Vectors.h"
#include "Matrices.h"

using namespace Darker;

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
