#include "player.h"

Player::Player(std::string n, CollisionSphere sphere, weapon* defweapon, float speed, float looks, float ss)
{
	weapons.push_back(defweapon);
	name = n;
	cs = sphere;
	health = 500;
	curweapon = 0;
	force.set(0.0, -0.3, 0.0);
	direction.set(0.0, 0.0, 0.0);
	setPosition(Vector3d(0.0, 10, 0));
	cam.setSpeed(speed, looks);
	sprintspeed = ss;
	normalspeed = speed;
	lookspeed = looks;
	energy = 10;
	issprint = false;
	points = 0;
	isWeapon = true;
}

void Player::show()
{
	if (isWeapon)
		weapons[curweapon]->show();
}

void Player::changeWeapon(unsigned int num)
{
	if (num<weapons.size() && num >= 0)
		curweapon = num;
}

void Player::changeWeaponUp()
{
	curweapon++;
	if (curweapon >= weapons.size())
		curweapon = 0;
	std::cout << curweapon << std::endl;
}

void Player::changeWeaponDown()
{
	curweapon--;
	if (curweapon<0)
		curweapon = weapons.size() - 1;
	std::cout << curweapon << std::endl;
}

void Player::jump()
{
	if (isground)
	{
		isground = false;
		direction.set(0.0, 2, 0.0);
	}
}

CollisionSphere Player::getCollisionSphere()
{
	return cs;
}

std::string Player::getName()
{
	return name;
}

void Player::setPosition(Vector3d pos)
{
	cs.setCenter(pos);
	cam.setLocation(pos);
}

void Player::update(std::vector<CollisionPlane>& cp)
{
	if (direction.y >= force.y)
		direction += force;
	//	std::cout << direction;
	Vector3d newpos(cam.getLocation());
	newpos += direction;
	Vector3d tmp(newpos);
	for (int i = 0;i<cp.size();i++)
		spherePlane(newpos, cp[i].normal, cp[i].p[0], cp[i].p[1], cp[i].p[2], cp[i].p[3], cs.r);
	//std::cout << "\n" << newpos;
	if (newpos.y>tmp.y)
		isground = true;
	setPosition(newpos);
	weapons[curweapon]->update();
	if (energy<10 && !issprint)
		energy += 0.01;
	if (issprint)
		energy -= 0.05;
	if (energy <= 0)
		setSprint(false);
	std::cout << curweapon << std::endl;
}

void Player::addWeapon(weapon* w)
{
	weapons.push_back(w);
}

Camera* Player::getCamera()
{
	return &cam;
}

void Player::decreaseHealth(int num)
{
	health -= num;
}

int Player::getHealth()
{
	return health;
}


weapon* Player::getCurWeapon()
{
	return weapons[curweapon];
}

void Player::setHealth(int h)
{
	health = h;
}


void Player::addHealth(int h)
{
	health += h;
}

void Player::setSprint(bool b)
{
	if (energy>3)
	{
		if (b && !weapons[curweapon]->isaimed())
		{
			issprint = true;
			cam.setSpeed(sprintspeed, lookspeed);
		}
		else {
			issprint = b;
			cam.setSpeed(normalspeed, lookspeed);
		}
	}
	else {
		issprint = false;
		cam.setSpeed(normalspeed, lookspeed);
	}
}

bool Player::isSprinting()
{
	return issprint;
}

void Player::addPoints(int num)
{
	points += num;
}

int Player::getPoints()
{
	return points;
}

int Player::getNumWeapons()
{
	return weapons.size();
}

void Player::holdWeapon(bool b)
{
	isWeapon = b;
}
