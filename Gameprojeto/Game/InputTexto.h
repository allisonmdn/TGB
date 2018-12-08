#pragma once

#include "libUnicornio.h"

class InputTexto
{
public:
	InputTexto();
	~InputTexto();

	void inicializar();
	void finalizar();

	void atualizar();
	void desenhar();
	Texto getTexto();
	Texto limparTexto();

private:
	Texto txt;
	
};

