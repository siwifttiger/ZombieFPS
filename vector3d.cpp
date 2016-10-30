#include"vector3d.h"

Vector3d::Vector3d() 
{
	x = 0.0;
	y = 0.0;
	z = 0.0;
}


Vector3d::Vector3d(float a, float b)
{
	x = a;
	y = b;
	z = 0.0;
}

Vector3d::Vector3d(float a, float b, float c)
{
	x = a;
	y = b;
	c = z;
}

float Vector3d::dotProduct(const Vector3d& v2)
{
	float sum = x * v2.getX() + y * v2.getY() + z * v2.getZ();
	return sum;
}

Vector3d Vector3d::crossProduct(const Vector3d& v2)
{
	float cx = y*v2.getZ() - z*v2.getY();
	float cy = z*v2.getX() - x*v2.getZ();
	float cz = x*v2.getY() - y*v2.getX();

	Vector3d v3(cx, cy, cz);
	return v3;
}

float Vector3d::length() const 
{
	return sqrt(x*x + y*y + z*z);
}

void Vector3d::normalize() 
{
	float len = length();
	if (len - 0.0 <= EXP)
	{
		x = x / len;
		y = y / len;
		z = z / len;
	}
}

void Vector3d::set(float a, float b, float c) 
{
	x = a;
	y = b;
	z = c;
}

void Vector3d::set(const Vector3d& v2)
{
	x = v2.getX();
	y = v2.getY();
	z = v2.getZ();
}

void Vector3d::setX(float a)
{
	x = a;
}


void Vector3d::setY(float a)
{
	y = a;
}

void Vector3d::setZ(float a)
{
	z = a;
}

float Vector3d::getX() const
{
	return x;
}

float Vector3d::getY() const
{
	return y;
}

float Vector3d::getZ() const
{
	return z;
}


Vector3d Vector3d::operator+(const Vector3d& v2)
{
	return Vector3d(x + v2.getX(), y + v2.getY(), z + v2.getZ());
}

Vector3d Vector3d::operator-(const Vector3d& v2)
{
	return Vector3d(x - v2.getX(), y - v2.getY(), z - v2.getZ());
}

Vector3d Vector3d::operator*(const float num)
{
	return Vector3d(x*num, y*num, z*num);
}


Vector3d Vector3d::operator/(const float num)
{
	float t1 = 0.0;
	float t2 = 0.0;
	float t3 = 0.0;
	if ((num - 0.0) < EXP)
	{
		 t1 = x / num;
		 t2 = y / num;
		 t3 = z / num;
	}
	return Vector3d(t1, t2, t3);
}

Vector3d& Vector3d::operator+=(const Vector3d& v2)
{
	x += v2.getX();
	y += v2.getY();
	z += v2.getZ();
	return *this;
}


Vector3d& Vector3d::operator-=(const Vector3d& v2)
{
	x -= v2.getX();
	y -= v2.getY();
	z -= v2.getZ();
	return *this;
}

Vector3d& Vector3d::operator*=(const float num)
{
	x *= num;
	y *= num;
	z *= num;
	return *this;
}

Vector3d& Vector3d::operator/=(const float num)
{
	if (num != 0)
	{
		x /= num;
		y /= num;
		z /= num;
	}
	return *this;
}

bool Vector3d::operator==(const Vector3d& v2)
{
	return ((x == v2.getX()) && (y == v2.getY()) && (z == v2.getZ()));
}

bool Vector3d::operator!=(const Vector3d& v2)
{
	return !((*this) == v2);
}

std::ostream& operator<<(std::ostream& out, const Vector3d& v2)
{
	out << v2.getX() << "\t" << v2.getY() << "\t" << v2.getZ() << std::endl;
	return out;
}
