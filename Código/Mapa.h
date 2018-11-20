#pragma once
#include "libUnicornio.h"
#include <iostream>
class Mapa 
{

protected:
	Sprite sprite;
	int x, y;


public:
	Mapa();
	~Mapa();

	void desenhar();
	void setSpriteSheet(string spritesheet);
};

