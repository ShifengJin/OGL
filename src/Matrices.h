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
class Matrix2;

template<typename T>
std::ostream& operator<<(std::ostream& os, const Matrix2<T>& m) {
    os << std::fixed << std::setprecision(6);
    os << "[" << std::setw(10) << m.data[0] << " " << std::setw(10) << m.data[1] << "]\n"
       << "[" << std::setw(10) << m.data[2] << " " << std::setw(10) << m.data[2] << "]\n";
    os << std::resetiosflags(std::ios_base::fixed | std::ios_base::floatfield);
    return os;
}

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
    
    friend std::ostream& operator<<(std::ostream& os, const Matrix2<T>& m);

public:
    T data[4];

};

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

    Matrix3<T>& Identity() {
        data[0] = data[4] = data[8] = (T)1.;
        data[1] = data[2] = data[3] = data[5] = data[6] = data[7] = (T)0.;
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

    

public:
    T data[9];
}


}

#endif