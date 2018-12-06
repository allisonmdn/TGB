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
   	 
	
	x = dir.x;
	y = dir.y;
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
	
	//TEXT POS UP HEAD
	
	//USERNAME

	text.setFonte("fonte2");
	text.setString("Username P1");
	text.setCor(0, 0, 0, true);
	text.setAlinhamento(TEXTO_CENTRALIZADO);
	text.setEspacamentoLinhas(1.5f);


	this->spr.desenhar(getX(), getY());
	
	//HpBar

	        //BEGIN

	healthBar_Borda.setSpriteSheet("Borda");
	healthBar_Borda.desenhar(getX(), (getY() - 25));

	hB_Fundo.setSpriteSheet("FundoBarra");
	hB_Fundo.desenhar(dir.x, (dir.y - 25));
		
	hB_Points.setSpriteSheet("HpPointsPixel");	
	hB_Points.desenhar(getX(), (getY() - 25));

	

	hB_brilho.setSpriteSheet("BrilhoBarra");
	hB_brilho.desenhar(getX(), (getY() - 25));

	if (gTeclado.soltou[TECLA_ESPACO])
	{	
		
	    hB_Points.setEscala(-1, 0);
				
	}
	       //END

	 	
	this->text.desenhar(getX(), (this->getY() - 35)); //Player text on person.
	this->pStatus.drawPS();
	
	//from Tiled

	//Pos1 288, 97;
	//Pos2 385, 129;
	//Pos3 513, 96;
}
void Personagem::update()
{
	attack();
	walk();			 	
	
		if (vivo == false)
		{
			x = getX();
			y = getY();

		}	
}
void Personagem::attack()
{
	if (gTeclado.soltou[TECLA_ESPACO])
	{
		Sounds.setEffectSong("attack");
	}
	
}
void Personagem::walk()
{	  
	
	if (gTeclado.segurando[TECLA_D])
	{
		//Right
		dir.x += 2;
		direcao = 2;
		spr.setAnimacao(2, false);
		//x + 1;
	}
	else if (gTeclado.segurando[TECLA_A])
	{
		//Left
		dir.x -= 2;
		direcao = 1;
		spr.setAnimacao(1, false);
		//x - 1;
	}
	else if (gTeclado.segurando[TECLA_W])
	{
		//
		dir.y -= 2;
		direcao = 3;
		spr.setAnimacao(3, false);
		//y - 1;
	}
	else if (gTeclado.segurando[TECLA_S])
	{
		//Down		
		dir.y += 2;
		direcao = 0;
		spr.setAnimacao(0, false);
		//y + 1;  
	}
	else
	{
		this->dir.set(getX(), getY());
		this->x = dir.x;
		this->y = dir.y;
		spr.recomecarAnimacao();
	} 
	spr.avancarAnimacao(); 		
	
}

float Personagem::getX()
{
	return dir.x;
}

float Personagem::getY()
{
	return dir.y;
}


void Personagem::setSpeed(float speed_)
{
	speed = speed_;
	
	speed = 1;
		
	spr.setVelocidadeAnimacao(speed);
}
float Personagem::getSpeed()
{
	return speed;
}



