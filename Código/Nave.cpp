#include "Nave.h"

Nave::Nave()
{
	x = 300;
	y = 400;
	speed = 2.0;
	Vivo_Nave = true;
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
	//isto so ocorre se a Nave estiver "Viva"
	if (Vivo_Nave)
	{
		if (gTeclado.segurando[TECLA_ESQ] && x > 20)
		{
			andou = true;	// altera o status de andou
			direcao = 1;	// direção para onde o personagem vai se mover
			x -= speed;			// x-- faz com que a posição se altere no eixo
			sprite.setAnimacao(0);		// pega a 3a linha da sprite de personagem
			sprite.avancarAnimacao();	// faz a animacao do personagem
		}
		if (gTeclado.segurando[TECLA_DIR] && x < 590)
		{
			andou = true;
			direcao = 1;
			x += speed;
			sprite.setAnimacao(0);
			sprite.avancarAnimacao();
		}
		if (gTeclado.segurando[TECLA_CIMA] && y > 40)
		{
			andou = true;
			direcao = 1;
			y -= speed;
			sprite.setAnimacao(0);
			sprite.avancarAnimacao();
		}
		if (gTeclado.segurando[TECLA_BAIXO] && y < 430)
		{
			andou = true;
			direcao = 1;
			y += speed;
			sprite.setAnimacao(0);
			sprite.avancarAnimacao();
		}
		if (gTeclado.pressionou[TECLA_ESPACO] && tiro.getVivo() == false)
		{
			tiro.disparar(x, y, direcao);

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
	
	
	
}

void Nave::desenhar()
{
	//só desenha a Nave na tela se ela estiver Viva
	//Por isso ela some quando está morta
	if (Vivo_Nave)
	{
		sprite.desenhar(x, y);
		tiro.desenhar();
	}
	
}

void Nave::matarTiro()
{
	tiro.morrer();
}

Sprite Nave::getSpriteTiro()
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

int Nave::getXNave()
{
	//evita colisões no invisível
	//assim para todos os demais
	if (Vivo_Nave)
	{
		return x;
	}
	
}

int Nave::getYNave()
{
	if (Vivo_Nave)
	{
		return y;
	}
	
}

//método para mudar a vida da Nave - true - false
bool Nave::morrer_Nave()
{
	Vivo_Nave = false;
	return Vivo_Nave;
}

void Nave::inicializaTiro()
{
	tiro.inicializar();
}

void Nave::atualizar_o_Tiro()
{
	tiro.velocidade = -10;
	tiro.atualizar();
}

void Nave::voltar_ao_Tiro()
{
	tiro.velocidade = -2;
	tiro.atualizar();
}

Sprite Nave::getSpriteNave()
{
	return sprite;
}

