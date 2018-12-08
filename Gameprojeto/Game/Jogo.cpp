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
	gRecursos.carregarFonte("fonte1", "assets/fonts/minecraft.ttf", 32);
	gRecursos.carregarFonte("fonte2", "assets/fonts/minecraft.ttf", 16);
	gRecursos.carregarFonte("fonte profile", "assets/fonts/minecraft.ttf", 16, FONTE_ESTILO_NEGRITO);

	menuz.LoadMenu();

	mapa.carregar("assets/tilemaps/mapa.json");
	mapa2.carregar("assets/tilemaps/mapa2.json");

	//ATRIBUTTES
	
	//TIME

	time = 0;
	

	//Text


	
	

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
	//gRecursos.carregarSpriteSheet("tiro", "assets/spritesheets/shot/tiro.png", 1, 1);
	//gRecursos.carregarSpriteSheet("tiro2", "assets/spritesheets/shot/tiro.png", 1, 1);
	gRecursos.carregarSpriteSheet("skull", "assets/spritesheets/shot/Skull.png", 1, 1);
	gRecursos.carregarSpriteSheet("Treasure Box", "assets/spritesheets/Powerups/treasure_box_sheet.png", 3, 1);
	//gRecursos.carregarSpriteSheet("Rock", "assets/spritesheets/shot/Rock.png", 3, 1);
	//gRecursos.carregarSpriteSheet("Potion_HP", "assets/spritesheets/Powerups/Potion.png", 1, 1);

	//ATK SPRITE
	gRecursos.carregarSpriteSheet("thief1", "assets/spritesheets/Thief1.png", 4, 2);
	gRecursos.carregarSpriteSheet("mage1", "assets/spritesheets/Mage1.png", 4, 2);
	gRecursos.carregarSpriteSheet("knight1", "assets/spritesheets/Knight1.png", 4, 2);



		
	treasure.setSpriteSheet("Treasure Box");
	//potions.setSpriteSheet("Potion_HP");
	
		
	//Sounds
	LoadS.LoadSongs(); // Load Songs.
	Btn.setSpriteSheet("sound");
	
	LoadS.setThemeSong("Kings_Feast");

	// Knight
	P1[0] = new Knight();
	P1[0]->setSpriteSheet("knight");
	P2[0] = new Knight2();
	P2[0]->setSpriteSheet("knight");

	TX.text.setFonte("fonte profile");
	TX.text.setString("class: Knight");

	TX.text.setAlinhamento(TEXTO_CENTRALIZADO);

	TX.text.setEspacamentoLinhas(1.5f);

	TX2.text.setFonte("fonte profile");
	TX2.text.setString("class: Knight");

	TX2.text.setAlinhamento(TEXTO_CENTRALIZADO);

	TX2.text.setEspacamentoLinhas(1.5f);

	// Mage

	P1[1] = new Mage();
	
	
	P2[1] = new Mage2();
	

	if (gTeclado.pressionou[TECLA_ESPACO] || gTeclado.pressionou[TECLA_CTRL_DIR])
	{
		P1[1]->setSpriteSheet("mage1");
		P2[1]->setSpriteSheet("mage1");
	}
	else
	{
		P1[1]->setSpriteSheet("mage");
		P2[1]->setSpriteSheet("mage");

	}

	// Thief

	P1[2] = new Thief();
	P1[2]->setSpriteSheet("thief");
	P2[2] = new Thief2();
	P2[2]->setSpriteSheet("thief");

	ObjetoTileMap *ObjPos, *ObjPos2;
	ObjPos = mapa2.getCamadaDeObjetos("Objetos")->getObjeto("Pos1"); //ObjPos = map getLayerOfObjects("string") and point to getObject("string");
	ObjPos2 = mapa2.getCamadaDeObjetos("Objetos")->getObjeto("Pos2");
				

	P1[sChar()]->setPosCentro(ObjPos->getPosCentro());	// Character type pointer indicate to set position in center (ObjPos point to get position in center).
	P2[sChar()]->setPosCentro(ObjPos2->getPosCentro());


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
	t_x = rand() % width;
	t_y = rand() % height;
	

	while (!gTeclado.soltou[TECLA_ESC] && !gEventos.sair && !menuz.Exit_m() == true)
	{
		uniIniciarFrame();	 

		//Draw Map

		mapa2.desenhar();
				

		//Switch Character.
		
			sChar();

						
		Collisions();

		//TREASURE BOX

		

		time++;

		time = time / 1000;

		gDebug.depurar("Time: ", time);

		//TESTE TEMPO 3600 == 1 MIN
		if ((time / 1000) == 1)
		{
			t_x = rand() % width;
			t_y = rand() % height;
			treasure.setAnimacao(0);
		}

		
		treasure.desenhar(t_x, t_y);		
			

		//Person

		P1[sChar()]->draw();
		P1[sChar()]->update();
		P2[sChar()]->draw();
		P2[sChar()]->update();

			  			  
		TX.text.desenhar(150, 40); // Class name.
		TX2.text.desenhar(650, 40); // Class name.
				

		//Button SOUND

		//Btn.desenhar(780, 10);
		Btn.setX(780);
		Btn.setY(580);
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
	bool player_col = Collision_Player();
}

