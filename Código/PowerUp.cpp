#include "PowerUp.h"

PowerUp::PowerUp()
{
	x = 23;
	y = 430;
	a = 583;
	b = 430;

}

PowerUp::~PowerUp()
{
}

int PowerUp::getXPowerUp()
{
	//só vai retornar o valor de x, se estiver vivo
	//com isso não tem chance de um objeto estar colidindo no invisível
	//isso é feito para todos os demais
	if (sumir)
	{
		return x;
	}
}

int PowerUp::getYPowerUp()
{
	if (sumir)
	{
		return y;
	}
}

int PowerUp::getAdesabilita()
{
	if (sumir_desabilita)
	{
		return a;
	}
}

int PowerUp::getBdesabilita()
{
	if (sumir_desabilita)
	{
		return b;
	}
}

void PowerUp::Some_PowerUp()
{
	sumir = false;
	sumir_desabilita = false;
}

bool PowerUp::getSumir()
{
	return sumir, sumir_desabilita;
}

void PowerUp::setSpriteSheet_PowerUp(std::string spritesheet)
{
	PowerUp_spr.setSpriteSheet(spritesheet);
	Desabilita_spr.setSpriteSheet(spritesheet);
}



Sprite PowerUp::getSpriteSheet_PowerUp()
{
	return PowerUp_spr;
}

void PowerUp::desenhar()
{
	if (sumir)
	{
		PowerUp_spr.desenhar(x, y);
	}
}

void PowerUp::desenhar_PowerUp2()
{
	if (sumir_desabilita)
	{
		Desabilita_spr.desenhar(a, b);
	}
}

Sprite PowerUp::getSpriteSheet_Desabilita()
{
	return Desabilita_spr;
}

