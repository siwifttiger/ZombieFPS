#include "level.h"
map::map(unsigned int m,std::vector<CollisionPlane>& cplane,std::string n,std::vector<std::string>& skyImages,std::vector<Vector3d>& sp)
{
	mesh=m;
	cp=cplane;
	name=n;
	sky=new skybox(skyImages[0].c_str(),skyImages[1].c_str(),skyImages[2].c_str(),skyImages[3].c_str(),skyImages[4].c_str(),skyImages[5].c_str());
	spawnPoints=sp;
}
	void map::update()
	{
		//empty
	}
	void map::show()
	{
		glCallList(mesh);
	}
	std::vector<CollisionPlane>& map::getCollisionPlanes()
	{
		return cp;
	}
	std::string& map::getName()
	{
		return name;
	}
	void map::change(unsigned int m,std::vector<CollisionPlane>& cplane,std::string n,std::string skyImages[])
	{
		mesh=m;
		cp=cplane;
		name=n;
		sky->change(skyImages[0].c_str(),skyImages[1].c_str(),skyImages[2].c_str(),skyImages[3].c_str(),skyImages[4].c_str(),skyImages[5].c_str());
	}
	
skybox* map::getSkybox()
{
	return sky;
}

std::vector<Vector3d>* map::getSpawnPoints()
{
	return &spawnPoints;
}

Vector3d* map::getRandomSpawnPoint()
{
	return &(spawnPoints[rand()%spawnPoints.size()]);
}