bool Jogo::Collision_Treasure()
{		  

	if (uniTestarColisaoPontoComSprite(t_x, t_y, treasure, P1[sChar()]->getX(), P1[sChar()]->getY(), 0))
	{			
		
		treasure.setAnimacao(1);
		treasure.avancarAnimacao();
		treasure.setAnimacao(2);
		treasure.avancarAnimacao();
		treasure.terminouAnimacao();


		return true;				 
	}
	else if (uniTestarColisaoPontoComSprite(t_x, t_y, treasure, P2[sChar()]->getX(), P2[sChar()]->getY(), 0))
	{
		treasure.setAnimacao(1);
		treasure.avancarAnimacao();
		treasure.setAnimacao(2);
		treasure.avancarAnimacao();
		treasure.terminouAnimacao();

		return true;
	}

	return false;
	
}

bool Jogo::Collision_Player()
{
	
	if (gTeclado.soltou[TECLA_ESPACO] && P1[0] || P1[2] && uniTestarColisaoSpriteComSprite(P1[sChar()]->getSprite(), P1[sChar()]->getX(), P1[sChar()]->getY(), 0, P2[sChar()]->getSprite(), P2[sChar()]->getX(), P2[sChar()]->getY(),0,true))
	{
		
		
			P1[0]->setSpriteSheet("knight1");
			P1[2]->setSpriteSheet("thief1");			
			P2[sChar()]->DamageTaken();
			P2[sChar()]->sethP(-10);
			P2[sChar()]->gethpMax();
			
			gGraficos.desenharRetangulo(200, 30, 10, 0, P2[sChar()]->getX(), P2[sChar()]->getY() - 50, 0, 0, 0, 128);

			damage_t.setFonte("fonte2");
			damage_t.setString(damage);
			damage_t.desenhar(P2[sChar()]->getX(), P2[sChar()]->getY() - 60);
			
		
			

		return true;
	}
	    //COLLISION P2 SHOT IN P1

	if (gTeclado.soltou[TECLA_CTRL_DIR] && P2[0] || P2[2] && uniTestarColisao(P2[sChar()]->getX(), P2[sChar()]->getY(), P1[sChar()]->getShot(), P1[sChar()]->getShotX(), P1[sChar()]->getShotY(), P1[sChar()]->getDir()))
	{
		P1[0]->setSpriteSheet("knight1");
		P1[2]->setSpriteSheet("thief1");

		P1[sChar()]->DamageTaken();
		P1[sChar()]->sethP(-10);
		P1[sChar()]->gethpMax();
		gGraficos.desenharRetangulo(200, 30, 10, 0, P1[sChar()]->getX(), P1[sChar()]->getY() - 60, 0, 0, 0, 128); 
		damage_t.setFonte("fonte2");
		damage_t.setString(damage);
		damage_t.desenhar(P1[sChar()]->getX(), P1[sChar()]->getY() - 60);//Damage taken P1.
		
		
		return true;
		
	}
	
	//COLLISION P1 SHOT IN P2

	if (gTeclado.soltou[TECLA_ESPACO] && P1[0] || P1[2] && uniTestarColisao(P1[sChar()]->getX(), P1[sChar()]->getY(), P2[sChar()]->getShot(), P2[sChar()]->getShotX(), P2[sChar()]->getShotY(), P2[sChar()]->getDir()))
		{
			P2[sChar()]->DamageTaken();			
			P2[sChar()]->sethP(-10);
			P2[sChar()]->gethpMax();
			gGraficos.desenharRetangulo(200, 30, 10, 0, P2[sChar()]->getX(), P2[sChar()]->getY() - 60, 0, 0, 0, 128);
			damage_t.setFonte("fonte2");
			damage_t.setString(damage);
			damage_t.desenhar(P2[sChar()]->getX(), P2[sChar()]->getY() - 60);

			return true;
		}



	

	return false;
}

int Jogo::sChar()
{
	if (gTeclado.soltou[TECLA_1])
	{
		x_char = 0;
		TX.text.setString("class: Knight");
		TX2.text.setString("class: Knight");
	}

	if (gTeclado.soltou[TECLA_2])
	{
		x_char = 1;
		TX.text.setString("class: Mage");
		TX2.text.setString("class: Mage");
	}

	if (gTeclado.soltou[TECLA_3])
	{
		x_char = 2;
		TX.text.setString("class: Thief");
		TX2.text.setString("class: Thief");
	}

	return x_char;
}
