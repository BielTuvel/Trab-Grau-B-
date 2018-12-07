#include "Tiro.h"



Tiro::Tiro()
{
}


Tiro::~Tiro()
{
}

int Tiro::getX()
{
	if (vivo)
	{
		return x;
	}
	
}

int Tiro::getY()
{
	if (vivo)
	{
		return y;
	}
	
}

bool Tiro::getVivo()
{
	return vivo;
}

Sprite Tiro::getSprite()
{
	return spr;
}

void Tiro::desenhar()
{
	if (vivo)
	{
		spr.desenhar(x, y);

	}
}

void Tiro::atualizar()
{
	if (vivo)
	{
		if (direcaoo == 1)
		{
			y += velocidade;
		}
		if (y<spr.getAltura() || y > gJanela.getAltura())
		{
			morrer();
			
		}
	}
}

void Tiro::morrer()
{
	vivo = false;
	
}

void Tiro::disparar(float x, float y, int dire)
{
	this->x = x;
	this->y = y;
	this->direcaoo = dire;
	vivo = true;

}

void Tiro::inicializar()
{
	spr.setSpriteSheet("tiro");
	velocidade = -2;
	vivo = false;
}









