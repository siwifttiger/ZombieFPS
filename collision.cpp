#include"collision.h"

//�ⷽ�̣��ж�ֱ�ߺ�������û�н���
bool Collision::raySphere(float xc, float yc, float zc, float xd, float yd, float zd, float xs, float ys, float zs, float r, float* dist, Vector3d* collpoint)
{
	float b = 2 * (xd*(xs - xc) + yd*(ys - yc) + zd*(zs - zc));
	float c = xs*xs - 2 * xs*xc + xc*xc + ys*ys - 2 * ys*yc + yc*yc + zs*zs - 2 * zs*zc + zc*zc - r*r;
	float disc = (b*b - 4 * c);
	if (disc < 0)	//С��0 ��û�н���
		return false;
	else {
		if (dist != NULL)  //dist �൱�ڵ�λʱ��t
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


//���������ε����,���׹�ʽ
float Collision::triangleArea(Vector3d p1, Vector3d p2, Vector3d p3)
{
	
	float a = sqrt((p2.x - p1.x)*(p2.x - p1.x) + (p2.y - p1.y)*(p2.y - p1.y) + (p2.z - p1.z)*(p2.z - p1.z));
	float b = sqrt((p3.x - p2.x)*(p3.x - p2.x) + (p3.y - p2.y)*(p3.y - p2.y) + (p3.z - p2.z)*(p3.z - p2.z));
	float c = sqrt((p1.x - p3.x)*(p1.x - p3.x) + (p1.y - p3.y)*(p1.y - p3.y) + (p1.z - p3.z)*(p1.z - p3.z));
	float s = (a + b + c) / 2.;
	return (sqrt(s*((s - a)*(s - b)*(s - c))));
}

//�������
float Collision::pointDistance(Vector3d p1, Vector3d p2)
{
	Vector3d vec(p2.x - p1.x, p2.y - p1.y, p2.z - p1.z);
	return (sqrt(vec.x*vec.x + vec.y*vec.y + vec.z*vec.z));
}
//��������ƽ��
float Collision::pointDistanceSquare(Vector3d p1, Vector3d p2)
{
	Vector3d vec(p2.x - p1.x, p2.y - p1.y, p2.z - p1.z);
	return (vec.x*vec.x + vec.y*vec.y + vec.z*vec.z);
}

//�߶κ�ƽ����ཻ���
//����ƽ�������޴�ģ����Ի���Ҫ��һ���ļ��
//���������ε�������жϵ��Ƿ����������һ�������ڲ�
bool Collision::rayPlane(const float& nx, float ny, float nz, float x0, float y0, float z0, float xs, float ys, float zs, float xd, float yd, float zd, Vector3d p1, Vector3d p2, Vector3d p3, Vector3d p4, float* dis, Vector3d* point)
{
	if ((xd*nx + yd*ny + zd*nz) == 0)	//���Ϊ0��ֱ�ߺ�ƽ��ƽ��
	{
		return false;
	}
	float t = ((x0*nx + y0*ny + z0*nz - nx*xs - ny*ys - nz*zs) / (xd*nx + yd*ny + zd*nz));
	if (t<0)	//t < 0 ˵���������෴�ķ���
	{
		return false;
	}
	float x = xs + t*xd;	
	float y = ys + t*yd;
	float z = zs + t*zd;
	Vector3d i(x, y, z);
	//�жϽ����Ƿ��������ָ��������
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
//�����ƽ����ཻ���
//spΪԲ������
//��Բ�ķ���һ�����ߣ�������������Ƿ���ƽ���ཻ��ͨ���ཻ�������ж������Ƿ���ƽ���ཻ
bool Collision::spherePlane(Vector3d& sp, Vector3d pn, Vector3d p1, Vector3d p2, Vector3d p3, Vector3d p4, float r)
{
	float dist1 = 0, dist2 = 0;
	//����������������
	if (rayPlane(pn.x, pn.y, pn.z, p1.x, p1.y, p1.z, sp.x, sp.y, sp.z, -pn.x, -pn.y, -pn.z, p1, p2, p3, p4, &dist1) || rayPlane(-pn.x, -pn.y, -pn.z, p1.x, p1.y, p1.z, sp.x, sp.y, sp.z, pn.x, pn.y, pn.z, p1, p2, p3, p4, &dist2))
	{
		if (dist1>r || dist2>r)   //�������r��˵�����ཻ
		{
			return false;
		}
		if (dist1>0)	//dist11
		{
			//��Ҫǡ�ò��ཻ���µ�Բ�ĵ�����
			sp.x = sp.x + pn.x*(r - dist1);	
			sp.y = sp.y + pn.y*(r - dist1);
			sp.z = sp.z + pn.z*(r - dist1);
		}
		else	
		{
			//ͬ��
			sp.x = sp.x - pn.x*(r - dist2);
			sp.y = sp.y - pn.y*(r - dist2);
			sp.z = sp.z - pn.z*(r - dist2);
		}

		return true;
	}
	//�����ཻ
	return false;
}


//�����������ཻ���
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

