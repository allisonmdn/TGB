#include <iostream>
#include "libUnicornio.h"
#include <time.h>
#include "Resources_Sound.h"
#include "PersonStatus.h"


#pragma once
class Personagem : public ObjetoTileMap
{
public:
	Personagem();
	~Personagem();
	void setSpriteSheet(std::string sSheet);
	virtual void draw();
	virtual void update();
	virtual void attack();
	virtual void walk();
	float getX();
	float getY();
	void setSpeed(float speed_);
	float getSpeed();	
	Texto text;

protected:
	//MOVIMENT

	Vetor2D dir;
	float x, y; //shot 
	float speed;
	int direcao = 0;

	bool vivo = false;

	//SPRITES
	Sprite spr, spr2, tiro;
	Sprite healthBar_Borda, hB_brilho, hB_Fundo, hB_Points; // HpBar
	
	int width, height; //Screen coordinates
	int respawn;

	//SOUNDS

	Resources_Sound Sounds;
	Resources_Sound Theme;

	//STATUS PERSON

	PersonStatus pStatus;
	
	

	
	
};
