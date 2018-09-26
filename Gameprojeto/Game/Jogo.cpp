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
	mapa.carregar("assets/tilemaps/mapa.json");
	
	gRecursos.carregarSpriteSheet("knight", "assets/spritesheets/Knight.png", 4, 4);

		
	Class[0] = new Warrior();
	Class[0]->setSpriteSheet("knight");
	
	
		
	ObjetoTileMap * ObjPos;
		
	/*In test if collision be true.

	CamadaDeTiles * ColLayer, * ColLayer2;
	
	ColLayer = mapa.getCamadaDeTiles("Ground4");
	ColLayer2 = mapa.getCamadaDeTiles("Ground5");

	//Ground4 and Ground5 collision layers.

	*/
	
	ObjPos = mapa.getCamadaDeObjetos("Objetos")->getObjeto("Pos1"); //ObjPos = map getLayerOfObjects("string") and point to getObject("string");
	Class[0]->setPosCentro(ObjPos->getPosCentro());	// Character type pointer indicate to set position in center (ObjPos point to get position in center).
	
}

void Jogo::finalizar()
{
	gRecursos.descarregarTudo();
	mapa.descarregar();
			
	uniFinalizar();
}

void Jogo::executar()
{
	
	

	while(!gTeclado.soltou[TECLA_ESC] && !gEventos.sair)
	{
		
		uniIniciarFrame();
		
		mapa.desenhar();
		
		Class[0]->draw();
		Class[0]->update();				

		uniTerminarFrame();
	}
}