#include"collision.h"

//解方程，判断直线和球面有没有交点
bool Collision::raySphere(float xc, float yc, float zc, float xd, float yd, float zd, float xs, float ys, float zs, float r, float* dist, Vector3d* collpoint)
{
	float b = 2 * (xd*(xs - xc) + yd*(ys - yc) + zd*(zs - zc));
	float c = xs*xs - 2 * xs*xc + xc*xc + ys*ys - 2 * ys*yc + yc*yc + zs*zs - 2 * zs*zc + zc*zc - r*r;
	float disc = (b*b - 4 * c);
	if (disc < 0)	//小于0 则没有交点
		return false;
	else {
		if (dist != NULL)  //dist 相当于单位时间t
		{
			(*dist) = (-b + sqrt(disc)) / 2;
			if (collpoint != NULL)
			{
				float x = xs + (*dist)*xd;   //         x = xs + t * xd
				float y = ys + (*dist)*yd;   //			y = ys + t * yd
				float z = zs + (*dist)*zd;  //          z = zs + t * zd
				collpoint->set(x, y, z);
			}
		}
		return true;
	}
}


//计算三角形的面积,海伦公式
float Collision::triangleArea(Vector3d p1, Vector3d p2, Vector3d p3)
{
	
	float a = sqrt((p2.x - p1.x)*(p2.x - p1.x) + (p2.y - p1.y)*(p2.y - p1.y) + (p2.z - p1.z)*(p2.z - p1.z));
	float b = sqrt((p3.x - p2.x)*(p3.x - p2.x) + (p3.y - p2.y)*(p3.y - p2.y) + (p3.z - p2.z)*(p3.z - p2.z));
	float c = sqrt((p1.x - p3.x)*(p1.x - p3.x) + (p1.y - p3.y)*(p1.y - p3.y) + (p1.z - p3.z)*(p1.z - p3.z));
	float s = (a + b + c) / 2.;
	return (sqrt(s*((s - a)*(s - b)*(s - c))));
}

//两点距离
float Collision::pointDistance(Vector3d p1, Vector3d p2)
{
	Vector3d vec(p2.x - p1.x, p2.y - p1.y, p2.z - p1.z);
	return (sqrt(vec.x*vec.x + vec.y*vec.y + vec.z*vec.z));
}
//两点距离的平方
float Collision::pointDistanceSquare(Vector3d p1, Vector3d p2)
{
	Vector3d vec(p2.x - p1.x, p2.y - p1.y, p2.z - p1.z);
	return (vec.x*vec.x + vec.y*vec.y + vec.z*vec.z);
}

//线段和平面的相交检测
//由于平面是无限大的，所以还需要进一步的检测
//利用三角形的面积来判断点是否真的落在那一块区域内部
bool Collision::rayPlane(const float& nx, float ny, float nz, float x0, float y0, float z0, float xs, float ys, float zs, float xd, float yd, float zd, Vector3d p1, Vector3d p2, Vector3d p3, Vector3d p4, float* dis, Vector3d* point)
{
	if ((xd*nx + yd*ny + zd*nz) == 0)	//点积为0，直线和平面平行
	{
		return false;
	}
	float t = ((x0*nx + y0*ny + z0*nz - nx*xs - ny*ys - nz*zs) / (xd*nx + yd*ny + zd*nz));
	if (t<0)	//t < 0 说明交点在相反的方向
	{
		return false;
	}
	float x = xs + t*xd;	
	float y = ys + t*yd;
	float z = zs + t*zd;
	Vector3d i(x, y, z);
	//判断交点是否真的落在指定区域内
	if ((std::abs(triangleArea(p1, p2, p3) - (triangleArea(p1, p2, i) + triangleArea(p2, p3, i) + triangleArea(p1, p3, i)))<0.3) || std::abs(triangleArea(p1, p3, p4) - (triangleArea(p1, p3, i) + triangleArea(p3, p4, i) + triangleArea(p1, p4, i)))<0.3)	//we divide the quad to 2 triangle, we divide one triangle to 3 (one point is the
																																																															//intersection point), and if the area of the 3 triangle is equal to the main triangle, then the point is inside the triangle. We do the same with
																																																															//the other triangle, and if one is true, then the point is in the quad
	{
		if (dis != NULL)
		{
			(*dis) = t;
			if (point != NULL)
			{
				point->x = x;
				point->y = y;
				point->z = z;
			}
		}
		return true;
	}
	return false;	
}
//球面和平面的相交检测
//sp为圆心坐标
//从圆心发射一条射线，检测这条射线是否与平面相交，通过相交距离来判断球面是否与平面相交
bool Collision::spherePlane(Vector3d& sp, Vector3d pn, Vector3d p1, Vector3d p2, Vector3d p3, Vector3d p4, float r)
{
	float dist1 = 0, dist2 = 0;
	//朝两个方向发射射线
	if (rayPlane(pn.x, pn.y, pn.z, p1.x, p1.y, p1.z, sp.x, sp.y, sp.z, -pn.x, -pn.y, -pn.z, p1, p2, p3, p4, &dist1) || rayPlane(-pn.x, -pn.y, -pn.z, p1.x, p1.y, p1.z, sp.x, sp.y, sp.z, pn.x, pn.y, pn.z, p1, p2, p3, p4, &dist2))
	{
		if (dist1>r || dist2>r)   //距离大于r，说明不相交
		{
			return false;
		}
		if (dist1>0)	//dist11
		{
			//若要恰好不相交，新的圆心的坐标
			sp.x = sp.x + pn.x*(r - dist1);	
			sp.y = sp.y + pn.y*(r - dist1);
			sp.z = sp.z + pn.z*(r - dist1);
		}
		else	
		{
			//同理
			sp.x = sp.x - pn.x*(r - dist2);
			sp.y = sp.y - pn.y*(r - dist2);
			sp.z = sp.z - pn.z*(r - dist2);
		}

		return true;
	}
	//否则不相交
	return false;
}


//球面与球面相交检测
bool Collision::sphereSphere(Vector3d& c1, float r1, Vector3d& c2, float r2)
{
	float dist = pointDistanceSquare(c1, c2);
	if (dist <= (r1 + r2)*(r1 + r2))
	{
		float a = sqrt(dist) - (r1 + r2);
		Vector3d vec(c2 - c1);
		vec.normalize();
		c1 = c1 + vec*a;
		return 1;
	}
	return 0;
}

