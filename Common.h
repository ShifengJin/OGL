#ifndef _COMMON_H_
#define _COMMON_H_

#include <iostream>
#include <vector>
#include <memory>

namespace DarkerOGL {

	template<typename T>
	class Vector3;

	template<typename T>
	class Vector4;

	template<typename T>
	class Vector2 {
	public:
		Vector2(T x, T y){
			data[0] = x; data[1] = y;		
		}
		Vector2() {
			data[0] = 0; data[1] = 0;		
		}
		Vector2(const Vector2<T>& v2) {
			data[0] = v2.data[0];
			data[1] = v2.data[1];
		}
		Vector2<T> operator-(Vector2<T>& v2) {
			Vector2<T> ans;
			ans.data[0] = data[0] - v2.data[0];
			ans.data[1] = data[1] - v2.data[1];
			return ans;
		}

		T X() { return data[0]; }
		T Y() { return data[1]; }
		void X(T x) { data[0] = x; }
		void Y(T y) { data[1] = y; }

		T Length() {
			return (T)(sqrt(data[0] * data[0] + data[1] * data[1]));
		}

	public:
		T data[2];
	};

	template<typename T>
	class Vector3 {
	public:
		Vector3(T x, T y, T z) {
			data[0] = x; data[1] = y; data[2] = z;
		}
		Vector3(){
			data[0] = 0; data[1] = 0; data[2] = 0;		
		}
		Vector3(const Vector3<T>& v3) {
			data[0] = v3.data[0];
			data[1] = v3.data[1];
			data[2] = v3.data[2];
		}

		T X() { return data[0]; }
		T Y() { return data[1]; }
		T Z() { return data[2]; }
		void X(T x) { data[0] = x; }
		void Y(T y) { data[1] = y; }
		void Z(T z) { data[2] = z; }

		Vector3<T> operator-(Vector3<T>& v3) {
			Vector3<T> ans;
			ans.data[0] = data[0] - v3.data[0];
			ans.data[1] = data[1] - v3.data[1];
			ans.data[2] = data[2] - v3.data[2];
			return ans;
		}
		Vector3<T> operator+(const Vector3<T>& v3) {
			Vector3<T> ans;
			ans.data[0] = data[0] + v3.data[0];
			ans.data[1] = data[1] + v3.data[1];
			ans.data[2] = data[2] + v3.data[2];
			return ans;
		}
		
		Vector3<T> operator*(T scale) {
			Vector3<T> ans;
			ans.data[0] = data[0] * scale;
			ans.data[1] = data[1] * scale;
			ans.data[2] = data[2] * scale;
			return ans;
		}

		Vector4<T> ToVector4(Vector3<T>& v3) {
			Vector4<T> ans(v3.X(), v3.Y(), v3.Z(), (T)1);
			return ans;
		}

		Vector3<T> mul_MainRow(T* matrix4x4) {
			Vector3<T> ans;
			T x = data[0] * matrix4x4[0] + data[1] * matrix4x4[1] + data[2] * matrix4x4[2] + matrix4x4[3];
			T y = data[0] * matrix4x4[4] + data[1] * matrix4x4[5] + data[2] * matrix4x4[6] + matrix4x4[7];
			T z = data[0] * matrix4x4[8] + data[1] * matrix4x4[9] + data[2] * matrix4x4[10] + matrix4x4[11];
			T w = data[0] * matrix4x4[12] + data[1] * matrix4x4[13] + data[2] * matrix4x4[14] + matrix4x4[15];
			ans.X(x / w);
			ans.Y(y / w);
			ans.Z(z / w);
			return ans;
		}
		T Length() {
			return (T)(sqrt(data[0] * data[0] + data[1] * data[1] + data[2] *data[2]));
		}

		void Normalize() {
			T len = this->Length();
			data[0] /= len;
			data[1] /= len;
			data[2] /= len;
		}

	public:
		T data[3];
	};

	template<typename T>
	class Vector4 {
	public:
		Vector4(T x, T y, T z, T w) {
			data[0] = x; data[1] = y; data[2] = z; data[3] = w;
		}
		Vector4(){
			data[0] = 0; data[1] = 0; data[2] = 0; data[3] = 0;
		}
		Vector4(const Vector4<T>& v4) {
			data[0] = v4.data[0];
			data[1] = v4.data[1];
			data[2] = v4.data[2];
			data[3] = v4.data[3];
		}

		T X() { return data[0]; }
		T Y() { return data[1]; }
		T Z() { return data[2]; }
		T W() { return data[3]; }
		T X(T x) { data[0] = x; }
		T Y(T y) { data[0] = y; }
		T Z(T z) { data[0] = z; }
		T W(T w) { data[0] = w; }

		Vector3<T> ToVector3(Vector4<T>& v4) {
			Vector3<T> ans;
			if (abs(v4.Z() < 1e-9)) {
				return ans;
			}
			ans.X(v4.X() / v4.W());
			ans.Y(v4.Y() / v4.W());
			ans.Y(v4.Z() / v4.W());
			return ans;
		}

	public:
		T data[4];		
	};

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

#endif