#include <iostream>
#include <libUnicornio.h>
				   

class PersonStatus
{
public:
	PersonStatus();
	~PersonStatus();  	 
	void attributes(); // Method of attributes to added to a person.
	void DamageTaken();
	int gethpMax();
	int getStaminaMax();
	int getStrength();
	int getAgility();
	int getVitality();
	int getIntelligence();
	void drawPS();
	void Profile();


	//HPMAX and STAMINAMAX
	int healthBar;
	int staminaBar;

private:
	//TEXTS	PROFILE
	Texto lifep, sta;
	Texto Texto_; //Class.
	std::string Hp_v = "HP: ";
	std::string stamina_v = "STA: ";
	std::string TextoTeste = "Player 1"; //Account
	
protected:
	//ATRIBUTTES

	int strength, vitality, intelligence, agility; // attributes variables.
	int powerUP;
	int atk, atkM; //Atk
	int def, defM;
	int stamina, healthp;

	

	
	

};