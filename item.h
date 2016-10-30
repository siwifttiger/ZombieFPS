#ifndef ITEM_H
#define ITEM_H
//#include<windows.h>
#include <vector>
#include "vector3d.h"
#include <SDL/SDL.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include "collisionsphere.h"
#include "collision.h"

struct oneItem
{
	int id;
	unsigned int mesh;
	Vector3d rotation;
	CollisionSphere cs;
	Vector3d scale;
	oneItem(int& i,unsigned int& m, CollisionSphere c);
};

class item:public Collision{
	std::vector<oneItem> items;
	public:
	item(int i,unsigned int mesh, CollisionSphere& c);
	item();
	int update(CollisionSphere playerloc);
	void show();
	void add(int i,unsigned int mesh, CollisionSphere c);
	void del(int id);
};

#endif
