#ifndef _MATRICES_H_
#define _MATRICES_H_

#include <math.h>
#include <iostream>
#include <iomanip>
#include "Vectors.h"

#define RAD2DEG 57.29578049
#define DEG2RAD 0.017453292
#define EPSILON 0.000001

namespace Darker{

template<typename T>
class Matrix2{
public:
    Matrix2(){
        Identity();
    }

    Matrix2(const T src[4]){
        data[0] = src[0]; data[1] = src[1];
        data[2] = src[2]; data[3] = src[3];
    }

    Matrix2(T m00, T m01, T m10, T m11) {
        data[0] = m00; data[1] = m01;
        data[2] = m10; data[3] = m11;
    }

    Matrix2(const Matrix2<T>& m2x2) {
        data[0] = m2x2.data[0]; data[1] = m2x2.data[1];
        data[2] = m2x2.data[2]; data[3] = m2x2.data[3];
    }

    T GetDeterminant() const {
        return (T)(data[0] * data[3] - data[1] * data[2]);
    }

    // retrieve rotation angle in degree from rotation matrix, R
    // R = | c -s |
    //     | s  c |
    // angle = atan(s / c)
    T GetAngle() const {
        return T(RAD2DEG * atan2(data[1], data[0]));
    }

    Matrix2<T>& Identity() {
        data[0] = data[3] = (T)1.;
        data[1] = data[2] = (T)0.;
        return *this;
    }

    Matrix2<T>& Transpose() {
        T tmp = data[1];
        data[1] = data[2];
        data[2] = tmp;
        return *this;
    }

    Matrix2<T>& Invert() {
        T determinant = GetDeterminant();
        if(fabs(determinant) <= EPSILON){
            return Identity();
        }

        T tmp = data[0];
        T invDeterminant = (T)(1. / determinant);
        data[0] =  invDeterminant * data[3];
        data[1] = -invDeterminant * data[1];
        data[2] = -invDeterminant * data[2];
        data[3] =  invDeterminant * tmp;
        return *this;
    }

    Matrix2<T> operator+(const Matrix2<T>& rhs) const {
        return Matrix2<T>(data[0] + rhs.data[0], data[1] + rhs.data[1],
                          data[2] + rhs.data[2], data[3] + rhs.data[3]);
    }

    Matrix2<T> operator-(const Matrix2<T>& rhs) const {
        return Matrix2<T>(data[0] - rhs.data[0], data[1] - rhs.data[1],
                          data[2] - rhs.data[2], data[3] - rhs.data[3]);
    }

    Matrix2<T>& operator+=(const Matrix2<T>& rhs) {
        data[0] += rhs.data[0];
        data[1] += rhs.data[1];
        data[2] += rhs.data[2];
        data[3] += rhs.data[3];
        return *this;
    }

    Matrix2<T>& operator-=(const Matrix2<T>& rhs) {
        data[0] -= rhs.data[0];
        data[1] -= rhs.data[1];
        data[2] -= rhs.data[2];
        data[3] -= rhs.data[3];
        return *this;
    }

    Vector2<T> operator*(const Vector2<T>& rhs) const {
        return Vector2<T>(data[0] * rhs.data[0] + data[1] * rhs.data[1], data[2] * rhs.data[0] + data[3] * rhs.data[1]);
    }

    Matrix2<T> operator*(const Matrix2<T>& rhs) const {
        return Matrix2<T>(data[0] * rhs.data[0] + data[1] * rhs.data[2], 
                          data[0] * rhs.data[1] + data[1] * rhs.data[3],
                          data[2] * rhs.data[0] + data[3] * rhs.data[2],
                          data[2] * rhs.data[1] + data[3] * rhs.data[3]);
    }

    Matrix2<T>& operator*=(const Matrix2<T>& rhs) {
        *this = *this * rhs;
        return *this;
    }

    bool operator==(const Matrix2<T>& rhs) const {
        return (data[0] == rhs.data[0]) && (data[1] == rhs.data[1]) && (data[2] == rhs.data[2]) && (data[3] == rhs.data[3]);
    }

