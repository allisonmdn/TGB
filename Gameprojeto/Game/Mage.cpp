#include "Mage.h"



Mage::Mage()
{
}


Mage::~Mage()
{
}
void Mage::attack()
{
	if (gTeclado.soltou[TECLA_ESPACO])
	{
		//Attack.
		Sounds.setEffectSong("explosion");
		
	}
}


