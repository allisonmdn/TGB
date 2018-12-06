#include <iostream>
#include "Personagem.h"
#include "Personagem2.h"
//#include "LoadingResources.h"
#include "libUnicornio.h"
#include "Resources_Sound.h"
#include "ObjetoTileMap.h"
#include "Menu.h"
#include "Knight.h"
#include "Mage.h"
#include "Thief.h"
#include "Knight2.h"
#include "Mage2.h"
#include "Thief2.h"


#pragma once
class Jogo

{
public:
	Jogo();
	~Jogo();

	void inicializar();
	void finalizar();
	void executar();
	void Collisions();
	bool Collision_Treasure();
	int sChar();
	
private:
	Personagem * P1[3], TX;
	Personagem2 * P2[3],TX2;
	TileMap mapa, mapa2;
	//fstream inORout;
	//ofstream outs;
	//ifstream ins;
	Sprite treasure;
	BotaoSprite Btn;
	Resources_Sound LoadS;
	Menu menuz;
	int width = 800;
	int height = 600;
	int t_x = 0; //Variable "x" and "y" to randomly respawn TREASURE BOX
	int t_y = 0;	
	int x_char = 0;
	int time;
	
	
	
	
	
};