    bool operator!=(const Matrix2<T>& rhs) const {
        return (data[0] != rhs.data[0]) || (data[1] != rhs.data[1]) || (data[2] != rhs.data[2]) || (data[3] != rhs.data[3]);
    }
    
    T operator[](int index) const {
        return data[index];
    }

    T& operator[](int index) {
        return data[index];
    }

    friend Matrix2<T> operator-(const Matrix2<T>& m);
    friend Matrix2<T> operator*(T scalar, const Matrix2<T>& m);
    friend Vector2<T> operator*(const Vector2<T>& vec, const Matrix2<T>& m);
    friend std::ostream& operator<<(std::ostream& os, const Matrix2<T>& m);

public:
    T data[4];

};

template<typename T>
inline Matrix2<T> operator-(const Matrix2<T>& rhs) {
    return Matrix2<T>(-rhs.data[0], -rhs.data[1], -rhs.data[2], -rhs.data[3]);
}

template<typename T>
inline Matrix2<T> operator*(T s, const Matrix2<T>& rhs) {
    return Matrix2<T>(s * rhs.data[0], s * rhs.data[1], s * rhs.data[2], s * rhs.data[3]);
}

template<typename T>
inline Vector2<T> operator*(const Vector2<T>& v, const Matrix2<T>* rhs) {
    return Vector2<T>(
        v.X() * rhs.data[0] + v.Y() * rhs.data[2],
        v.X() * rhs.data[1] + v.Y() * rhs.data[3]);
}

template<typename T>
inline std::ostream& operator<<(std::ostream& os, const Matrix2<T>& m) {
    os << std::fixed << std::setprecision(6);
    os << "[" << std::setw(10) << m.data[0] << " " << std::setw(10) << m.data[1] << "]\n"
       << "[" << std::setw(10) << m.data[2] << " " << std::setw(10) << m.data[2] << "]\n";
    os << std::resetiosflags(std::ios_base::fixed | std::ios_base::floatfield);
    return os;
}

template<typename T>
class Matrix3{
public:
    Matrix3() {
        Identity();
    }

    Matrix3(const T src[9]) {
        data[0] = src[0]; data[1] = src[1]; data[2] = src[2];
        data[3] = src[3]; data[4] = src[4]; data[5] = src[5];
        data[6] = src[6]; data[7] = src[7]; data[8] = src[8];
    }

    Matrix3(T m00, T m01, T m02, T m10, T m11, T m12, T m20, T m21, T m22){
        data[0] = m00; data[1] = m01; data[2] = m02;
        data[3] = m10; data[4] = m11; data[5] = m12;
        data[6] = m20; data[7] = m21; data[8] = m22;
    }

    Matrix3(const Matrix3<T>& m3x3) {
        data[0] = m3x3.data[0]; data[1] = m3x3.data[1]; data[2] = m3x3.data[2];
        data[3] = m3x3.data[3]; data[4] = m3x3.data[4]; data[5] = m3x3.data[5];
        data[6] = m3x3.data[6]; data[7] = m3x3.data[7]; data[8] = m3x3.data[8];
    }

