#include "Jogo.h"

Jogo::Jogo()
{

}

Jogo::~Jogo()
{
}

void Jogo::inicializar()
{

	uniInicializar(800, 600, false);

	/*this->inORout.open("assets_all.txt", ios::in);
	if (!inORout.is_open())
	{
		gDebug.erro("Don't opened the file", this);
	}
	else
	{
		//Load Resources

		LoadingResources * Ld_R = new LoadingResources;
		if (!Ld_R->Loader(inORout))
		{
			gDebug.erro("Error in loading resources");
		}
		inORout.close();
	}*/
	
		
	//Maps

	menuz.LoadMenu();

	mapa.carregar("assets/tilemaps/mapa.json");
	mapa2.carregar("assets/tilemaps/mapa2.json");
	

	//Text

	gRecursos.carregarFonte("fonte1", "assets/fonts/minecraft.ttf", 32);
	gRecursos.carregarFonte("fonte2", "assets/fonts/minecraft.ttf", 16);
	gRecursos.carregarFonte("fonte profile", "assets/fonts/minecraft.ttf", 16, FONTE_ESTILO_NEGRITO);
	

	//SpriteSheets Person

	gRecursos.carregarSpriteSheet("knight", "assets/spritesheets/Knight.png", 4, 4);
	gRecursos.carregarSpriteSheet("mage", "assets/spritesheets/mage.png", 4, 4);
	gRecursos.carregarSpriteSheet("thief", "assets/spritesheets/thief.png", 4, 4);
	gRecursos.carregarSpriteSheet("sound", "assets/spritesheets/sound.png", 2, 1);
	//HpBar
	
	gRecursos.carregarSpriteSheet("Borda", "assets/spritesheets/HealthBar/Borda.png", 1, 1);
	gRecursos.carregarSpriteSheet("BrilhoBarra", "assets/spritesheets/HealthBar/BrilhoBarra.png", 1, 1);
	gRecursos.carregarSpriteSheet("FundoBarra", "assets/spritesheets/HealthBar/FundoBarra.png", 1, 1);
	gRecursos.carregarSpriteSheet("HpPointsPixel", "assets/spritesheets/HealthBar/HpPointsPixel.png", 1, 1);
	gRecursos.carregarSpriteSheet("HpPointsPixel2", "assets/spritesheets/HealthBar/HpPointsPixel2.png", 1, 1);
	gRecursos.carregarSpriteSheet("tiro", "assets/spritesheets/shot/tiro.png", 1, 1);
	gRecursos.carregarSpriteSheet("Treasure Box", "assets/spritesheets/Powerups/treasure_box_sheet.png", 3, 1);
		
	treasure.setSpriteSheet("Treasure Box");
	
		
	//Sounds
	LoadS.LoadSongs(); // Load Songs.
	Btn.setSpriteSheet("sound");
	
	Theme.setThemeSong("Kings_Feast");

	// Knight
	Class[0] = new Knight();
	Class[0]->setSpriteSheet("knight");
	text.setFonte("fonte profile");
	text.setString("class: Knight");

	text.setAlinhamento(TEXTO_CENTRALIZADO);

	text.setEspacamentoLinhas(1.5f);

	// Mage

	Class[1] = new Mage();
	Class[1]->setSpriteSheet("mage");

	// Thief

	Class[2] = new Thief();
	Class[2]->setSpriteSheet("thief");

	ObjetoTileMap * ObjPos;
	ObjPos = mapa2.getCamadaDeObjetos("Objetos")->getObjeto("Pos1"); //ObjPos = map getLayerOfObjects("string") and point to getObject("string");
				

	Class[sChar()]->setPosCentro(ObjPos->getPosCentro());	// Character type pointer indicate to set position in center (ObjPos point to get position in center).

	
	//Map1
	//Ground4 and Ground5 collision layers.
	//Ground5 nv2.

	//Map2
	//Ground2, Ground3 and Ground4 collision layers.
	//Ground5 nv2.

}

void Jogo::finalizar()
{
	gRecursos.descarregarTudo();
	
	//mapa2.descarregar();
	
	uniFinalizar();
}

void Jogo::executar()
{
	int Tempo;
	

	t_x = rand() % width;
	t_y = rand() % height;

	gTempo.inicializar();
	
	while (!gTeclado.soltou[TECLA_ESC] && !gEventos.sair && !menuz.Exit_m() == true)
	{
		uniIniciarFrame();	 

		mapa2.desenhar();
									 		
		Tempo = 60 * gTempo.getDeltaTempo();
		

		//Switch Character.
		
			sChar();

						
		Collisions();
		
		treasure.desenhar(t_x, t_y);		
			

		//Person

		Class[sChar()]->draw();
		Class[sChar()]->update();

			  			  
		text.desenhar(150, 40); // Class name.

		

		//Button

		//Btn.desenhar(780, 10);
		Btn.setX(780);
		Btn.setY(10);
		Btn.atualizar();
		Btn.desenhar();
				
		
		if (Btn.estaClicado() && !Btn.estaAbaixado())
		{				 			
			Btn.setAnimacaoDoEstado(BOTAOSPRITE_ABAIXADO, 1);
			gMusica.setVolumeGlobal(0);
			gAudios.setVolumeGlobal(0);			
		}
		if (Btn.estaClicado() && Btn.estaAbaixado())
		{	  			
			Btn.setAnimacaoDoEstado(BOTAOSPRITE_NORMAL, 0);  			
			gMusica.setVolumeGlobal(50);
			gAudios.setVolumeGlobal(50);						
		}		
		

		/*
		if (gMouse.soltou[BOTAO_MOUSE_ESQ]) //Muted.
		{
			Btn.setAnimacao(1, false);
			Btn.avancarAnimacao();
			gMusica.setVolumeGlobal(0);
			
		}
		else if (gMouse.soltou[BOTAO_MOUSE_DIR])
		{
			Btn.setAnimacao(0, false);
			Btn.avancarAnimacao();
			gMusica.setVolumeGlobal(70);
		}*/

		menuz.updateMenu();
		


		uniTerminarFrame();
	}
}

void Jogo::Collisions()
{
	
	bool treasure_b = Collision_Treasure();

	  	
	
}

bool Jogo::Collision_Treasure()
{
	

	if (mapa.existeObjetoDoTipoNaPos("Treasure Box", Class[sChar()]->getX(), Class[sChar()]->getY()))
	{
		

		uniTestarColisaoPontoComSprite(Class[sChar()]->getX(), Class[sChar()]->getY(), treasure, t_x, t_y, 0);
		

		return true;
	}

	return false;
	
}

int Jogo::sChar()
{
	if (gTeclado.soltou[TECLA_1])
	{
		x_char = 0;
		text.setString("class: Knight");
	}

	if (gTeclado.soltou[TECLA_2])
	{
		x_char = 1;
		text.setString("class: Mage");
	}

	if (gTeclado.soltou[TECLA_3])
	{
		x_char = 2;
		text.setString("class: Thief");
	}

	return x_char;
}
