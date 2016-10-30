#include "camera.h"

Camera::Camera()
{
	loc.x = 0.0f;
	loc.y = 0.0f;
	loc.z = 0.0f;
	camYaw = 0.0f;
	camPitch = 0.0f;
	speed = 0.2f;
	mousespeed = 0.05f;
	mi = false;
}
Camera::Camera(const Vector3d& l)
{
	loc = l;
	camYaw = 0.0;
	camPitch = 0.0;
	speed = 0.3f;
	mousespeed = 0.3f;
	mi = false;
}
Camera::Camera(const Vector3d& l, const float& yaw, const float& pitch)
{
	loc = l;
	camYaw = yaw;
	camPitch = pitch;
	speed = 0.3f;
	mousespeed = 0.3f;
	mi = false;
}
Camera::Camera(const Vector3d& l, const float& yaw, const float& pitch, const float& sp, const float& ms)
{
	loc = l;
	camYaw = yaw;
	camPitch = pitch;
	speed = sp;
	mousespeed = ms;
	mi = false;
}


void Camera::lockCamera()
{
	if (camPitch>90)
		camPitch = 90;
	if (camPitch<-90)
		camPitch = -90;
	if (camYaw<0.0)
		camYaw += 360.0;
	if (camYaw>360.0)
		camYaw -= 360;
}

void Camera::moveCamera(const float &dir)
{
	float rad = (camYaw + dir)*M_PI / 180.0;
	loc.x -= sin(rad)*speed;
	loc.z -= cos(rad)*speed;
}

void Camera::moveCameraUp(const float& dir)
{
	float rad = (camPitch + dir)*M_PI / 180.0;
	loc.y += sin(rad)*speed;
}

void Camera::control()
{
	if (mi)
	{

		int MidX = 320;
		int MidY = 240;
		SDL_ShowCursor(SDL_DISABLE);
		int tmpx, tmpy;   //鼠标移动的位置
		SDL_GetMouseState(&tmpx, &tmpy);
		camYaw += mousespeed*(MidX - tmpx);
		camPitch += mousespeed*(MidY - tmpy);
		lockCamera();
		SDL_WarpMouse(MidX, MidY);
		Uint8* state = SDL_GetKeyState(NULL);
		//不是 free camera 所以 Y值不变 只需改变 X 和 Y的值
		if (state[SDLK_w])
		{
			moveCamera(0.0);
		}
		else if (state[SDLK_s])
		{
			moveCamera(180.0);
		}
		if (state[SDLK_a])
			moveCamera(90.0);
		else if (state[SDLK_d])
			moveCamera(270);
	}

	glRotatef(-camPitch, 1.0, 0.0, 0.0);
	glRotatef(-camYaw, 0.0, 1.0, 0.0);
}

void Camera::update()
{
	glTranslatef(-loc.x, -loc.y, -loc.z);
}

Vector3d Camera::getLocation()
{
	return loc;
}

float Camera::getYaw()
{
	return camYaw;
}
float Camera::getPitch()
{
	return camPitch;
}

void Camera::setLocation(const Vector3d& newcoord)
{
	loc = newcoord;
}

void Camera::lookAt(const float& y, const float& p)
{
	camYaw = y;
	camPitch = p;
}

void Camera::mouseIn()
{
	mi = true;
}

void Camera::mouseOut()
{
	mi = false;
}

Vector3d Camera::getVector()
{
	return (Vector3d(-cos(camPitch*M_PI / 180.0)*sin(camYaw*M_PI / 180.0), sin(camPitch*M_PI / 180.0), -cos(camPitch*M_PI / 180.0)*cos(camYaw*M_PI / 180.0)));
}

bool Camera::IsMouseIn()
{
	return mi;
}


void Camera::setSpeed(float sp, float ms)
{
	speed = sp;
	mousespeed = ms;
}
