#ifndef ZOMBIE_H
#define ZOMBIE_H
//#include<windows.h>
#include <iostream>
#include <cstdlib>
#include <GL/gl.h>
#include <GL/glu.h>
#include <SDL/SDL.h>
#include "weapon.h"
#include "vector3d.h"
#include "collisionsphere.h"
#include "collisionplane.h"
#include "collision.h"
#include <string>
#include <vector>
#include <cmath>
#include <SDL/SDL_mixer.h>

class zombie : private Collision
{
	static std::vector<unsigned int> frames;
	static unsigned int walk;
	static unsigned int attack;
	static unsigned int die;
	int health;
	float speed;
	int strength;
	Vector3d direction;
	bool isattack;
	bool iswalk;
	CollisionSphere cs;
	Vector3d rotation;
	unsigned int curframe;
	bool isdead;
	
	public:
	zombie(std::vector<unsigned int>& f,unsigned int& w,unsigned int& at,unsigned int& di,int h,float s,int str, CollisionSphere c,Vector3d rot,Vector3d playerloc);
	zombie(int h,float s,int str, CollisionSphere c,Vector3d rot,Vector3d playerloc);
	bool update(std::vector<CollisionPlane>&,Vector3d);
	void show();
	CollisionSphere* getSphere();
	void setLocation(Vector3d& loc);
	bool setAttack(CollisionSphere playerloc);
	void decreaseHealth(int num);
	int getHealth();
	int getStrength();
	bool isDead();
};

#endif
