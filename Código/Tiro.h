#pragma once
#include "libUnicornio.h"
#include "Inimigo.h"
class Tiro
{
public:
	Tiro();
	~Tiro();

	int getX();
	int getY();
	bool getVivo();
	Sprite getSprite();
	
	void desenhar();
	void atualizar();
	void morrer();
	void disparar(float x, float y, int dire);
	void inicializar();
	//void setPos(float x, float y);

	float x, y;
	float velocidade;
	Sprite spr;
	bool vivo;
	int direcaoo;

};

