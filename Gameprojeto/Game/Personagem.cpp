#include "Personagem.h"


Personagem::Personagem()
{ 
	
	srand(time(0));
	respawn = rand() % 3 + 1; //Between 1 and 3 to randomly respawn (Tiled Obj. Pos.).

	if (respawn == 1)
	{
		this->mx = 288;
		this->my = 97;
		//Pos1	  
	}
	else if (respawn == 2)
	{
		this->mx = 385;
		this->my = 129;
		//Pos2	
	}
	else
	{
		this->mx = 513;
		this->my = 96;
		//Pos3 
	}
   	 
	
	x = mx;
	y = my;

	this->healthBar = 100;   //HPMax
	this->staminaBar = 100;  //StaminaMAX

	this->strength = 1;
	this->agility = 1;
	this->vitality = 1;
	this->intelligence = 1;

	this->atk = 0;
	this->atkM = 0;
	this->def = 1;
	this->defM = 1;

	this->powerUP = 1;

	this->healthp = 1;
	this->stamina = 1;

	attributes(); 
	
}


Personagem::~Personagem()
{
}
//void PersonStatus::attributes(int strength_, int vitality_, int intelligence_, int agility_, int powerUp_, int atk_, int atkM_, int def_, int defM_)
void Personagem::attributes()
{
	/*this->strength = strength_;
	this->agility = agility_;
	this->vitality = vitality_;
	this->intelligence = intelligence_;

	this->atk = atk_;
	this->atkM = atkM_;
	this->def = def_;
	this->defM = defM_;

	this->powerUP = powerUp_;*/

	//atk -= def; //Attacking
	//atkM -= defM;

	staminaBar += stamina;
	healthBar += healthp + (vitality * 5);

}

void Personagem::DamageTaken()
{

	if (atk > 0)
	{
		healthBar -= (atk - def);
	}
	else
	{
		healthBar -= (atkM - defM);
	}
	staminaBar -= (atk + atkM * 0.5);

	healthBar -= 10;

}

int Personagem::gethpMax()
{
	return healthBar;
}

void Personagem::sethP(int healthp_)
{
	healthp = healthp_;
}

void Personagem::setStaminaMax(int StaMax)
{
	this->staminaBar = StaMax;

}

void Personagem::sethpMax(int hPMax)
{
	this->healthBar = hPMax;
}

void Personagem::setStamina(int stamina_)
{
	this->stamina = stamina_;
}

int Personagem::getStaminaMax()
{
	return staminaBar;
}

int Personagem::getStamina()
{
	return stamina;
}

int Personagem::getHp()
{
	return healthp;
}

int Personagem::getStrength()
{
	return strength;
}

int Personagem::getAgility()
{
	return agility;
}

int Personagem::getVitality()
{
	return vitality;
}

int Personagem::getIntelligence()
{
	return intelligence;
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

	//HP LIFE POINTS

	lifep.setFonte("fonte profile");
	lifep.setCor(0, 0, 0, true);
	lifep.setString(Hp_v + std::to_string(gethpMax()));
	lifep.setAlinhamento(TEXTO_ALINHADO_A_DIREITA);
	lifep.setEspacamentoLinhas(1.5f);

	//STAMINA POINTS

	sta.setFonte("fonte profile");
	sta.setCor(0, 0, 0, true);
	sta.setString(stamina_v + std::to_string(getStaminaMax()));
	sta.setAlinhamento(TEXTO_ALINHADO_A_DIREITA);
	sta.setEspacamentoLinhas(1.5f);


	//PLAYER PROFILE

	Texto_.setFonte("fonte profile");
	Texto_.setCor(0, 0, 0, true);
	Texto_.setString(TextoTeste);
	Texto_.setAlinhamento(TEXTO_ALINHADO_A_DIREITA);
	Texto_.setEspacamentoLinhas(1.5f);


	//DRAW TEXT

	Texto_.desenhar(50, 40);
	lifep.desenhar(50, 70);
	sta.desenhar(150, 70);

	this->spr.desenhar(getX(), getY());
	
	//HpBar

	        //BEGIN

	healthBar_Borda.setSpriteSheet("Borda");
	healthBar_Borda.desenhar(getX(), (getY() - 25));

	hB_Fundo.setSpriteSheet("FundoBarra");
	hB_Fundo.desenhar(getX(), (getY() - 25));
		
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
	//this->pStatus.drawPS();
	
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
		mx += 2;
		direcao = 2;
		spr.setAnimacao(2, false);
		//x + 1;
	}
	else if (gTeclado.segurando[TECLA_A])
	{
		//Left
		mx -= 2;
		direcao = 1;
		spr.setAnimacao(1, false);
		//x - 1;
	}
	else if (gTeclado.segurando[TECLA_W])
	{
		//
		my -= 2;
		direcao = 3;
		spr.setAnimacao(3, false);
		//y - 1;
	}
	else if (gTeclado.segurando[TECLA_S])
	{
		//Down		
		my += 2;
		direcao = 0;
		spr.setAnimacao(0, false);
		//y + 1;  
	}
	else
	{
		mx = mx;
		my = my;
		getX();
		getY();
		this->x = mx;
		this->y = my;
		spr.recomecarAnimacao();
	} 
	spr.avancarAnimacao(); 		
	
}

float Personagem::getX()
{
	return mx;
}

float Personagem::getY()
{
	return my;
}


void Personagem::setSpeed(float speed_)
{
	speed = speed_;
	
	speed = 2;
   		
	spr.setVelocidadeAnimacao(speed);
}
float Personagem::getSpeed()
{
	return speed;
}

Sprite Personagem::getSprite()
{
	return spr;
}



