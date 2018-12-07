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
	cadastrarUsuario.setX(390);
	cadastrarUsuario.setY(550);

	regster.setX(400);
	regster.setY(300);

	login.setX(400);
	login.setY(350);

	//BUTTON LOGIN

	Blogin.setX(700);
	Blogin.setY(500);

	inputMe.inicializar();

	user.first = "";
	user.second = "";
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
	typedef std::unordered_map<std::string, Score> type_map;
	typedef std::unordered_multimap<std::string, Score> type_multimap;
	typedef std::pair<std::string, Score> par;

	type_map users;
	type_multimap score;
	par user;
	type_multimap::iterator it_multimap, it_multimap2;
	type_map::iterator it;



	user.first = "Allison";	 //Account
	user.second.kills = 7;
	user.second.deaths = 5;

	score.insert(user);
	users.insert(user);


	user.first = "Allan";
	user.second.kills = 6;
	user.second.deaths = 4;

	score.insert(user);
	users.insert(user);


	user.first = "Anderson";
	user.second.kills = 5;
	user.second.deaths = 3;

	score.insert(user);
	users.insert(user);


	user.first = "Felipe";
	user.second.kills = 4;
	user.second.deaths = 2;

	score.insert(user);
	users.insert(user);


	user.first = "Flavio";
	user.second.kills = 3;
	user.second.deaths = 1;

	score.insert(user);
	users.insert(user);

	user.first = "Porto";
	user.second.kills = 2;
	user.second.deaths = 0;

	score.insert(user);
	users.insert(user);

	//std::sort(stackScoreKills.begin(), stackScoreKills.end());	//Order
	//std::reverse(stackScoreKills.begin(), stackScoreKills.end()); //Inverse Order


	//std::sort(stackScoreDeaths.begin(), stackScoreDeaths.end());	//Order
	//std::reverse(stackScoreDeaths.begin(), stackScoreDeaths.end()); //Inverse Order


	it_multimap = score.begin();
	it_multimap2 = score.begin();

	std::cout << " ABATES \n\n";


	for (it_multimap; it_multimap != score.end(); it_multimap++)
	{
		std::cout << "Name: " << it_multimap->first << "\nKills: " << it_multimap->second.kills << "\n";
	}

	std::cout << "\n\n MORTES \n\n";

	for (it_multimap2; it_multimap2 != score.end(); it_multimap2++)
	{
		std::cout << "Name: " << it_multimap2->first << "\nDeaths: " << it_multimap2->second.deaths << "\n";
	}
	
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
		Playing, Exit, RETURN

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

		cadastrarUsuario.setX(390);
		cadastrarUsuario.setY(450);

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

			//logReg.Login();
			op = MenuState::RETURN;
			stackMenu.push(RETURN);
			stackMenu.top();

		}

		break;

	case MainMenu:

		//DRAWING MENU

		//BEGIN DRAW

		//New
		gGraficos.desenharRetangulo(0, 0, 0, 800, 600, 0, 0, 0, 0, 0, 255, true);
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

	case REGISTER:

		loginScene.desenhar(400, 300);

		regster.desenhar();//Sprite registro

		cadastrarUsuario.setX(650);
		cadastrarUsuario.setY(520);

		cadastrarUsuario.desenhar();
		cadastrarUsuario.atualizar();

		reg.open("Register.bin", std::ios::binary | std::ios::app);	  //Open

		inputMe.atualizar();
		inputMe.desenhar();

		//logReg.Register();

												  //Account *account = new Account();				

		//user.first = "";

		//user.second = "";



		if (!reg.is_open())
		{
			gDebug.erro("Arquivo de registro não está aberto");
		}
		else
		{

			//inputMe.inicializar(); // Habilitar
			//inputMe.atualizar();
			//inputMe.desenhar();

			gGraficos.desenharTexto(user.first, 400, 300, 0, 0, 0, 255);

			if (gTeclado.pressionou[TECLA_ENTER])
			{

								

				if (user.first.empty()) // Se está vazio user.first insere.
				{
					user.first = inputMe.getTexto().getString();//Account
					inputMe.limparTexto();
					gDebug.depurar("login: ", user.first); //Testa o valor na variável.

				} else if (user.second.empty()) {

					
						user.second = inputMe.getTexto().getString();//Account
						inputMe.limparTexto();
						gDebug.depurar("senha: ", user.second); //Testa o valor na variável.

						users.insert(user);
						reg << user.first;
						reg << user.second;
						inputMe.finalizar();
						
				}
				
				if (cadastrarUsuario.estaClicado())
				{
					op = MenuState::MainMenu_LOG;
					stackMenu.push(op);
					stackMenu.top();

					//REGISTERED
				}

				reg.close();

			}
		

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
	case LOGIN:
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

		gGraficos.desenharRetangulo(150, 70, 0, 500, 450, 0, 0, 0, 0, 0, 128, true);	//DRAWING BACKGROUND OPTION
		text_window.setFonte("fonte2");
		text_window.setString("DEVELOPERS\nAllison Medina\nAnderson Paim\n\nART\nAllison Medina\n\nCODES\nAllison Medina\nAnderson Paim\n\nESPECIALS CREDITS\nSound: Knight Attack\nVinicius Garmentz\nArt: Persons and Tileset\nUnknown Source");
		text_window.setEspacamentoLinhas(1.5);
		text_window.setAlinhamento(TEXTO_CENTRALIZADO);
		text_window.desenhar(400, 300);
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
}


