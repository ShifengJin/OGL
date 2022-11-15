#ifndef _VECTORS_H_
#define _VECTORS_H_

#include <iostream>

namespace Darker{

    template<typename T>
    class Vector2;

    template<typename T>
    inline std::ostream& operator<<(std::ostream& os, const Vector2<T>& vec) {
        os << "[" << vec.X() << ", " << vec.Y() << "]";
    }

    template<typename T>
	class Vector2 {
	public:
		Vector2(T x, T y) {
			data[0] = x; data[1] = y;		
		}

		Vector2() {
			data[0] = 0; data[1] = 0;		
		}

		Vector2(const Vector2<T>& v2) {
			data[0] = v2.data[0];
			data[1] = v2.data[1];
		}

        T Length() const {
			return (T)(sqrt(data[0] * data[0] + data[1] * data[1]));
		}

        T Distance(const Vector2<T>& vec) const { 
            T dx = vec.data[0] - data[0];
            T dy = vec.data[1] - data[1];
            return (T)(sqrt(dx * dx + dy * dy));
        }

        Vector2<T>& Normalize() {
            T xxyy = data[0] * data[0] + data[1] * data[1];
            T invLength = (T)(1. / (T)sqrt(xxyy));
            data[0] *= invLength;
            data[1] *= invLength;
        }

        T Dot(const Vector2<T>& vec) const {
            return (T)(data[0] * vec.data[0] + data[1] * vec.data[1]);
        }

        bool Equal(const Vector2<T>& vec, T e) const {
            return fabs(data[0] - vec.data[0]) < e && fabs(data[1] - vec.data[1]) < e;
        }

        Vector2<T> operator-() const {
            return Vector2<T>(-data[0], -data[1]);
        }

        Vector2<T> operator+(const Vector2<T>& rhs) const {
            return Vector2<T>(data[0] + rhs.data[0], data[1] + rhs.data[1]);
        }

        Vector2<T> operator-(const Vector2<T>& rhs) const {
            return Vector2<T>(data[0] - rhs.data[0], data[1] - rhs.data[1]);
        }

        Vector2<T>& operator+=(const Vector2<T>& rhs) {
            data[0] += rhs.data[0];
            data[1] += rhs.data[1];
            return *this;
        }

        Vector2<T>& operator-=(const Vector2<T>& rhs){
            data[0] -= rhs.data[0];
            data[1] -= rhs.data[1];
            return *this;
        }

        Vector2<T> operator*(const T scale) const {
            return Vector2<T>(data[0] * scale, data[1] * scale);            
        }

        Vector2<T> operator*(const Vector2<T>& rhs) const {
            return Vector2<T>(data[0] * rhs.data[0], data[1] * rhs.data[1]);
        }

        Vector2<T>& operator*=(const T scale) {
            data[0] *= scale;
            data[1] *= scale;
            return *this;
        }

        Vector2<T>& operator*=(const Vector2<T>& rhs) {
            data[0] *= rhs.data[0];
            data[1] *= rhs.data[1];
            return *this;
        }

        Vector2<T> operator/(const T scale) const {
            return Vector<T>(data[0] / scale, data[1] / scale);
        }

        Vector2<T>& operator/=(const T scale) {
            data[0] /= scale;
            data[1] /= scale;
            return *this;
        }

        bool operator==(const Vector2<T>& rhs) const {
            return (data[0] == rhs.data[0]) && (data[1] == rhs.data[1]);
        }

        bool operator!=(const Vector2<T>& rhs) const {
            return (data[0] != rhs.data[0]) || (data[1] != rhs.data[1]);
        }

		T X() { return data[0]; }
		T Y() { return data[1]; }
		void X(T x) { data[0] = x; }
		void Y(T y) { data[1] = y; }

        friend std::ostream& operator<<(std::ostream& os, const Vector2<T>& vec);

	public:
		T data[2];
	};

    template<typename T>
    class Vector3;

    template<typename T>
    std::ostream& operator<<(std::ostream& os, const Vector3<T>& vec){
        os << "[" << vec.X() << ", " << vec.Y() << ", " << vec.Z() << "]";
    }

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

        T Length() {
			return (T)(sqrt(data[0] * data[0] + data[1] * data[1] + data[2] *data[2]));
		}

        T Distance(const Vector3<T>& vec) const {
            T dx = data[0] - vec.data[0];
            T dy = data[1] - vec.data[1];
            T dz = data[2] - vec.data[2];
            return (T)(sqrt(dx * dx + dy * dy + dz * dz));
        }

