#include <SDL/SDL.h>
#ifndef TEXT_H
#define TEXT_H
//#include<windows.h>
#include <string>
#include <cstring>
#include <iostream>
#include <GL/gl.h>
#include "vector3d.h"
#include "collisionplane.h"
#include <vector>
#include <GL/glu.h>

class text{
	std::vector<unsigned int> characters;
	float width,height;
	bool istest;
	bool islocked;
	Vector3d changepos,changerot,changescale;
	public:
	text(std::vector<unsigned int>& ch,float w,float h);
	void assignFont(std::vector<unsigned int>& ch,float w,float h);
	void drawText(Vector3d pos,Vector3d rot,Vector3d scale,const char* tex);
	void test(Vector3d& pos,Vector3d& rot, Vector3d& scale);
	void setTest(bool b);
};
#endif
