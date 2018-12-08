#include <iostream>
#include "libUnicornio.h"
#include "Resources_Sound.h" 
#include <ctime>
#include "Personagem.h"


#pragma once
class Personagem2:public ObjetoTileMap
{
public:
	Personagem2();
	~Personagem2();
	void setSpriteSheet(std::string sSprite);
	virtual void update();
	virtual void draw();
	virtual void attack();
	virtual void walk();
	Sprite getShot();
	float getShotX();
	float getShotY();
	int getDir();

	float getX();
	float getY();
	void setSpeed(float speed_);
	float getSpeed();
	Texto text;
	Sprite getSprite();

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

	
	//TEXTS	PROFILE
	Texto lifep, sta;
	Texto Texto_; //Class.
	std::string Hp_v = "HP: ";
	std::string stamina_v = "STA: ";	
	std::string TextoTeste2 = "Player 2";


	//HPMAX and STAMINAMAX
	int healthBar;
	int staminaBar;

protected:
	//MOVIMENT

	float mx, my;
	float tx, ty; //shot 
	float speed = 1;
	int direcao = 0;

	bool vivo = false;

	//SPRITES
	Sprite spr2, tiro2;
	Sprite healthBar_Borda, hB_brilho, hB_Fundo, hB_Points; // HpBar

	int width, height; //Screen coordinates
	int respawn;

	//SOUNDS

	Resources_Sound Sounds;
	

	//ATRIBUTTES

	int strength, vitality, intelligence, agility; // attributes variables.
	int powerUP;
	int atk, atkM; //Atk
	int def, defM;
	int stamina, healthp;

	Personagem tiro;

	


};

