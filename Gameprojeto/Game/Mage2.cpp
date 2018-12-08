#include "Mage2.h"



Mage2::Mage2()
{
}


Mage2::~Mage2()
{
}
void Mage2::attack()
{
	if (gTeclado.pressionou[TECLA_CTRL_DIR] && vivo == false)
	{
		vivo = true;

		tiro2.setSpriteSheet("skull");
		



		while (vivo == true) {


			if (direcao == 2 && gTeclado.pressionou[TECLA_CTRL_DIR])
			{
				spr2.setFrame(2);
				spr2.getFrame();
			}
			if (direcao == 1 && gTeclado.pressionou[TECLA_CTRL_DIR])
			{
				spr2.setFrame(1);
				spr2.getFrame();

			}
			if (direcao == 3 && gTeclado.pressionou[TECLA_CTRL_DIR])
			{
				spr2.setFrame(3);
				spr2.getFrame();

			}
			if (direcao == 0 && gTeclado.pressionou[TECLA_CTRL_DIR])
			{
				spr2.setFrame(0);
				spr2.getFrame();

			}

			if (direcao == 2)
			{
				tiro2.desenhar(x, y, direcao);
				x += getSpeed();	 // x+
			}

			if (direcao == 1)
			{
				tiro2.desenhar(x, y, direcao);
				x -= getSpeed();	  // x-

			}

			if (direcao == 3)
			{
				tiro2.desenhar(x, y, direcao);
				y -= getSpeed();// y-

			}

			if (direcao == 0)
			{
				tiro2.desenhar(x, y, direcao);
				y += getSpeed();// y+   				
			}

			if (x < tiro2.getLargura() || x > gJanela.getLargura() + tiro2.getLargura())
			{
				vivo = false;
			}
			if (y < tiro2.getAltura() || y > gJanela.getAltura() + tiro2.getLargura())
			{
				vivo = false;
			}
		}
		Sounds.setEffectSong("explosion");

	}
	   

}



