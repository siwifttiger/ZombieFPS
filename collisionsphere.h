#ifndef COLLISIONSPHERE_H
#define COLLISIONSPHERE_H
#include"vector3d.h"

class CollisionSphere
{
public:
	float r;
	Vector3d center;
public:
	CollisionSphere()
	{
		center.setX(0.0);
		center.setY(0.0);
		center.setZ(0.0);
		r = 0.0;
	}

	CollisionSphere(Vector3d& cen, float radius)
	{
		r = radius;
		center.set(cen);
	}

	float getR() const
	{
		return r;
	}

	void setR(float radius)
	{
		r = radius;
	}

	Vector3d getCenter() const
	{
		return center;
	}

	void setCenter(Vector3d& v)
	{
		center.set(v);
	}
};
	
#endif
