#include "Menu.h"



Menu::Menu()
{
			
}


Menu::~Menu()
{
}

void Menu::LoadMenu()
{
	//Loading

	gRecursos.carregarSpriteSheet("NovoJogo", "assets/spritesheets/Button/NovoJogo.png", 2, 1);
	gRecursos.carregarSpriteSheet("CarregarJogo", "assets/spritesheets/Button/CarregarJogo.png", 2, 1);
	gRecursos.carregarSpriteSheet("ExibirRanking", "assets/spritesheets/Button/ExibirRanking.png", 2, 1);
	gRecursos.carregarSpriteSheet("Creditos", "assets/spritesheets/Button/Creditos.png", 2, 1);
	gRecursos.carregarSpriteSheet("Sair", "assets/spritesheets/Button/Sair.png", 2, 1);
	gRecursos.carregarSpriteSheet("CadastrarUsuario", "assets/spritesheets/Button/CadastrarUsuario.png", 2, 1);
	gRecursos.carregarSpriteSheet("Login", "assets/spritesheets/Button/Login.png", 1, 1);
	gRecursos.carregarSpriteSheet("LoginScene", "assets/spritesheets/BackgroundLogin/LoginScene.png", 1, 1);
	gRecursos.carregarSpriteSheet("Bvoltar", "assets/spritesheets/Button/Bvoltar.png", 2, 1);
	gRecursos.carregarSpriteSheet("Blogin", "assets/spritesheets/Button/Blogin.png", 2, 1);
	gRecursos.carregarSpriteSheet("RegistrarA", "assets/spritesheets/Button/RegistrarA.png", 1, 1);


	//Instance

	novoJogo.setSpriteSheet("NovoJogo");
	carregarJogo.setSpriteSheet("CarregarJogo");
	ranking.setSpriteSheet("ExibirRanking");
	creditos.setSpriteSheet("Creditos");
	sair.setSpriteSheet("Sair");
	cadastrarUsuario.setSpriteSheet("CadastrarUsuario");
	voltar.setSpriteSheet("Bvoltar");
	Blogin.setSpriteSheet("Blogin");
	login.setSpriteSheet("Login");
	loginScene.setSpriteSheet("LoginScene");
	regster.setSpriteSheet("RegistrarA");


	//SetPos

	novoJogo.setX(400);
	novoJogo.setY(100);

	carregarJogo.setX(400);
	carregarJogo.setY(200);

	ranking.setX(400);
	ranking.setY(300);

	creditos.setX(400);
	creditos.setY(400);

	sair.setX(400);
	sair.setY(500);

	voltar.setX(100);
	voltar.setY(550);

	//COORDINATES OK.

	//First Window]
	cadastrarUsuario.setX(383);
	cadastrarUsuario.setY(450);

	regster.setX(400);
	regster.setY(350);

	login.setX(400);
	login.setY(350);

	//BUTTON LOGIN

	Blogin.setX(700);
	Blogin.setY(500);
}



void Menu::FirstWindow()
{
	
}

void Menu::newGame_m()
{

}

void Menu::loadGame_m()
{
	
}

void Menu::ranking_m()
{
	
}

void Menu::credits_m()
{
	

}

