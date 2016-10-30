#ifndef WEAPON_H
#define WEAPON_H
//#include<windows.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <vector>
#include <iostream>
#include <fstream>
#include <SDL/SDL.h>
#include <SDL/SDL_mixer.h>
#include <cstdlib>
#include <ctime>
#include "vector3d.h"
#include "camera.h"

class weapon {
	std::vector<unsigned int> frames;
	unsigned int outerview;
	unsigned int normalanimation;	//2,3,4
	unsigned int fireanimation;	//0,1
	unsigned int reloadanimation;	//2,3,4
	Mix_Chunk *firesound;					//5,6,7,8
	Mix_Chunk *reloadsound;
	Mix_Chunk *normalsound;		//not used
	Mix_Chunk *emptysound;
	Vector3d curpos;
	Vector3d currot;
	Vector3d position;
	Vector3d rotation;
	Vector3d curPos;
	Vector3d curRot;

	Vector3d aimposition;
	Vector3d aimrotation;
	float precision;
	float aimprecision;
	int strength;
	bool isaim;
	bool isreloading;
	bool isautomatic;
	bool isfired;
	bool istest;
	unsigned int numbullets;
	float length;							//not used
	unsigned int speed;
	unsigned int curframe;
	unsigned int curmode;
	unsigned int lastshot;
	unsigned int bullets;
	unsigned int allbullets;
	std::string name;
public:
	weapon(std::vector<unsigned int>& anim, unsigned int na, unsigned int fa, unsigned int ra, Mix_Chunk *fs, Mix_Chunk* rs, Mix_Chunk* ns, Mix_Chunk* es, Vector3d pos, Vector3d rot, Vector3d apos, Vector3d arot, float prec, float aprec, unsigned int numb, float length, unsigned int sp, bool isauto, int strength, const char* name, unsigned int);
	void aim();
	bool fire(Vector3d& direction, Vector3d& startpoint, Vector3d& camdirection);
	void nofire();
	bool reload();
	void update();
	void show();
	void test();
	void addBullets(unsigned int num);
	void setBullets(unsigned int num);
	int getStrength();
	int getAmmo();
	int getAllAmmo();
	std::string& getName();
	std::vector<unsigned int>& getAnimation();
	bool isaimed();
	unsigned int getOuterView();
};

#endif