    T GetDeterminant() const {
        return data[0] * (data[4] * data[8] - data[5] * data[7]) -
               data[1] * (data[3] * data[8] - data[5] * data[6]) + 
               data[2] * (data[3] * data[7] - data[4] * data[6]);
    }

#if 0
    // retrieve angles in degree from rotation matrix, M = Rx*Ry*Rz
    // Rx: rotation about X-axis, pitch
    // Ry: rotation about Y-axis, yaw(heading)
    // Rz: rotation about Z-axis, roll
    //    Rx           Ry          Rz
    // |1  0   0| | Cy  0 Sy| |Cz -Sz 0|   | CyCz        -CySz         Sy  |
    // |0 Cx -Sx|*|  0  1  0|*|Sz  Cz 0| = | SxSyCz+CxSz -SxSySz+CxCz -SxCy|
    // |0 Sx  Cx| |-Sy  0 Cy| | 0   0 1|   |-CxSyCz+SxSz  CxSySz+SxCz  CxCy|
    //
    // Pitch: atan(-m[5] / m[8]) = atan(SxCy/CxCy)                x
    // Yaw  : asin(m[2]) = asin(Sy)                               y
    // Roll : atan(-m[1] / m[0]) = atan(SzCy/CzCy)                z
    Vector3<T> GetAngle() const {  
        T pitch, yaw, roll;

        // find yaw (around y-axis) first
        // NOTE: asin() returns -90~+90, so correct the angle range -180~+180
        // using z value of forward vector
        yaw = (T)(RAD2DEG * asin(data[2]));
        if(data[8] < 0){
            if(yaw >= 0) yaw = (T)( 180. - yaw);
            else         yaw = (T)(-180. - yaw);
        }

        // find roll (around z-axis) and pitch (around x-axis)
        // if forward vector is (1,0,0) or (-1,0,0), then m[0]=m[4]=m[9]=m[10]=0
        if(data[0] > -EPSILON && data[0] < EPSILON)
        {
            roll  = (T)0.;  //@@ assume roll=0
            pitch = (T)(RAD2DEG * atan2(m[3], m[4]));
        }
        else
        {
            roll = (T)(RAD2DEG * atan2(-m[1], m[0]));
            pitch = (T)(RAD2DEG * atan2(-m[5], m[8]));
        }
        return Vector3<T>(pitch, yaw, roll);
    }
#endif

    Matrix3<T>& Identity() {
        data[0] = data[4] = data[8] = (T)1.;
        data[1] = data[2] = data[3] = data[5] = data[6] = data[7] = (T)0.;
        return *this;
    }

    Matrix3<T>& Transpose() {
        T tmp = data[1];
        data[1] = data[3];
        data[3] = tmp;

        tmp = data[2];
        data[2] = data[6];
        data[6] = tmp;

        tmp = data[5];
        data[5] = data[7];
        data[7] = tmp;

        return *this;
    }

    ///////////////////////////////////////////////////////////////////////////////
    // inverse 3x3 matrix
    // If cannot find inverse (det=0), set identity matrix
    // M^-1 = adj(M) / det(M)
    //        | m4m8-m5m7  m5m6-m3m8  m3m7-m4m6 |
    //      = | m7m2-m8m1  m0m8-m2m6  m6m1-m7m0 | / det(M)
    //        | m1m5-m2m4  m2m3-m0m5  m0m4-m1m3 |
    ///////////////////////////////////////////////////////////////////////////////
    Matrix3<T>& Invert() {
        T determinant, invDeterminant;
        T tmp[9];
        tmp[0] = data[4] * data[8] - data[5] * data[7];
        tmp[1] = data[5] * data[6] - data[3] * data[8];
        tmp[2] = data[3] * data[7] - data[4] * data[6];
        tmp[3] = data[7] * data[2] - data[8] * data[1];
        tmp[4] = data[0] * data[8] - data[2] * data[6];
        tmp[5] = data[6] * data[1] - data[7] * data[0];
        tmp[6] = data[1] * data[5] - data[2] * data[4];
        tmp[7] = data[2] * data[3] - data[0] * data[5];
        tmp[8] = data[0] * data[4] - data[1] * data[3];

        determinant = data[0] * tmp[0] + data[1] * tmp[1] + data[2] * tmp[2];
        if(fabs(determinant) <= EPSILON){
            return Identity();
        }

        invDeterminant = T(1. / determinant);

        data[0] = invDeterminant * tmp[0];
        data[1] = invDeterminant * tmp[1];
        data[2] = invDeterminant * tmp[2];
        data[3] = invDeterminant * tmp[3];
        data[4] = invDeterminant * tmp[4];
        data[5] = invDeterminant * tmp[5];
        data[6] = invDeterminant * tmp[6];
        data[7] = invDeterminant * tmp[7];
        data[8] = invDeterminant * tmp[8];

        return *this;
    }

