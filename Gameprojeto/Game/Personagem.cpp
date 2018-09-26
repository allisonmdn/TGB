#include "Personagem.h"



Personagem::Personagem()
{
	srand(time(0));
	respawn = rand() % 3 + 1; //Between 1 and 3 to randomly respawn (Tiled Obj. Pos.).

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
	
	//Respawn free of pos. in obj. layer.

	/*this->width = 800;
	this->height = 600;	

	this->x = rand() % width; //Variable "x" and "y" to randomly respawn.
	this->y = rand() % height;*/
}


Personagem::~Personagem()
{
}

void Personagem::setSpriteSheet(std::string sSprite)
{
	
	spr.setSpriteSheet(sSprite);//Set spr to get variable type string
	setSprite(&spr);
	
}

void Personagem::draw()	//Draws using the variable as condition.
{		
	
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
		
		dir.x += 1;
		
		spr.setAnimacao(2, false);
		
		//x + 1;
	}
	else if (gTeclado.segurando[TECLA_A])
	{
		dir.x -= 1;;
		
		spr.setAnimacao(1, false);		
		//x - 1;
	}
	else if (gTeclado.segurando[TECLA_W])
	{
		dir.y -= 1;
		
		spr.setAnimacao(3, false);		
		//y - 1;
	}
	else if (gTeclado.segurando[TECLA_S])
	{
		//dir.set(dir.x,dir.y + 1);
		
		dir.y += 1;
		spr.setAnimacao(0, false);
		//y + 1;  
	}
	else
	{			
		this->dir.set(dir.x, dir.y);
		spr.recomecarAnimacao();		
	}
	
	spr.avancarAnimacao();

	Vetor2D pos = getPosCentro();
	pos += dir * speed * 2 * gTempo.getDeltaTempo();
	setPosCentro(pos);		
}

void Personagem::setSpeed()
{
	this->speed = 1;
}
float Personagem::getSpeed()
{
	return speed;
}

