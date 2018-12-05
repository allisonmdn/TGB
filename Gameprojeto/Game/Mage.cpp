#include "Mage.h"



Mage::Mage()
{
}


Mage::~Mage()
{
}
void Mage::attack()
{
	if (gTeclado.pressionou[TECLA_ESPACO] && vivo == false)
	{
		vivo = true;

		tiro.setSpriteSheet("tiro");

		while (vivo == true) {

			if (direcao == 2)
			{
				tiro.desenhar(x, y);
				x += 1;	 // +
			}

			if (direcao == 1)
			{
				tiro.desenhar(x, y);
				x -= 1;	  // -
			}

			if (direcao == 3)
			{
				tiro.desenhar(x, y);
				y -= 1;// -

			}

			if (direcao == 0)
			{
				tiro.desenhar(x, y);
				y += 1;// +   				
			}

			if (x < tiro.getLargura() || x > gJanela.getLargura() + tiro.getLargura())
			{
				vivo = false;
			}
			if (y < tiro.getAltura() || y > gJanela.getAltura() + tiro.getLargura())
			{
				vivo = false;
			}
		}

		Sounds.setEffectSong("explosion");
	}
	
	

	
}