    Matrix3<T> operator+(const Matrix3<T>& rhs) const {
        return Matrix3<T>(data[0] + rhs.data[0], data[1] + rhs.data[1], data[2] + rhs.data[2],
                          data[3] + rhs.data[3], data[4] + rhs.data[4], data[5] + rhs.data[5],
                          data[6] + rhs.data[6], data[7] + rhs.data[7], data[8] + rhs.data[8]);
    }

    Matrix3<T> operator-(const Matrix3<T>& rhs) const {
        return Matrix3<T>(data[0] - rhs.data[0], data[1] - rhs.data[1], data[2] - rhs.data[2],
                          data[3] - rhs.data[3], data[4] - rhs.data[4], data[5] - rhs.data[5],
                          data[6] - rhs.data[6], data[7] - rhs.data[7], data[8] - rhs.data[8]);
    }

    Matrix3<T>& operator+=(const Matrix3<T>& rhs) {
        data[0] += rhs.data[0]; data[1] += rhs.data[1]; data[2] += rhs.data[2];
        data[3] += rhs.data[3]; data[4] += rhs.data[4]; data[5] += rhs.data[5];
        data[6] += rhs.data[6]; data[7] += rhs.data[7]; data[8] += rhs.data[8];
        return *this;
    }

    Matrix3<T>& operator-=(const Matrix3<T>& rhs) {
        data[0] -= rhs.data[0]; data[1] -= rhs.data[1]; data[2] -= rhs.data[2];
        data[3] -= rhs.data[3]; data[4] -= rhs.data[4]; data[5] -= rhs.data[5];
        data[6] -= rhs.data[6]; data[7] -= rhs.data[7]; data[8] -= rhs.data[8];
        return *this;
    }

    Vector3<T> operator*(const Vector3<T>& rhs) const {
        return Vector3<T>(data[0] * rhs.data[0] + data[1] * rhs.data[1] + data[2] * rhs.data[2],
                          data[3] * rhs.data[0] + data[4] * rhs.data[1] + data[5] * rhs.data[2],
                          data[6] * rhs.data[0] + data[7] * rhs.data[1] + data[8] * rhs.data[2]);
    }

    Matrix3<T> operator*(const Matrix3<T>& rhs) const {
        return Matrix3<T>(
            data[0] * rhs.data[0] + data[1] * rhs.data[3] + data[2] * rhs.data[6],
            data[0] * rhs.data[1] + data[1] * rhs.data[4] + data[2] * rhs.data[7],
            data[0] * rhs.data[2] + data[1] * rhs.data[5] + data[2] * rhs.data[8],

            data[3] * rhs.data[0] + data[4] * rhs.data[3] + data[5] * rhs.data[6],
            data[3] * rhs.data[1] + data[4] * rhs.data[4] + data[5] * rhs.data[7],
            data[3] * rhs.data[2] + data[4] * rhs.data[5] + data[5] * rhs.data[8],

            data[6] * rhs.data[0] + data[7] * rhs.data[3] + data[8] * rhs.data[6],
            data[6] * rhs.data[1] + data[7] * rhs.data[4] + data[8] * rhs.data[7],
            data[6] * rhs.data[2] + data[7] * rhs.data[5] + data[8] * rhs.data[8]
        );
    }

    Matrix3<T>& operator*=(const Matrix3<T>& rhs) {
        *this = *this * rhs;
        return *this;
    }

    bool operator==(const Matrix3<T>& rhs) const {
        return (data[0] == rhs.data[0]) && (data[1] == rhs.data[1]) && (data[2] == rhs.data[2]) &&
               (data[3] == rhs.data[3]) && (data[4] == rhs.data[4]) && (data[5] == rhs.data[5]) && 
               (data[6] == rhs.data[6]) && (data[7] == rhs.data[7]) && (data[8] == rhs.data[8]);
    }

