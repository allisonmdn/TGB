#include <iostream>
#include "libUnicornio.h"
#include <time.h>
#include "Resources_Sound.h"

#pragma once
class Personagem: public ObjetoTileMap
{
public:
	Personagem();
	~Personagem();
	void setSpriteSheet(std::string sSheet);	
	virtual void draw();
	virtual void update();
	//void setSpeed();
	//float getSpeed();
	
protected:
	Vetor2D dir;
	Sprite spr;
	//float speed;
	//int width, height; //Screen coordinates
	int respawn;
	Resources_Sound Sounds;
	Resources_Sound Theme;
};

