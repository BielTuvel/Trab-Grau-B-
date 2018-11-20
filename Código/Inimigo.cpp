#include "Inimigo.h"
Inimigo::Inimigo()
{
	
	
}


Inimigo::~Inimigo()
{
}

void Inimigo::inicializar()
{
	setSpriteSheet("Inimigo1");
	vivoIni = true;
	x = 300;
	y = 50;
	velocidade = 1;
}

void Inimigo::setSpriteSheet(string spritesheet)
{
	spr_inimigo.setSpriteSheet(spritesheet);
}

void Inimigo::atualizar()
{
	
			
   if(vivoIni)
   {

	   y+= velocidade;
	   b+= velocidade;

	   if (y == 730)
	   {
		  
		   morrer();
           //gDebug.depurar("Vivo2:", getVivo());
	   }
	   if (b == 730)
	   {
		   morrer();
		   //gDebug.depurar("Vivo3:", getVivo());

	   }

   }

}

void Inimigo::desenhar()
{
	if (vivoIni)
	{
		spr_inimigo.desenhar(x, y);
	}
	
    
}

bool Inimigo::getVivo()
{
	return vivoIni;
}

void Inimigo::morrer()
{
	vivoIni = false;
	
}

int Inimigo::getXIni()
{
	if (vivoIni)
	{
		return x;
	}
	
}

int Inimigo::getYIni()
{
	if (vivoIni)
	{
		return y;
	}
	
}

Sprite Inimigo::getSpriteInimigo()
{
	return spr_inimigo;
}
