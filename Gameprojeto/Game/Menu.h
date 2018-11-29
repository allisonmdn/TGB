#include <iostream>
#include "libUnicornio.h"
#include <stack>
#include <string>
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

	BotaoSprite novoJogo;
	BotaoSprite carregarJogo;
	BotaoSprite ranking;
	BotaoSprite creditos;
	BotaoSprite sair;
	BotaoSprite voltar;
	BotaoSprite regster;
	BotaoSprite Blogin;

	// First Page

	BotaoSprite cadastrarUsuario;
	BotaoSprite login;
	Sprite loginScene;
	int op = 0;
	int sizeStack; // Size of stack
	bool ext = false;

	std::stack<int> stackMenu;
};

