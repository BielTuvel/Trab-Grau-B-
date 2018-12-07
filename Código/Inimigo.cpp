#include "Inimigo.h"

Inimigo::Inimigo()
{
	
	
	
}

/*Nesta classe temos todos os Inimigos
e todas suas características*/
/*Por boa prática estou dizendo o que as variaveis são direto no construtor
Principalmente as do tipo bool, que por mais que umas sejam true por default
sempre é bom declarar*/
Inimigo::~Inimigo()
{
}

void Inimigo::inicializar()
{
	setSpriteSheet("Inimigo1");
	setSptitesheetBoss("Boss");
	vivoIni = true;
	vivoIni2 = true;
	vivoBoss = false;
	vivoIni3 = false;
	x_Inimigo1 = 200;
	y_Inimigo1 = 50;
	a_Inimigo2 = 450;
	b_Inimigo2 = 50;
	aIni3 = 300;
	bIni3 = 100;
	xBoss = 300;
	yBoss = 50;

	velocidade = 1;
}

void Inimigo::setSpriteSheet(string spritesheet)
{
	spr_inimigo.setSpriteSheet(spritesheet);
	
	
}

void Inimigo::setSptitesheetBoss(string spriteheetBoss)
{
	spr_boss.setSpriteSheet(spriteheetBoss);
}

//Neste método fazemos toda a movimentação dos Inimigos
void Inimigo::atualizar()
{		
   if(vivoIni)
   {
	   // calculo para movimentação
	   //mesmo uso ns demais
	   y_Inimigo1 += velocidade;
   }
   if(vivoIni2)
   {
	   b_Inimigo2 += velocidade;
   }
   if (vivoIni3)
   {
	   bIni3 += velocidade;
   }
   if (vivoBoss)
   {   
	   xBoss += velocidade;
	   if (xBoss == 500)
	   {
		   //quando o Boss chegar nesta posição de x
		   //ele troca a velocidade
		   //e o Boss muda de direcao
		   velocidade = -1;
		   xBoss += velocidade;

	   }
	   if (xBoss == 100)
	   {
		   velocidade = 1;
		   xBoss += velocidade;
			   
	   }
   }
}

void Inimigo::desenhar()
{
	//desenha somente se Vivo
	//não deixa com que o obj fique desenhado na tela
	if (vivoIni)
	{
		spr_inimigo.desenhar(x_Inimigo1, y_Inimigo1);
		
	}
	if (vivoIni2)
	{
		spr_inimigo.desenhar(a_Inimigo2, b_Inimigo2);
	}
	
}

//Novo metodo desenhar somente para o Inimigo 3 para evitar problemas
//(pois ele é desenhado separado, em um momento diferente)
void Inimigo::desenharInimigo3()
{
	if (vivoIni3)
	{
		spr_inimigo.desenhar(aIni3, bIni3);
	}
}

void Inimigo::desenharBoss()
{
	if (vivoBoss)
	{
		spr_boss.desenhar(xBoss, yBoss);
	}
}

bool Inimigo::getVivo()
{
	return vivoIni;
}
//Mudando a Vida para false com isso ele morre
void Inimigo::morrer()
{
	//O inimigo Morre e sua posição volta a antiga
	vivoIni = false;
	this->x_Inimigo1 = 200;
	this->y_Inimigo1 = 50;	
}

void Inimigo::morrer2()
{   
	//O inimigo Morre e sua posição volta a antiga
	vivoIni2 = false;
	this->a_Inimigo2 = 450;
	this->b_Inimigo2 = 50;
}


void Inimigo::morrer3()
{
	vivoIni3 = false;
}

void Inimigo::morrerBoss()
{
	vivoBoss = false;
}


int Inimigo::getXIni()
{
	//evita colisões no invisível
	//assim para todos os demais
	if (vivoIni)
	{
		return x_Inimigo1;
	}
}

int Inimigo::getYIni()
{
	if (vivoIni)
	{
		return y_Inimigo1;
	}
	
}

int Inimigo::getAIni2()
{
	if (vivoIni2)
	{
		return a_Inimigo2;
	}
}

int Inimigo::getBIni2()
{
	if (vivoIni2)
	{
		return b_Inimigo2;
	}
	
}

int Inimigo::getxBoss()
{
	if(vivoBoss)
	{
		return xBoss;
	}
	
}

int Inimigo::getyBoss()
{
	if (vivoBoss)
	{
		return yBoss;
	}

}

int Inimigo::getAIni3()
{
	if (vivoIni3)
	{
		return aIni3;
	}
}

int Inimigo::getBIni3()
{
	if (vivoIni3)
	{
		return bIni3;
	}
}

int Inimigo::nivel()
{
	//quando chamado passa o nível atual +1
	return Nivel+1;
}


Sprite Inimigo::getSpriteInimigo()
{
	return spr_inimigo;
}

Sprite Inimigo::getSpriteBoss()
{
	return spr_boss;
}