void Menu::options_m()
{
}
bool Menu::Exit_m()
{
	if (sair.estaClicado())
	{
		ext = true;
	}

	return ext;
}
void Menu::updateMenu()
{
	enum MenuState
	{
		MainMenu_LOG, MainMenu, NEW_G, LOAD_G, RANKING, CREDITS, REGISTER, LOGIN,
		Playing, Options, Exit, RETURN

	};

	this->stackMenu.push(MainMenu_LOG);
	this->stackMenu.push(MainMenu);

	//FIRST STACK SIZE
	sizeStack = stackMenu.size();

	switch (op)
	{
	case MainMenu_LOG:

		loginScene.desenhar(400, 300);

		login.desenhar();
		login.atualizar();

		cadastrarUsuario.desenhar();
		cadastrarUsuario.atualizar();

		if (cadastrarUsuario.estaClicado())
		{
			op = MenuState::REGISTER;
			stackMenu.push(REGISTER);
			stackMenu.top();

		}

		Blogin.desenhar();
		Blogin.atualizar();

		if (Blogin.estaClicado())
		{
			op = MenuState::RETURN;
			stackMenu.push(RETURN);
			stackMenu.top();
		}

		break;

	case MainMenu:

		//DRAWING MENU

		//BEGIN DRAW

		//New

		novoJogo.desenhar();
		novoJogo.atualizar();
		//Load

		carregarJogo.desenhar();
		carregarJogo.atualizar();
		//Ranking

		ranking.desenhar();
		ranking.atualizar();
		//Credits

		creditos.desenhar();
		creditos.atualizar();

		//Exit

		sair.desenhar();
		sair.atualizar();

		//END DRAW

		//CLICK BUTTON CONDITIONS

		//BEGIN

		if (novoJogo.estaClicado())
		{
			op = MenuState::NEW_G;
			stackMenu.top() = op;
		}
		if (carregarJogo.estaClicado())
		{
			op = MenuState::LOAD_G;
			stackMenu.top() = op;
		}
		if (ranking.estaClicado())
		{
			op = MenuState::RANKING;
			stackMenu.top() = op;
		}
		if (creditos.estaClicado())
		{
			op = MenuState::CREDITS;
			stackMenu.top() = op;
		}
		if (sair.estaClicado())
		{
			op = MenuState::Exit;
			stackMenu.top() = op;
		}

		//END

		break;
	case NEW_G:
		for (int i = sizeStack; 0 < i; i--)
		{
			stackMenu.pop();
		}

		//RETURN
		if (voltar.estaClicado())
		{
			op = MenuState::RETURN;
			stackMenu.push(RETURN);
			stackMenu.top();
		}

		stackMenu.push(NEW_G);
		stackMenu.top();

		voltar.desenhar();
		voltar.atualizar();

		break;
	case LOAD_G:
		for (int i = sizeStack; 0 < i; i--)
		{
			stackMenu.pop();
		}
		//RETURN
		if (voltar.estaClicado())
		{
			op = MenuState::RETURN;
			stackMenu.push(RETURN);
			stackMenu.top();
		}

		stackMenu.push(LOAD_G);
		stackMenu.top();

		voltar.desenhar();
		voltar.atualizar();
		break;
	case RANKING:
		for (int i = sizeStack; 0 < i; i--)
		{
			stackMenu.pop();
		}
		//RETURN
		if (voltar.estaClicado())
		{
			op = MenuState::RETURN;
			stackMenu.push(RETURN);
			stackMenu.top();
		}

		stackMenu.push(RANKING);
		stackMenu.top();

		voltar.desenhar();
		voltar.atualizar();
		break;
	case CREDITS:
		for (int i = sizeStack; 0 < i; i--)
		{
			stackMenu.pop();
		}
		//RETURN
		if (voltar.estaClicado())
		{
			op = MenuState::RETURN;
			stackMenu.push(RETURN);
			stackMenu.top();
		}

		stackMenu.push(CREDITS);
		stackMenu.top();

		voltar.desenhar();
		voltar.atualizar();
		break;
	case Playing:

		sizeStack = stackMenu.size();

		for (int i = sizeStack; 0 < i; i--)
		{
			stackMenu.pop();
		}

		stackMenu.push(Playing);
		stackMenu.top();

		voltar.desenhar();
		voltar.atualizar();

		break;
	case Options:

		sizeStack = stackMenu.size();

		for (int i = sizeStack; 0 < i; i--)
		{
			stackMenu.pop();
		}
		//RETURN
		if (voltar.estaClicado())
		{
			op = MenuState::RETURN;
			stackMenu.push(RETURN);
			stackMenu.top();
		}

		stackMenu.push(Options);
		stackMenu.top();

		break;
	case REGISTER:

		loginScene.desenhar(400, 300);
		regster.desenhar();

		voltar.desenhar();
		voltar.atualizar();
		//RETURN
		if (voltar.estaClicado())
		{
			op = MenuState::MainMenu_LOG;
			stackMenu.push(op);
			stackMenu.top();
		}

		break;
	case RETURN:
		op = MainMenu;
		stackMenu.push(op);

		stackMenu.top();
		break;
	case Exit:
		Menu::Exit_m();
		break;
	}

}


