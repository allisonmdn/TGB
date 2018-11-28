#include "Jogo.h"

Jogo::Jogo()
{
}

Jogo::~Jogo()
{
}

void Jogo::inicializar()
{
	uniInicializar(800, 600, false);

	//Loading

	gRecursos.carregarSpriteSheet("NovoJogo", "assets/spritesheets/NovoJogo.png", 2, 1);
	gRecursos.carregarSpriteSheet("CarregarJogo", "assets/spritesheets/CarregarJogo.png", 2, 1);
	gRecursos.carregarSpriteSheet("ExibirRanking", "assets/spritesheets/ExibirRanking.png", 2, 1);
	gRecursos.carregarSpriteSheet("Creditos", "assets/spritesheets/Creditos.png", 2, 1);
	gRecursos.carregarSpriteSheet("Sair", "assets/spritesheets/Sair.png", 2, 1);
	gRecursos.carregarSpriteSheet("CadastrarUsuario", "assets/spritesheets/CadastrarUsuario.png", 2, 1);
	gRecursos.carregarSpriteSheet("Login", "assets/spritesheets/Login.png", 1, 1);

	//Instance

	novoJogo.setSpriteSheet("NovoJogo");
	carregarJogo.setSpriteSheet("CarregarJogo");
	ranking.setSpriteSheet("ExibirRanking");
	creditos.setSpriteSheet("Creditos");
	sair.setSpriteSheet("Sair");
	cadastrarUsuario.setSpriteSheet("CadastrarUsuario");
	login.setSpriteSheet("Login");

	//SetPos
	novoJogo.setX(0);
	novoJogo.setY(500);
	carregarJogo.setX(0);
	carregarJogo.setY(400);
	ranking.setX(0);
	ranking.setY(300);
	creditos.setX(0);
	creditos.setY(200);
	sair.setX(0);
	sair.setY(100);

	//COORDINATES OK.

	//First Window]
	cadastrarUsuario.setX(383);
	cadastrarUsuario.setY(450);
	login.setX(400);
	login.setY(350);



	//	O resto da inicialização vem aqui!
	//	...
}

void Jogo::finalizar()
{
	//	O resto da finalização vem aqui (provavelmente, em ordem inversa a inicialização)!
	//	...

	uniFinalizar();
}

void Jogo::executar()
{
	while (!gTeclado.soltou[TECLA_ESC] && !gEventos.sair)
	{
		uniIniciarFrame();
		/*
		novoJogo.desenhar();
		carregarJogo.desenhar();
		ranking.desenhar();
		creditos.desenhar();
		sair.desenhar();*/
		login.desenhar();
		cadastrarUsuario.atualizar();
		cadastrarUsuario.desenhar();

		if (cadastrarUsuario.estaClicado())
		{

			gJanela.setCorDeFundo(0, 0, 0);

		}



		//	Seu código vem aqui!
		//	...

		uniTerminarFrame();
	}
}