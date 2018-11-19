#include "stdafx.h"
#include "Menu.h"


Menu::Menu()
{
}


Menu::~Menu()
{
}
bool Menu::Resume()
{
	menu[0].m_options[0] = "Resume";
	menu[0].m_options_index[0] = 0;
	return true;
}

bool Menu::NewGame()
{
	menu[0].m_options[1] = "New Game";
	menu[0].m_options_index[1] = 0;
	return true;
}
bool Menu::SaveGame()
{
	menu[0].m_options[2] = "Save Game";
	menu[0].m_options_index[2] = 0;
	return true;
}
void Menu::Options()
{
	menu[0].m_options[3] = "Options";
	menu[0].m_options_index[3] = 1;
}

    //Begin Options
void Menu::Sounds() 
{
	menu[1].m_options[0] = "Sounds";
	menu[1].m_options_index[0] = 2;
	menu[2].m_options[0] = "Theme volume";
	menu[2].m_options_index[0] = 5;
	menu[2].m_options[1] = "Effect volume";
	menu[2].m_options_index[1] = 6;
}
void Menu::Graphics()
{
	menu[1].m_options[1] = "Graphics";
	menu[1].m_options_index[1] = 3;
	menu[3].m_options[0] = "Resolution";
	menu[3].m_options_index[0] = 7;
}
void Menu::Controls()
{
	menu[1].m_options[2] = "Controls";
	menu[1].m_options_index[2] = 4;
}
     //End Options

bool Menu::ExitGame()
{
	menu[0].m_options[4] = "Exit Game";
	menu[0].m_options_index[4] = 0;

	return true;
}

void Menu::DrawMenu()
{
	std::cout << "\n";
	std::cout << "Informe uma opcao: ";
	std::cin >> op;
	std::cout << "\n";
	for (int i = 0; i < 5; i++)
	{
		if (m_options[i] != " ")
		{
			std::cout << i << " - " << m_options[i] << "\n";
		}
	}
	pilha_menu.push(&menu[0]); // Insere o menu principal.

	
	if (op == -1)
	{
		if (pilha_menu.top() != &menu[0])  // Top -> referência.
		{
			pilha_menu.pop(); // remove o elemento no top.
			system("cls"); // Limpa
			pilha_menu.top()->DrawMenu(); //Retorna a referência e desenha.
		}
	}
	if (op > 0)	 // Seleção de opções.
	{
		pilha_menu.push(&menu[op]);	//Insere novas opções de menu.
		system("cls");
		pilha_menu.top()->DrawMenu();
	} 	
	
}
