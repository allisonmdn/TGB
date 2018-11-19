#include <string>
#include <iostream>
#include <stack>
#include <array>
#pragma once
class Menu
{
public:
	Menu();
	~Menu();
	bool Resume();
	bool NewGame();
	bool SaveGame();
	void Options();	 // Opções gerais.
	void Sounds();	 // Config sons.
	void Graphics();  // Resolução de telas, entre outros.
	void Controls();  // Controles
	bool ExitGame();
	void DrawMenu();


protected:
	std::array<Menu, 4> menu;
	std::string m_options[5];
	int m_options_index[5];
	std::stack <Menu*> pilha_menu;
	int op;
	
};

