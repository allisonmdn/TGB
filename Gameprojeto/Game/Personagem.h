#include <iostream>
#include "libUnicornio.h"
#include <time.h>
#include "Resources_Sound.h"  


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
	Texto Texto_, text;
	std::string TextoTeste = "Player 1"; //Optional

protected:
	Vetor2D dir;
	float x, y; //shot
	Sprite spr, spr2, tiro;
	Sprite healthBar_Borda, hB_brilho, hB_Fundo, hB_Points; // HpBar
	float speed;
	int width, height; //Screen coordinates
	int respawn;
	Resources_Sound Sounds;
	Resources_Sound Theme;
	int direcao = 0;
	bool vivo = false;

	
	
};
