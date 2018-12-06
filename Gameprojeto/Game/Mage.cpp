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

		tiro.setSpriteSheet("skull");
				

		while (vivo == true) {


			if (direcao == 2 && gTeclado.soltou[TECLA_ESPACO])
			{
				spr.setFrame(2);
				spr.getFrame();
			}
			if (direcao == 1 && gTeclado.soltou[TECLA_ESPACO])
			{
				spr.setFrame(1);
				spr.getFrame();

			}
			if (direcao == 3 && gTeclado.soltou[TECLA_ESPACO])
			{
				spr.setFrame(3);
				spr.getFrame();

			}
			if (direcao == 0 && gTeclado.soltou[TECLA_ESPACO])
			{
				spr.setFrame(0);
				spr.getFrame();

			}

			if (direcao == 2)
			{
				tiro.desenhar(x, y, direcao);
				x += 1;	 // x+
			}

			if (direcao == 1)
			{
				tiro.desenhar(x, y, direcao);
				x -= 1;	  // x-
				
			}

			if (direcao == 3)
			{
				tiro.desenhar(x, y,direcao);
				y -= 1;// y-

			}

			if (direcao == 0)
			{
				tiro.desenhar(x, y, direcao);
				y += 1;// y+   				
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