    bool operator!=(const Matrix3<T>& rhs) const {
        return (data[0] != rhs.data[0]) || (data[1] != rhs.data[1]) || (data[2] != rhs.data[2]) ||
               (data[3] != rhs.data[3]) || (data[4] != rhs.data[4]) || (data[5] != rhs.data[5]) || 
               (data[6] != rhs.data[6]) || (data[7] != rhs.data[7]) || (data[8] != rhs.data[8]);
    }

    T operator[](int index) const {
        return data[index];
    }

    T& operator[](int index) {
        return data[index];
    }

    friend Matrix3<T> operator-(const Matrix3<T>& m);
    friend Matrix3<T> operator*(T scalar, const Matrix3<T>& m);
    friend Vector3<T> operator*(const Vector3<T>& vec, const Matrix3<T>& m);
    friend std::ostream& operator<<(std::ostream& os, const Matrix3<T>& m);

public:
    T data[9];
};

template<typename T>
inline Matrix3<T> operator-(const Matrix3<T>& rhs) {
    return Matrix3<T>(
        -rhs.data[0], -rhs.data[1], -rhs.data[2], 
        -rhs.data[3], -rhs.data[4], -rhs.data[5], 
        -rhs.data[6], -rhs.data[7], -rhs.data[8]);
}

template<typename T>
inline Matrix3<T> operator*(T s, const Matrix3<T>& rhs) {
    return Matrix3<T>(
        s * rhs.data[0], s * rhs.data[1], s * rhs.data[2], 
        s * rhs.data[3], s * rhs.data[4], s * rhs.data[5], 
        s * rhs.data[6], s * rhs.data[7], s * rhs.data[8]);
}

template<typename T>
inline Vector3<T> operator*(const Vector3<T>& v, const Matrix3<T>& m){
    return Vector3<T>(
        v.X() * m.data[0] + v.Y() * m.data[3] + v.Z() * m.data[6],
        v.X() * m.data[1] + v.Y() * m.data[4] + v.Z() * m.data[7],
        v.X() * m.data[2] + v.Y() * m.data[5] + v.Z() * m.data[8]
    );
}

template<typename T>
inline std::ostream& operator<<(std::ostream& os, const Matrix3<T>& m) {
    os << std::fixed << std::setprecision(6);
    os << "[" << std::setw(10) << m.data[0] << " " << std::setw(10) << m.data[1] << " " << std::setw(10) << m.data[2] << "]\n"
       << "[" << std::setw(10) << m.data[3] << " " << std::setw(10) << m.data[4] << " " << std::setw(10) << m.data[5] << "]\n"
       << "[" << std::setw(10) << m.data[6] << " " << std::setw(10) << m.data[7] << " " << std::setw(10) << m.data[8] << "]\n";
    os << std::resetiosflags(std::ios_base::fixed | std::ios_base::floatfield);
    return os;
}

template<typename T>
class Matrix4 {
public:
    Matrix4(){
        Identity();
    }

    Matrix4(const T src[16]) {
        data[0 ] = src[0 ]; data[1 ] = src[1 ]; data[2 ] = src[2 ]; data[3 ] = src[3 ];
        data[4 ] = src[4 ]; data[5 ] = src[5 ]; data[6 ] = src[6 ]; data[7 ] = src[7 ];
        data[8 ] = src[8 ]; data[9 ] = src[9 ]; data[10] = src[10]; data[11] = src[11];
        data[12] = src[12]; data[13] = src[13]; data[14] = src[14]; data[15] = src[15];
    }

    Matrix4(T m00, T m01, T m02, T m03,
            T m10, T m11, T m12, T m13,
            T m20, T m21, T m22, T m23,
            T m30, T m31, T m32, T m33) {
        data[0 ] = m00; data[1 ] = m01, data[2 ] = m02, data[3 ] = m03;
        data[4 ] = m10; data[5 ] = m11, data[6 ] = m12, data[7 ] = m13;
        data[8 ] = m20; data[9 ] = m21, data[10] = m22, data[11] = m23;
        data[12] = m30; data[13] = m31, data[14] = m32, data[15] = m33;
    }

