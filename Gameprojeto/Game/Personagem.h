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
	void setSpriteSheet(std::string sSprite);
	virtual void draw();
	virtual void update();
	virtual void attack();
	virtual void walk();
	float getX();
	float getY();
	Sprite getShot();
	float getShotX();
	float getShotY();
	int getDir();

	void setSpeed(float speed_);
	float getSpeed();	
	Texto text;
	Sprite getSprite();
	//ATRIBUTTES

	void attributes();
	void DamageTaken();
	void sethpMax(int hPMax);
	void setStamina(int stamina_);
	void sethP(int healthp_);
	void setStaminaMax(int StaMax);
	int gethpMax();
	int getHp();
	int getStaminaMax();
	int getStamina();
	int getStrength();
	int getAgility();
	int getVitality();
	int getIntelligence();
	

	//HPMAX and STAMINAMAX
	int healthBar;
	int staminaBar;

	//TEXTS	PROFILE
	Texto lifep, sta;
	Texto Texto_; //Class.
	std::string Hp_v = "HP: ";
	std::string stamina_v = "STA: ";
	std::string TextoTeste = "Player 1";

protected:
	//MOVIMENT

	float mx, my;
	float x, y; //shot 
	float speed = 1;
	int direcao = 0;

	bool vivo = false;

	//SPRITES
	Sprite spr, tiro;
	Sprite healthBar_Borda, hB_brilho, hB_Fundo, hB_Points; // HpBar
	
	int width, height; //Screen coordinates
	int respawn;

	//SOUNDS

	Resources_Sound Sounds;
	Resources_Sound Theme;

	//ATRIBUTTES

	int strength, vitality, intelligence, agility; // attributes variables.
	int powerUP;
	int atk, atkM; //Atk
	int def, defM;
	int stamina, healthp;
	
	

	
	
};
