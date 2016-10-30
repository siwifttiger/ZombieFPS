#ifndef OBJECT_H
#define OBJECT_H
//#include<windows.h>
#include <SDL/SDL.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <vector>
#include <cstdlib>
#include "vector3d.h"
#include "collisionplane.h"
class OneObject{
	std::vector<unsigned int> frames;
	std::vector<CollisionPlane> cp;
	std::string name;
	int id;
	public:
	OneObject(std::vector<unsigned int>& f,std::vector<CollisionPlane>& c,std::string n,int i);
	std::string& getName();
	int getId();
};

struct ObjectPos{
	int id;
	Vector3d pos;
	ObjectPos(int i,Vector3d p) : id(i),pos(p){};
};

class Object{
	std::vector<OneObject> obj;
	std::vector<ObjectPos> objects;
	public:
	Object();
	void add(std::vector<unsigned int>& f,std::vector<CollisionPlane>& c,Vector3d& p,std::string n,int i);
	void add(int id,Vector3d pos);
	void add(std::string name,Vector3d pos);
	bool del(int id);
	bool del(std::string name);
};

#endif