    // m0   m1   m2   m3
    // m4   m5   m6   m7
    // m8   m9   m10  m11
    // m12  m13  m14  m15
    T GetDeterminant() const {
        return data[0] * getCofactor(data[5], data[6], data[7], data[9], data[10], data[11], data[13], data[14], data[15]) -
               data[1] * getCofactor(data[4], data[6], data[7], data[8], data[10], data[11], data[12], data[14], data[15]) +
               data[2] * getCofactor(data[4], data[5], data[7], data[8], data[9 ], data[11], data[12], data[13], data[15]) -
               data[3] * getCofactor(data[4], data[5], data[6], data[8], data[9 ], data[10], data[12], data[13], data[14]);
    }

    Matrix3<T> GetRotationMatrix() const {
        Matrix3<T> mat(data[0], data[1], data[2],
                       data[4], data[5], data[6],
                       data[8], data[9], data[10]);
        return mat;
    }

    Matrix4<T>& Identity() {
        data[0] = data[5] = data[10] = data[15] = (T)(1.);
        data[1] = data[2] = data[3] = data[4] = data[6] = data[7] = data[8] = data[9] = data[11] = data[12] = data[13] = data[14] = (T)(0.);
        return *this;
    }

    Matrix4<T>& Transpose() {
        T tmp = data[1];
        data[1] = data[4];
        data[4] = tmp;

        tmp = data[2];
        data[2] = data[8];
        data[8] = tmp;

        tmp = data[3];
        data[3] = data[12];
        data[12] = tmp;

        tmp = data[6];
        data[6] = data[9];
        data[9] = tmp;

        tmp = data[7];
        data[7] = data[13];
        data[13] = tmp;

        tmp = data[11];
        data[11] = data[14];
        data[14] = tmp;
    }

    ///////////////////////////////////////////////////////////////////////////////
    // compute the inverse of 4x4 Euclidean transformation matrix
    //
    // Euclidean transformation is translation, rotation, and reflection.
    // With Euclidean transform, only the position and orientation of the object
    // will be changed. Euclidean transform does not change the shape of an object
    // (no scaling). Length and angle are reserved.
    //
    // Use inverseAffine() if the matrix has scale and shear transformation.
    //
    // M = [ R | T ]
    //     [ --+-- ]    (R denotes 3x3 rotation/reflection matrix)
    //     [ 0 | 1 ]    (T denotes 1x3 translation matrix)
    //
    // y = M*x  ->  y = R*x + T  ->  x = R^-1*(y - T)  ->  x = R^T*y - R^T*T
    // (R is orthogonal,  R^-1 = R^T)
    //
    //  [ R | T ]-1    [ R^T | -R^T * T ]    (R denotes 3x3 rotation matrix)
    //  [ --+-- ]   =  [ ----+--------- ]    (T denotes 1x3 translation)
    //  [ 0 | 1 ]      [  0  |     1    ]    (R^T denotes R-transpose)
    ///////////////////////////////////////////////////////////////////////////////
    Matrix4<T>& InvertEuclidean() {
        T tmp;
        tmp = data[1]; data[1] = data[4]; data[4] = tmp;
        tmp = data[2]; data[2] = data[8]; data[8] = tmp;
        tmp = data[6]; data[6] = data[9]; data[9] = tmp;

        T x = data[3];
        T y = data[7];
        T z = data[11];

        data[3] = -(data[0] * x + data[1] * y + data[2] * z);
        data[7] = -(data[4] * x + data[5] * y + data[6] * z);
        data[11] = -(data[8] * x + data[9] * y + data[10] * z);

        return *this;
    }

