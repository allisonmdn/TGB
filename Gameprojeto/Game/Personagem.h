#include <iostream>
#include "libUnicornio.h"
#include <time.h>

#pragma once
class Personagem: public ObjetoTileMap
{
public:
	Personagem();
	~Personagem();
	void setSpriteSheet(std::string sSheet);	
	void setRespawn();
	virtual void draw();
	virtual void update();
	void setSpeed();
	float getSpeed();
	int respawn;
protected:
	Vetor2D dir;
	Sprite spr;
	float speed;
	int width, height; //Screen coordinates
	 
	
};

