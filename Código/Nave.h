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
	Tiro tiro;
	
public:
	Nave();
	~Nave();
	int x, y, direcao;

	void setSpriteSheet(string spritesheet);
	void atualizar();
	void desenhar();
	void matarTiro();
	Sprite getSpriteTiro();
	int getXtiro();
	int getYtiro();
	int getXNave();
	int getYNave();
	bool morrer_Nave();
	void inicializaTiro();
	void atualizar_o_Tiro();
	void voltar_ao_Tiro();
	
	Sprite getSpriteNave();

	int pontuacao;
	bool Vivo_Nave;
};