    ///////////////////////////////////////////////////////////////////////////////
    // compute the inverse of a 4x4 affine transformation matrix
    //
    // Affine transformations are generalizations of Euclidean transformations.
    // Affine transformation includes translation, rotation, reflection, scaling,
    // and shearing. Length and angle are NOT preserved.
    // M = [ R | T ]
    //     [ --+-- ]    (R denotes 3x3 rotation/scale/shear matrix)
    //     [ 0 | 1 ]    (T denotes 1x3 translation matrix)
    //
    // y = M*x  ->  y = R*x + T  ->  x = R^-1*(y - T)  ->  x = R^-1*y - R^-1*T
    //
    //  [ R | T ]-1   [ R^-1 | -R^-1 * T ]
    //  [ --+-- ]   = [ -----+---------- ]
    //  [ 0 | 1 ]     [  0   +     1     ]
    ///////////////////////////////////////////////////////////////////////////////
    Matrix4<T>& InvertAffinne() {
        // R^-1
        Matrix3<T> r(data[0], data[1], data[2], 
                     data[4], data[5], data[6], 
                     data[8], data[9], data[10]);
        r.Invert();

        data[0] = r.data[0]; data[1] = r.data[1]; data[2] = r.data[2];
        data[4] = r.data[3]; data[5] = r.data[4]; data[6] = r.data[5];
        data[8] = r.data[6]; data[9] = r.data[7]; data[10] = r.data[8];

        // -R^-1 * T
        T x = data[3];
        T y = data[7];
        T z = data[11];
        data[3] = -(data[0] * x + data[1] * y + data[2] * z);
        data[7] = -(data[4] * x + data[5] * y + data[6] * z);
        data[11] = -(data[8] * x + data[9] * y + data[10] * z);
        return *this;
    }
    
    ///////////////////////////////////////////////////////////////////////////////
    // compute the inverse of a general 4x4 matrix using Cramer's Rule
    // If cannot find inverse, return indentity matrix
    // M^-1 = adj(M) / det(M)
    ///////////////////////////////////////////////////////////////////////////////
    Matrix4<T>& InvertGeneral() {
        // get cofactors of minor matrices
        float cofactor0 = getCofactor(data[5], data[6], data[7], data[9],data[10], data[11], data[13], data[14], data[15]);
        float cofactor1 = getCofactor(data[4], data[6], data[7], data[8],data[10], data[11], data[12], data[14], data[15]);
        float cofactor2 = getCofactor(data[4], data[5], data[7], data[8],data[9 ], data[11], data[12], data[13], data[15]);
        float cofactor3 = getCofactor(data[4], data[5], data[6], data[8],data[9 ], data[10], data[12], data[13], data[14]);

        // get determinant
        float determinant = data[0] * cofactor0 - data[1] * cofactor1 + data[2] * cofactor2 - data[3] * cofactor3;
        if(fabs(determinant) <= EPSILON)
        {
            return identity();
        }

        // get rest of cofactors for adj(M)
        float cofactor4 = getCofactor(data[1], data[2], data[3], data[9], data[10], data[11], data[13], data[14], data[15]);
        float cofactor5 = getCofactor(data[0], data[2], data[3], data[8], data[10], data[11], data[12], data[14], data[15]);
        float cofactor6 = getCofactor(data[0], data[1], data[3], data[8], data[9 ], data[11], data[12], data[13], data[15]);
        float cofactor7 = getCofactor(data[0], data[1], data[2], data[8], data[9 ], data[10], data[12], data[13], data[14]);

        float cofactor8 = getCofactor(data[1], data[2], data[3], data[5], data[6], data[7],  data[13], data[14], data[15]);
        float cofactor9 = getCofactor(data[0], data[2], data[3], data[4], data[6], data[7],  data[12], data[14], data[15]);
        float cofactor10= getCofactor(data[0], data[1], data[3], data[4], data[5], data[7],  data[12], data[13], data[15]);
        float cofactor11= getCofactor(data[0], data[1], data[2], data[4], data[5], data[6],  data[12], data[13], data[14]);

        float cofactor12= getCofactor(data[1], data[2],data[3], data[5], data[6], data[7], data[9], data[10], data[11]);
        float cofactor13= getCofactor(data[0], data[2],data[3], data[4], data[6], data[7], data[8], data[10], data[11]);
        float cofactor14= getCofactor(data[0], data[1],data[3], data[4], data[5], data[7], data[8], data[9 ], data[11]);
        float cofactor15= getCofactor(data[0], data[1],data[2], data[4], data[5], data[6], data[8], data[9 ], data[10]);

        // build inverse matrix = adj(M) / det(M)
        // adjugate of M is the transpose of the cofactor matrix of M
        float invDeterminant = 1.0f / determinant;
        data[0] =  invDeterminant * cofactor0;
        data[1] = -invDeterminant * cofactor4;
        data[2] =  invDeterminant * cofactor8;
        data[3] = -invDeterminant * cofactor12;

        data[4] = -invDeterminant * cofactor1;
        data[5] =  invDeterminant * cofactor5;
        data[6] = -invDeterminant * cofactor9;
        data[7] =  invDeterminant * cofactor13;

        data[8] =  invDeterminant * cofactor2;
        data[9] = -invDeterminant * cofactor6;
        data[10]=  invDeterminant * cofactor10;
        data[11]= -invDeterminant * cofactor14;

        data[12]= -invDeterminant * cofactor3;
        data[13]=  invDeterminant * cofactor7;
        data[14]= -invDeterminant * cofactor11;
        data[15]=  invDeterminant * cofactor15;
        return *this;
    }

