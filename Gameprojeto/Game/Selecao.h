#include <iostream>
#include "libUnicornio.h"
#include <map>
#include <unordered_map>
#include <algorithm>
#include <vector>
#include <ctime>
#pragma once
class Selecao
{
public:
	Selecao();
	~Selecao();
	int op_map;
	void SelecMap();
	void drawMap();
	TileMap mapa1, mapa2;
};

