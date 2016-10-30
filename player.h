#ifndef PLAYER_H
#define PLAYER_H
//#include<windows.h>
#include <iostream>
#include <cstdlib>
#include "weapon.h"
#include "vector3d.h"
#include "collisionsphere.h"
#include "collision.h"
#include "collisionplane.h"
#include <string>
#include <vector>
#include <GL/gl.h>
#include <GL/glu.h>
#include <SDL/SDL.h>

class Player :private Collision {
	std::vector<weapon*> weapons;
	std::string name;
	CollisionSphere cs;
	int health;
	int curweapon;
	Vector3d force;
	Vector3d direction;
	bool isground;
	bool iscollision;
	float sprintspeed;
	float normalspeed;
	float lookspeed;
	bool issprint;
	float energy;
	int points;
	bool isWeapon;
public:
	Camera cam;
	Player(std::string n, CollisionSphere sphere, weapon* defweapon, float, float, float);
	void update(std::vector<CollisionPlane>& cp);
	void show();
	void changeWeapon(unsigned int num);
	void changeWeaponUp();
	void changeWeaponDown();
	void jump();
	CollisionSphere getCollisionSphere();
	std::string getName();
	Camera* getCamera();
	void setPosition(Vector3d pos);
	void addWeapon(weapon* w);
	weapon* getCurWeapon();
	void decreaseHealth(int num);
	int getHealth();
	void setHealth(int h);
	void addHealth(int h);
	void setSprint(bool b);
	bool isSprinting();
	void addPoints(int num);
	int getPoints();
	int getNumWeapons();
	void holdWeapon(bool);
};
#endif