    Matrix4<T>& Rotate(T angle, const Vector3<T>& axis) {
        return Rotate(angle, axis.X(), axis.Y(), axis.Z());
    }

    Matrix4<T>& Rotate(T angle, T x, T y, T z) {
        T c = (T)cos(angle * DEG2RAD);
        T s = (T)sin(angle * DEG2RAD);
        T = (T)(1. - c);

        T m00 = data[0]; 
        T m01 = data[1];
        T m02 = data[2];
        T m10 = data[4];
        T m11 = data[5];
        T m12 = data[6];
        T m20 = data[8];
        T m21 = data[9];
        T m22 = data[10];

        T m03 = data[3];
        T m13 = data[7];
        T m23 = data[11];

        T r00 = x * x * c1 + c;
        T r01 = x * y * c1 - z * s;
        T r02 = x * z * c1 + y * s;

        T r10 = x * y * c1 + z * s;
        T r11 = y * y * c1 + c;
        T r12 = y * z * c1 - x * s;

        T r20 = x * x * z * c1 - y * s;
        T r21 = y * z * c1 + x * s;
        T r22 = z * z * c1 + c;

        data[0] = r00 * m00 + r01 * m10 + r02 * m20;
        data[1] = r00 * m01 + r01 * m11 + r02 * m21;
        data[2] = r00 * m02 + r01 * m12 + r02 * m22;

        data[4] = r10 * m00 + r11 * m10 + r12 * m20;
        data[5] = r10 * m01 + r11 * m11 + r12 * m21;
        data[6] = r10 * m02 + r11 * m12 + r12 * m22;

        data[8] =  r20 * m00 + r21 * m10 + r22 * m20;
        data[9] =  r20 * m01 + r21 * m11 + r22 * m21;
        data[10] = r20 * m02 + r21 * m12 + r22 * m22;

        data[3] =  r00 * m03 + r01 * m13 + r02 * m23;
        data[7] =  r10 * m03 + r11 * m13 + r12 * m23;
        data[11] = r20 * m03 + r21 * m13 + r22 * m23;

        return *this;
    }

    /// @brief rotate x axis
    ///////////////////////////////////////////////////////////////////////
    //      1     0     0
    // X =  0    cos  -sin
    //      0    sin   cos
    ///////////////////////////////////////////////////////////////////////
    /// @param angle 
    /// @return 
    Matrix4<T>& RotateX(T angle) {

    }

    Matrix4<T>& RotateY(T angle) {
        
    }

    Matrix4<T>& RotateZ(T angle) {
        
    }

private:
    T getCofactor(T m0, T m1, T m2, T m3, T m4, T m5, T m6, T m7, T m8) const {
        return m0 * (m4 * m8 - m5 * m7) + 
               m1 * (m5 * m6 - m3 * m8) + 
               m2 * (m3 * m7 - m4 * m6);
    }

    T data[16];

};

}

#endif