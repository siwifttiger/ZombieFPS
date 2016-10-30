#ifndef COLLISION_H
#define COLLISION_H
#include"vector3d.h"
class Collision
{
public:
	static bool spherePlane(Vector3d& sp, Vector3d pn, Vector3d p1, Vector3d p2, Vector3d p3, Vector3d p4, float r);
	static bool raySphere(float xc, float yc, float zc, float xd, float yd, float zd, float xs, float ys, float zs, float r, float* dist = NULL, Vector3d* collpoint = NULL);
	static bool rayPlane(const float& nx, float ny, float nz, float x0, float y0, float z0, float xs, float ys, float zs, float xd, float yd, float zd, Vector3d p1, Vector3d p2, Vector3d p3, Vector3d p4, float* dis = NULL, Vector3d* point = NULL);
	static float rayplanedist(float nx, float ny, float nz, float x0, float y0, float z0, float xs, float ys, float zs, float xd, float yd, float zd);
	static float triangleArea(Vector3d p1, Vector3d p2, Vector3d p3);
	static bool sphereSphere(Vector3d& c1, float r1, Vector3d& c2, float r2);
	static float pointDistanceSquare(Vector3d p1, Vector3d p2);
	static float pointDistance(Vector3d p1, Vector3d p2);
};

#endif
