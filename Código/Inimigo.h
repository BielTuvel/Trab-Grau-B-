#pragma once
#include "libUnicornio.h"
#include "Sprite.h"

class Inimigo
{

private:

	int velocidade;
	
	int x, y, direcao;
	int a, b, direcao2;
	Sprite spr_inimigo;
	bool vivoIni;

public:
	Inimigo();
	~Inimigo();

	void inicializar();
	void setSpriteSheet(string spritesheet);
	void atualizar();
	void desenhar();
	bool getVivo();
	void morrer();
	int getXIni();
	int getYIni();
	Sprite getSpriteInimigo();

};


