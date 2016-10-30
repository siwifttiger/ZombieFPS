#ifndef CAMERA_H
#define CAMERA_H
//#include<windows.h>  
#include <GL/gl.h>
#include <GL/glu.h>
#include <SDL/SDL.h>

#include <cmath>
#include <iostream>
#include "vector3d.h"

#define M_PI 3.1415926


class Camera
{
	Vector3d loc;   //ÉãÏñ»úÎ»ÖÃ
	float camYaw;   //ÈÆYÖáÐý×ª
	float camPitch;  //ÈÆXÖáÐý×ª
	float speed;     // W A D S
	float mousespeed;  //Êó±ê
	bool mi;
	void lockCamera();
	void moveCamera(const float& dir);
	void moveCameraUp(const float& dir);
public:
	Camera();
	Camera(const Vector3d& loc);
	Camera(const Vector3d& loc, const float& yaw, const float& pitch);
	Camera(const Vector3d& loc, const float& yaw, const float& pitch, const float& sp, const float& ms);
	void control();
	void update();
	Vector3d getVector();
	Vector3d getLocation();
	float getYaw();
	float getPitch();
	void setLocation(const Vector3d& newcoord);
	void lookAt(const float& y, const float& p);
	void mouseIn();
	void mouseOut();
	bool IsMouseIn();
	void setSpeed(float sp, float ms);
};


#endif

