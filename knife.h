#ifndef KNIFE_H
#define KNIFE_H
//#include<windows.h>
#include <GL/gl.h>
#include <SDL/SDL.h>
#include <GL/glu.h>
#include <iostream>
#include <string>
#include <vector>
#include "player.h"
#include "zombie.h"
#include "vector3d.h"
#include "collision.h"
#include <SDL/SDL_mixer.h>

class knife{
	std::vector<unsigned int> frames;
	bool isknifing;
	int strength;
	int delay;
	int wepDelay;
	int lastKnifing;
	int curframe;
	Vector3d loc;
	Mix_Chunk* hitSound;
	Mix_Chunk* notHitSound;
	public:
	knife(std::vector<unsigned int>& f,int str,int del,int wdel,Vector3d location,Mix_Chunk*,Mix_Chunk*);
	int setKnife(Player* p,std::vector<zombie>& zombies);
	void update(Player* p);
	void show();
	bool isKnifing();
	int getStrength();
	void test();
};


#endif
