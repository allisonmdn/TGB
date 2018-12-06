#include <iostream>
#include "libUnicornio.h"
#include "User.h"
#include <stack>
#include <string> 
#include <unordered_map>
#include <algorithm>
#include <map>
#include <string>
#include "Score.h"
#pragma once
class Menu
{
public:
	Menu();
	~Menu();

	void updateMenu();
	void LoadMenu();
	void FirstWindow();
	void newGame_m();
	void loadGame_m();
	void ranking_m();
	void credits_m();
	void options_m();
	bool Exit_m();
	

protected:

	User logReg;

	BotaoSprite novoJogo;
	BotaoSprite carregarJogo;
	BotaoSprite ranking;
	BotaoSprite creditos;
	BotaoSprite sair;
	BotaoSprite voltar;
	BotaoSprite regster;
	BotaoSprite Blogin;

	// First Page
	Texto text_window, text_back;
	BotaoSprite cadastrarUsuario;
	BotaoSprite login;
	Sprite loginScene;
	int op = 0;
	int sizeStack; // Size of stack
	bool ext = false; 	
	std::stack<int> stackMenu;
		
};