        float Angle(const Vector3<T>& vec) const {
            T l1 = this->Length();
            T l2 = vec.Length();
            T d = this->Dot(vec);
            float angle = acosf(d / (l1 * l2)) / 3.1415926f * 180.f;
            return angle;
        }

        Vector3<T>& Normalize() {
            T xxyyzz = data[0] * data[0] + data[1] * data[1] + data[2] * data[2];
            T invLength = 1.f / sqrtf(xxyyzz);
            data[0] *= invLength;
            data[1] *= invLength;
            data[2] *= invLength;
            return *this;
        }

        T Dot(const Vector3<T>& rhs) const {
            return (data[0] * rhs.data[0] + data[1] * rhs.data[1] + data[2] * rhs.data[2]);
        }

        Vector3<T> Cross(const Vector3<T>& rhs) const {
            return Vector3<T>(data[1] * rhs.data[2] - data[2] * rhs.data[1], 
                              data[2] * rhs.data[0] - data[0] * rhs.data[2], 
                              data[0] * rhs.data[1] - data[1] * rhs.data[0]);
        }

        bool Equal(const Vector3<T>& rhs, float epsilon) const {
            return fabs(data[0] - rhs.data[0]) < epsilon &&
                   fabs(data[1] - rhs.data[1]) < epsilon && 
                   fabs(data[2] - rhs.data[2]) < epsilon;
        }

        Vector3<T> operator-() const {
            return Vector3<T>(-data[0], -data[1], -data[2]);
        }

        Vector3<T> operator+(const Vector3<T>& rhs) const {
            return Vector3<T>(data[0] + rhs.data[0], data[1] + rhs.data[1], data[2] + rhs.data[2]);
        }

        Vector3<T> operator-(const Vector3<T>& rhs) const {
            return Vector3<T>(data[0] - rhs.data[0], data[1] - rhs.data[1], data[2] - rhs.data[2]);
        }

        Vector3<T>& operator+=(const Vector3<T>& rhs) {
            data[0] += rhs.data[0];
            data[1] += rhs.data[1];
            data[2] += rhs.data[2];
            return *this;
        }

        Vector3<T>& operator-=(const Vector3<T>& rhs) {
            data[0] -= rhs.data[0];
            data[1] -= rhs.data[1];
            data[2] -= rhs.data[2];
            return *this;
        }

        Vector3<T> operator*(const T scale) const {
            return Vector3<T>(data[0] * scale, data[1] * scale, data[2] * scale);
        }

        Vector3<T> operator*(const Vector3<T>& rhs) const {
            return Vector3<T>(data[0] * rhs.data[0], data[1] * rhs.data[1], data[2] * rhs.data[2]);
        }

        Vector3<T>& operator*=(const T scale) {
            data[0] *= scale;
            data[1] *= scale;
            data[2] *= scale;
            return *this;
        }

        Vector3<T>& operator*=(const Vector3<T>& rhs) {
            data[0] *= rhs.data[0];
            data[1] *= rhs.data[1];
            data[2] *= rhs.data[2];
            return *this;
        }

        Vector3<T> operator/(const T scale) const {
            return Vector3<T>(data[0] / scale, data[1] / scale, data[2] / scale);
        }

        Vector3<T>& operator/=(const T scale){
            data[0] /= scale;
            data[1] /= scale;
            data[2] /= scale;
            return *this;
        }

        bool operator==(const Vector3<T>& rhs) const {
            return (data[0] == rhs.data[0]) && (data[1] == rhs.data[1]) && (data[2] == rhs.data[2]);
        }

        bool operator!=(const Vector3<T>& rhs) const {
            return (data[0] != rhs.data[0]) || (data[1] != rhs.data[1]) || (data[2] != rhs.data[2]);
        }
        
		T X() { return data[0]; }
		T Y() { return data[1]; }
		T Z() { return data[2]; }
		void X(T x) { data[0] = x; }
		void Y(T y) { data[1] = y; }
		void Z(T z) { data[2] = z; }

