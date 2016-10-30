
#ifndef VECTOR3D_H
#define VECTOR3D_H
#include<iostream>
#include<cmath>
const float EXP = 1e-10f;


class Vector3d {
public:
	float x, y, z;
public:
	Vector3d();
	Vector3d(float x, float y);
	Vector3d(float x, float y, float z); 

	float dotProduct(const Vector3d& vec);
	Vector3d crossProduct(const Vector3d& vec);
	float length() const;
	void normalize();

	//change coordinate
	void set(float a, float b, float c);
	void set(const Vector3d& v2);
//	void set(Vector3d v2);
	void setX(float a);
	void setY(float b);
	void setZ(float c);

	//get coordinate
	float getX() const;
	float getY() const;
	float getZ() const;

	//operators
	Vector3d operator+(const Vector3d& v2);
	Vector3d operator-(const Vector3d& v2);
	Vector3d operator*(const float num);
	Vector3d operator/(const float num);

	Vector3d& operator+=(const Vector3d& v2);
	Vector3d& operator-=(const Vector3d& v2);
	Vector3d& operator*=(const float num);
	Vector3d& operator/=(const float num);

	bool operator==(const Vector3d& v2);
	bool operator!=(const Vector3d& v2);

	friend std::ostream& operator<<(std::ostream& out, const Vector3d& v2);

};
#endif // !1
