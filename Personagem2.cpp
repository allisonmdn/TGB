#include "Personagem2.h"



Personagem2::Personagem2()
{
	Personagem::Personagem();
}


Personagem2::~Personagem2()
{
	Personagem::~Personagem();
}
bool Personagem2::walk()
{
	//Walk True

	if (gTeclado.segurando[TECLA_DIR])
	{
		//Right
		dir.x += 1;
		spr.setAnimacao(2, false);
		//x + 1;
	}
	else if (gTeclado.segurando[TECLA_ESQ])
	{
		//Left
		dir.x -= 1;
		spr.setAnimacao(1, false);
		//x - 1;
	}
	else if (gTeclado.segurando[TECLA_CIMA])
	{
		//Up
		dir.y -= 1;
		spr.setAnimacao(3, false);
		//y - 1;
	}
	else if (gTeclado.segurando[TECLA_BAIXO])
	{
		//Down		
		dir.y += 1;
		spr.setAnimacao(0, false);
		//y + 1;  
	}
	//Walk false.
	else
	{
		this->dir.set(dir.x, dir.y);
		spr.recomecarAnimacao();
	}

	spr.avancarAnimacao();


	return true;
}