#include "Personagem2.h"



Personagem2::Personagem2()
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

Personagem2::~Personagem2()
{
	
}


//void PersonStatus::attributes(int strength_, int vitality_, int intelligence_, int agility_, int powerUp_, int atk_, int atkM_, int def_, int defM_)
void Personagem2::attributes()
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

void Personagem2::DamageTaken()
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

}

int Personagem2::gethpMax()
{
	return healthBar;
}

void Personagem2::sethP(int healthp_)
{
	healthp = healthp_;
}

void Personagem2::setStaminaMax(int StaMax)
{
	this->staminaBar = StaMax;

}

void Personagem2::sethpMax(int hPMax)
{
	this->healthBar = hPMax;
}

void Personagem2::setStamina(int stamina_)
{
	this->stamina = stamina_;
}

int Personagem2::getStaminaMax()
{
	return staminaBar;
}

int Personagem2::getStamina()
{
	return stamina;
}

int Personagem2::getHp()
{
	return healthp;
}

int Personagem2::getStrength()
{
	return strength;
}

int Personagem2::getAgility()
{
	return agility;
}

int Personagem2::getVitality()
{
	return vitality;
}

int Personagem2::getIntelligence()
{
	return intelligence;
}

void Personagem2::setSpriteSheet(std::string sSprite)
{

	spr2.setSpriteSheet(sSprite);//Set spr to get variable type string
	setSprite(&spr2);


}
void Personagem2::draw()	//Draws using the variable as condition.
{

	//TEXT POS UP HEAD

	//USERNAME

	text.setFonte("fonte2");
	text.setString("Username P2");
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
	Texto_.setString(TextoTeste2);
	Texto_.setAlinhamento(TEXTO_ALINHADO_A_DIREITA);
	Texto_.setEspacamentoLinhas(1.5f);


	//DRAW TEXT

	Texto_.desenhar(750, 40);
	lifep.desenhar(750, 70);
	sta.desenhar(650, 70);

	this->spr2.desenhar(getX(), getY());

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

	if (gTeclado.soltou[TECLA_CTRL_DIR])
	{

		hB_Points.setEscala(-1, 0);

	}
	//END	

	this->text.desenhar(getX(), (this->getY() - 35)); //Player text on person.
	 //this->pStatus.drawPS();
		
}
void Personagem2::attack()
{
	

	if (gTeclado.soltou[TECLA_CTRL_DIR])
	{
		
		
		Sounds.setEffectSong("attack");

		
	}

}


void Personagem2::update()
{
	attack();
	walk();

	if (vivo == false)
	{
		x = getX();
		y = getY();

	}
}

void Personagem2::walk()
{
	//Walk True

	if (gTeclado.segurando[TECLA_DIR])
	{
		//Right
		mx += 2;
		direcao = 2;
		spr2.setAnimacao(2, false);
		//x + 1;
	}
	else if (gTeclado.segurando[TECLA_ESQ])
	{
		//Left
		mx -= 2;
		direcao = 1;
		spr2.setAnimacao(1, false);
		//x - 1;
	}
	else if (gTeclado.segurando[TECLA_CIMA])
	{
		//Up
		my -= 2;
		direcao = 3;
		spr2.setAnimacao(3, false);
		//y - 1;
	}
	else if (gTeclado.segurando[TECLA_BAIXO])
	{
		//Down		
		my += 2;
		direcao = 0;
		spr2.setAnimacao(0, false);
		//y + 1;  
	}
	//Walk false.
	else
	{
		mx = mx;
		my = my;
		getX();
		getY();
		spr2.recomecarAnimacao();
	}

	spr2.avancarAnimacao();	
		
}
float Personagem2::getX()
{
	return mx;
}

float Personagem2::getY()
{
	return my;
}


void Personagem2::setSpeed(float speed_)
{
	speed = speed_;

	speed = 2;
	
	spr2.setVelocidadeAnimacao(speed);
}
float Personagem2::getSpeed()
{
	return speed;
}

Sprite Personagem2::getSprite()
{
	return spr2;
}
