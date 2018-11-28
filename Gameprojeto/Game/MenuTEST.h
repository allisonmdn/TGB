#pragma once
#include "libUnicornio.h"

class Jogo
{
public:
	Jogo();
	~Jogo();

	void inicializar();
	void finalizar();

	void executar();

	//Second Page

	BotaoSprite novoJogo;
	BotaoSprite carregarJogo;
	BotaoSprite ranking;
	BotaoSprite creditos;
	BotaoSprite sair;

	// FirstPage

	BotaoSprite cadastrarUsuario;
	BotaoSprite login;
};

/*
novojogo
carregarjogo
ranking
creditos
sair

cadastrarusuario
login*/