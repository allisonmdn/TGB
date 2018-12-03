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
			

	
	dir2.x = dir.x;
	dir2.y = dir.y;
}


Personagem::~Personagem()
{
}


void Personagem::setSpriteSheet(std::string sSprite)
{

	spr.setSpriteSheet(sSprite);//Set spr to get variable type string
	setSprite(&spr);
	tiro.setSpriteSheet("tiro");

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

	       //END

//Draw with Vetor2D type.
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
	shot();

	
		if (vivo == false)
		{
			dir2.x = dir.x;
			dir2.y = dir.y;
		}

}
void Personagem::attack()
{
	

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
		this->dir2.set(dir.x, dir.y);
		spr.recomecarAnimacao();
	}

	spr.avancarAnimacao();


}

void Personagem::shot()
{
	if (gTeclado.pressionou[TECLA_ESPACO] && vivo == false)
	{
		vivo = true;


		while (vivo == true) {

			if (direcao == 2)
			{
				tiro.desenhar(dir2.x, dir2.y);
				dir2.x += 1;	 //+
			}

			if (direcao == 1)
			{
				tiro.desenhar(dir2.x, dir2.y);
				dir2.x -= 1;	  //-
			}

			if (direcao == 3)
			{
				tiro.desenhar(dir2.x, dir2.y);
				dir2.y -= 1; //-
			}

			if (direcao == 0)
			{
				tiro.desenhar(dir2.x, dir2.y);
				dir2.y += 1; //+
				
			}	   

			if (dir2.x < tiro.getLargura() || dir2.x > gJanela.getLargura() + tiro.getLargura())
			{
				vivo = false;
			}
			if (dir2.y < tiro.getAltura() || dir2.y > gJanela.getAltura() + tiro.getLargura())
			{
				vivo = false;  
			}	   		
		} 		
		Sounds.setEffectSong("hit"); 
	}
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



