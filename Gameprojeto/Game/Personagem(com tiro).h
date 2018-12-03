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
	virtual void shot();
	void setSpeed(float speed_);
	float getSpeed();
	Texto Texto_, text;
	std::string TextoTeste = "Trabalho Grau B"; //Optional

protected:
	Vetor2D dir, dir2;
	Sprite spr, spr2, tiro;
	Sprite healthBar_Borda, hB_brilho, hB_Fundo, hB_Points; // HpBar
	float speed;
	//int width, height; //Screen coordinates
	int respawn;
	Resources_Sound Sounds;
	Resources_Sound Theme;
	int direcao, pontuacao, velocidade = 0;
	bool vivo = false;
};
