#include <iostream>
#include "libUnicornio.h"
//#include "User.h"
#include <stack>
#include <string> 
#include <unordered_map>
#include <algorithm>
#include <map>
#include <string>
#include "Score.h"
#include "InputTexto.h"

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
	bool Exit_m();
	

protected:

	//User logReg;

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
	InputTexto inputMe;
	std::string userName, passWord, userNameC, passWordC;
	std::string uNameLog, passwLog;

	//REGISTER
	typedef std::unordered_map<std::string, std::string> type_map;
	typedef std::unordered_multimap<std::string, std::string> type_multimap;
	typedef std::pair<std::string, std::string> par;

	type_map users;
	par user;
	type_multimap::iterator it_multimap, it_multimap2;
	type_map::iterator it;

	//IN AND OUT.

	std::ofstream reg;
	std::ifstream regIn;
		
};

