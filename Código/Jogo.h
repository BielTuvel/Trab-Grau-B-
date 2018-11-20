#pragma once
#include "libUnicornio.h"
#include "Controller.h"
#include "CarregadorDeAssets.h"
#include "fstream"
#include "Menu.h"
class Jogo
{
public:
	Jogo();
	~Jogo();

	void inicializar();
	void finalizar();


	void executar();

private:

	CarregadorDeAssets * carregaAssets;
	Menu * menuzao;
	
};

