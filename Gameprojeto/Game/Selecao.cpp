#include "Selecao.h"



Selecao::Selecao()
{
}


Selecao::~Selecao()
{
}

void Selecao::SelecMap()
{
	srand(time(0));

	typedef std::unordered_multimap<int, std::string> T_multimap;
	typedef std::pair<int, std::string> par;

	par escolha;
	T_multimap conjunto;
	std::vector<std::string>::iterator it;

	

	mapa1.carregar("assets/tilemaps/mapa.json"); //LoadMaps.
	mapa2.carregar("assets/tilemaps/mapa2.json");

	escolha.first = 1;
	escolha.second = "mapa.json";
	

	conjunto.insert(escolha);

	escolha.first = 2;
	escolha.second = "mapa2.json";

	conjunto.insert(escolha);

	op_map = rand() % 2 + 1;
					
	
}

void Selecao::drawMap()
{
	mapa1.desenhar();
	
}
