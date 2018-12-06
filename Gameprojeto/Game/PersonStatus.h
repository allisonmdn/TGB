#include <iostream>
#include <libUnicornio.h>
				   

class PersonStatus
{
public:
	PersonStatus();
	~PersonStatus();  	 
	//void attributes(int strength_, int vitality_, int intelligence_, int agility_, int powerUp_,int atk_, int atkM_, int def_, int defM_); // Method of attributes to added to a person.
	void attributes();
	void DamageTaken();
	void sethpMax(int hPMax);
	void setStamina(int stamina_);
	void sethP(int healthp_);
	void setStaminaMax(int StaMax);
	int gethpMax();
	int getHp();			 	
	int getStaminaMax();
	int getStamina();  	
	int getStrength();
	int getAgility();
	int getVitality();
	int getIntelligence();
	void drawPS();
	void Profile();

	//TEXTS	PROFILE
	Texto lifep, sta;
	Texto Texto_; //Class.
	std::string Hp_v = "HP: ";
	std::string stamina_v = "STA: ";
	std::string TextoTeste = "Player 1"; //Account
	std::string TextoTeste2 = "Player 2";


	//HPMAX and STAMINAMAX
	int healthBar;
	int staminaBar;
	
	
protected:
	//ATRIBUTTES

	int strength, vitality, intelligence, agility; // attributes variables.
	int powerUP;
	int atk, atkM; //Atk
	int def, defM;
	int stamina, healthp;

	

	
	

};