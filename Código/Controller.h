#pragma once
#include "Nave.h"
#include "Mapa.h"
#include "Inimigo.h"
#include "Tiro.h"
class Controller
{
private:
	Mapa * mapa;
	Nave * player;
	Inimigo * enemy;
	Texto texto;
	
public:

	Controller();
	~Controller();
	void controlaAtaques();
	void atualizar();
	void inicializar();
	void finalizar();
	void testarColisoes();
	
	
};