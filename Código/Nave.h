#pragma once
#include "libUnicornio.h"
#include <iostream>
#include "Tiro.h"
#include "Inimigo.h"
class Nave
{
protected:

	Sprite sprite;
	float speed;
	int x, y, direcao;
	Tiro tiro;
	
	
public:
	Nave();
	~Nave();

	void setSpriteSheet(string spritesheet);
	void atualizar();
	void desenhar();
	void matarTiro();
	Sprite getSproteTiro();
	int getXtiro();
	int getYtiro();
	void inicializaTiro();
	
	Sprite getSpriteNave();

	int pontuacao;
};