	public:
		T data[3];
	};


    template<typename T>
    class Vector4;

    template<typename T>
    std::ostream& operator<<(std::ostream& os, const Vector4<T>& vec){
        os << "[" << vec.X() << ", " << vec.Y() << ", " << vec.Z() << ", " << vec.W() << "]";
    }

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

        T Length() const {
            return (T)(sqrt(data[0] * data[0] + data[1] * data[1] + data[2] * data[2] + data[3] * data[3]));
        }

        T Distance(const Vector4<T>& vec) const {
            T dx = data[0] - vec.data[0];
            T dy = data[1] - vec.data[1];
            T dz = data[2] - vec.data[2];
            T dw = data[3] - vec.data[3];
            return (T)(sqrt(dx * dx + dy * dy + dz * dz + dw * dw));
        }

        Vector4<T>& Normalize() {
            //NOTE: leave w-component untouched
            T xxyyzz = data[0] * data[0] + data[1] * data[1] + data[2] * data[2];
            T invLength = (T)(1. / sqrt(xxyyzz));
            data[0] *= invLength;
            data[1] *= invLength;
            data[2] *= invLength;
            return *this;
        }

        T Vector4<T> Dot(const Vector4<T>& rhs) const {
            return (data[0] * rhs.data[0] + data[1] * rhs.data[1] + data[2] * rhs.data[2] + data[3] * rhs.data[3]);
        }

        bool Equal(const Vector4<T>& rhs, T epsilon) const {
            return (fabs(data[0] - rhs.data[0]) < epsilon) && (fabs(data[1] - rhs.data[1]) < epsilon) &&
                   (fabs(data[2] - rhs.data[2]) < epsilon) && (fabs(data[3] - rhs.data[3]) < epsilon);
        }
        
        Vector4<T> operator-() const {
            return Vector4<T>(-data[0], -data[1], -data[2], -data[3]);
        }

        Vector4<T> operator+(const Vector4<T>& rhs) const {
            return Vector4<T>(data[0] + rhs.data[0], data[1] + rhs.data[1], data[2] + rhs.data[2], data[3] + rhs.data[3]);
        }

        Vector4<T> operator-(const Vector4<T>& rhs) const {
            return Vector4<T>(data[0] - rhs.data[0], data[1] - rhs.data[1], data[2] - rhs.data[2], data[3] - rhs.data[3]);
        }

        Vector4<T>& operator+=(const Vector4<T>& rhs) {
            data[0] += rhs.data[0];
            data[1] += rhs.data[1];
            data[2] += rhs.data[2];
            data[3] += rhs.data[3];
            return *this;
        }

        Vector4<T>& operator-=(const Vector4<T>& rhs){
            data[0] -= rhs.data[0];
            data[1] -= rhs.data[1];
            data[2] -= rhs.data[2];
            data[3] -= rhs.data[3];
            return *this;
        }

        Vector4<T> operator*(const T scale) const {
            return Vector4<T>(scale * data[0], scale * data[1], scale * data[2], scale * data[3]);
        }

        Vector4<T> operator*(const Vector4<T>& rhs) const {
            return Vector4<T>(data[0] * rhs.data[0], data[1] * rhs.data[1], data[2] * rhs.data[2], data[3] * rhs.data[3]);
        }

        Vector4<T>& operator*=(const T scale) {
            data[0] *= scale;
            data[1] *= scale;
            data[2] *= scale;
            data[3] *= scale;
            return *this;
        }

        Vector4<T>& operator*=(const Vector4<T>& rhs) {
            data[0] *= rhs.data[0];
            data[1] *= rhs.data[1];
            data[2] *= rhs.data[2];
            data[3] *= rhs.data[3];
            return *this;
        }

        Vector4<T> operator/(const T a) const {
            return Vector4<T>(data[0] / a, data[1] / a, data[2] / a, data[3] / a);
        }

        Vector4<T>& operator/(const T a) {
            data[0] /= a;
            data[1] /= a;
            data[2] /= a;
            data[3] /= a;
            return *this;
        }

        bool operator==(const Vector4<T>& rhs) const {
            return (data[0] == rhs.data[0]) && (data[1] == rhs.data[1]) && (data[2] == rhs.data[2]) && (data[3] == rhs.data[3]);
        }

        bool operator!=(const Vector4<T>& rhs) const {
            return (data[0] != rhs.data[0]) || (data[1] != rhs.data[1]) || (data[2] != rhs.data[2]) || (data[3] != rhs.data[3]);
        }

        friend std::ostream& operator<<(std::ostream& os, const Vector4<T>& vec);

		T X() { return data[0]; }
		T Y() { return data[1]; }
		T Z() { return data[2]; }
		T W() { return data[3]; }
		T X(T x) { data[0] = x; }
		T Y(T y) { data[0] = y; }
		T Z(T z) { data[0] = z; }
		T W(T w) { data[0] = w; }
        
	public:
		T data[4];		
	};

}

#endif