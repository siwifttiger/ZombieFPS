#include"collisionplane.h"

CollisionPlane::CollisionPlane(float i, float j, float k,
	float x1, float y1, float z1,
	float x2, float y2, float z2,
	float x3, float y3, float z3,
	float x4, float y4, float z4)
{
	normal.set(i,j,k);
	p[0].set(x1,y1,z1);
	p[1].set(x2,y2,z2);
	p[2].set(x3,y3,z3);
	p[3].set(x4,y4,z4);
}

Vector3d CollisionPlane::get1Point()
{
	return p[0];
}

Vector3d CollisionPlane::get2Point()
{
	return p[1];
}
Vector3d CollisionPlane::get3Point()
{
	return p[2];
}

Vector3d CollisionPlane::get4Point()
{
	return p[3];
}
Vector3d CollisionPlane::getNormal()
{
	return normal;
}

bool CollisionPlane::isOK()
{
	return (normal.getX() != 0.0 && normal.getY() != 0.0 && normal.getZ() != 0.0);
}