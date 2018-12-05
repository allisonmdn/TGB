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
	

	Texto_.setFonte("fonte1"); 	
	Texto_.setString(TextoTeste);
	Texto_.setAlinhamento(TEXTO_CENTRALIZADO);
	Texto_.setEspacamentoLinhas(1.5f);

	text.setFonte("fonte2");
	text.setString("Player");
	text.setAlinhamento(TEXTO_CENTRALIZADO);
	text.setEspacamentoLinhas(1.5f);

	this->spr.desenhar(dir.x, dir.y);
	
	//HpBar

	        //BEGIN

	healthBar_Borda.setSpriteSheet("Borda");
	healthBar_Borda.desenhar(dir.x, (dir.y - 25));

	hB_Fundo.setSpriteSheet("FundoBarra");
	hB_Fundo.desenhar(dir.x, (dir.y - 25));
		
	hB_Points.setSpriteSheet("HpPointsPixel");	
	hB_Points.desenhar(dir.x, (dir.y - 25));

	

	hB_brilho.setSpriteSheet("BrilhoBarra");
	hB_brilho.desenhar(dir.x, (dir.y - 25));

	if (gTeclado.soltou[TECLA_ESPACO])
	{	
		
	    hB_Points.setEscala(-1, 0);
				
	}
	       //END


	this->Texto_.desenhar(150, 40);
	this->text.desenhar(dir.x, (dir.y - 35)); //Player text on person.


	
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
			x = dir.x;
			y = dir.y;
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
		this->dir.set(dir.x, dir.y);
		this->x = dir.x;
		this->y = dir.y;
		spr.recomecarAnimacao();
	} 
	spr.avancarAnimacao();
	
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



