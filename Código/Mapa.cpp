#include "Mapa.h"

Mapa::Mapa()
{
	//Desenhando o mapa do jogo na posi��o correta
	x = 300;
	y = 230;
}


Mapa::~Mapa()
{
}

void Mapa::desenhar()
{
	sprite.desenhar(x, y);
}

void Mapa::setSpriteSheet(string spritesheet)
{
	sprite.setSpriteSheet(spritesheet);
}


