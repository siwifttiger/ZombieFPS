#ifndef COLLISIONPLANE_H
#define COLLISIONPLANE_H

#include"vector3d.h"
class CollisionPlane
{
public:
	Vector3d p[4];           //4 points in a plane
	Vector3d normal;         //normal
public:
	CollisionPlane(float i, float j, float k,
		           float x1, float y1, float z1, 
				   float x2, float y2, float z2, 
		           float x3, float y3, float z3,
				   float x4, float y4, float z4	);

	Vector3d get1Point();
	Vector3d get2Point();
	Vector3d get3Point();
	Vector3d get4Point();
	Vector3d getNormal();

	bool isOK();
};

#endif
