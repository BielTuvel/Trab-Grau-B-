#pragma once

#include "string"
#include "Sprite.h"
class PowerUp
{
private:

	int x;
	int y;
	int a;
	int b;
	Sprite PowerUp_spr;
	Sprite Desabilita_spr;

public:
	PowerUp();
	~PowerUp();

	bool sumir;
	bool sumir_desabilita;

	int getXPowerUp();
	int getYPowerUp();
	int getAdesabilita();
	int getBdesabilita();
	void Some_PowerUp();
	bool getSumir();

	void setSpriteSheet_PowerUp(std::string spritesheet);
	Sprite getSpriteSheet_PowerUp();
	void desenhar();
	void desenhar_PowerUp2();
	Sprite getSpriteSheet_Desabilita();

};

