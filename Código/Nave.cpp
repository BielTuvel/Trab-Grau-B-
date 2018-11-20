#include "Nave.h"

Nave::Nave()
{
	x = 300;
	y = 400;
	//Pontuacao iniciando em zero pra não bugar
	pontuacao = 0;
}

Nave::~Nave()
{
}

void Nave::setSpriteSheet(string spritesheet)
{
	sprite.setSpriteSheet(spritesheet);
	
}

void Nave::atualizar()
{
	bool andou = false;


	////se a sprite estiver virada pra esquerda
	////esquerda
	//sprite.setInverterX(false);
	////direita
	//sprite.setInverterX(true);

	
	if (gTeclado.segurando[TECLA_ESQ] && x > 20)
	{
		andou = true;	// altera o status de andou
		direcao = 1;	// direção para onde o personagem vai se mover
		x--;			// x-- faz com que a posição se altere no eixo
		sprite.setAnimacao(0);		// pega a 3a linha da sprite de personagem
		sprite.avancarAnimacao();	// faz a animacao do personagem
	}
	if (gTeclado.segurando[TECLA_DIR] && x < 590 )
	{
		andou = true;
		direcao = 1;
		x++;
		sprite.setAnimacao(0);
		sprite.avancarAnimacao();
	}
	if (gTeclado.segurando[TECLA_CIMA] && y > 40)
	{
		andou = true;
		direcao = 1;
		y--;
		sprite.setAnimacao(0);
		sprite.avancarAnimacao();
	}
	if (gTeclado.segurando[TECLA_BAIXO] && y < 430)
	{
		andou = true;
		direcao = 1;
		y++;
		sprite.setAnimacao(0);
		sprite.avancarAnimacao();
	}
	if (gTeclado.pressionou[TECLA_ESPACO] && tiro.getVivo() == false)
	{
		tiro.disparar(x, y,direcao);

	}
	tiro.atualizar();
	if (!andou)
	{
		if (direcao == 1) // esquerda
			sprite.setFrame(0);
		else
			sprite.setFrame(1);
	}

	
	
}

void Nave::desenhar()
{
	
	sprite.desenhar(x,y);
	tiro.desenhar();
}

void Nave::matarTiro()
{
	tiro.morrer();
}

Sprite Nave::getSproteTiro()
{
	return tiro.getSprite();
}

int Nave::getXtiro()
{
	return tiro.getX();
}

int Nave::getYtiro()
{
	return tiro.getY();
}

void Nave::inicializaTiro()
{
	tiro.inicializar();
}


Sprite Nave::getSpriteNave()
{
	return sprite;
}

