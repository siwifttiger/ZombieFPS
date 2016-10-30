#ifndef LEVEL_H
#define LEVEL_H
//#include<windows.h>
#include <SDL/SDL.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <vector>
#include <string>
#include "skybox.h"
#include "vector3d.h"
#include "collisionplane.h"
#include "collision.h"
#include "object.h"
#include "collisionsphere.h"

class map{
	unsigned int mesh;
	std::vector<CollisionPlane> cp;
	std::vector<Vector3d> spawnPoints;
	std::string name;
	skybox* sky;
	public:
	map(unsigned int m,std::vector<CollisionPlane>& cplane,std::string n,std::vector<std::string>& skyImages,std::vector<Vector3d>& sp);
	void update();
	void show();
	std::vector<CollisionPlane>& getCollisionPlanes();
	std::string& getName();
	skybox* getSkybox();
	void change(unsigned int m,std::vector<CollisionPlane>& cplane,std::string n,std::string skyImages[]);
	std::vector<Vector3d>* getSpawnPoints();
	Vector3d* getRandomSpawnPoint();
};
#endif
