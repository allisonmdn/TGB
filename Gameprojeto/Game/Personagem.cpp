#include "Personagem.h"



Personagem::Personagem()
{
		
}


Personagem::~Personagem()
{
}

void Personagem::setSpriteSheet(std::string sSprite)
{
	
	spr.setSpriteSheet(sSprite);//Set spr to get variable type string
	setSprite(&spr);
	
}

void Personagem::setRespawn()
{
	this->width = 800;
	this->height = 600;
	respawn = rand() % 3 + 1;
				
	//this->x = rand() % width; //Variable "x" and "y" to randomly respawn.
	//this->y = rand() % height;
		
}

void Personagem::draw()	//Draws using the variable as condition.
{		
	
	if (respawn == 1)
	{
		this->dir.x = 288;
		this->dir.y = 97;
		//Pos1	  
	}
	else if (respawn == 2)
	{
		this->dir.x = 385;
		this->dir.y = 129;
		//Pos2	
	}
	else
	{
		this->dir.x = 513;
		this->dir.y = 96;
		//Pos3 
	}
	this->spr.desenhar(dir.x, dir.y);
	
	//from Tiled

	//Pos1 288, 97;
	//Pos2 385, 129;
	//Pos3 513, 96;
}
void Personagem::update()
{		
	if (gTeclado.segurando[TECLA_D])
	{			
		dir.set(1, 0);
		
		spr.setAnimacao(2, false);				
		//x + 1;
	}
	else if (gTeclado.segurando[TECLA_A])
	{
		dir.set(-1, 0);
		
		spr.setAnimacao(1, false);		
		//x - 1;
	}
	else if (gTeclado.segurando[TECLA_W])
	{
		dir.set(0, 1);
		
		spr.setAnimacao(3, false);		
		//y + 1;
	}
	else if (gTeclado.segurando[TECLA_S])
	{
		dir.set(0, -1);
		
		spr.setAnimacao(0, false);
		//y - 1;  
	}
	else
	{			
		dir.set(0, 0);		
		spr.recomecarAnimacao();		
	}
	
	spr.avancarAnimacao();

	Vetor2D pos = getPosCentro();
	pos += dir * speed / 2 * gTempo.getDeltaTempo();
	setPosCentro(pos);		
}

/*void Personagem::setSpeed()
{
	this->speed = 1;
}
float Personagem::getSpeed()
{
	return speed;
}*/

