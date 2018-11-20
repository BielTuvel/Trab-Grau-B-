#include "Controller.h"

Controller::Controller()
{
	mapa = new Mapa();
	player = new Nave();
	enemy = new Inimigo();
	
}

Controller::~Controller()
{
}

void Controller::inicializar()
{
	//Setando a fonte para escrever
	texto.setFonte("Score");
	//Colocando cor da palavra (isso não foi enviado ao felipe)
	texto.setCor(0, 191, 255);
	//Escrevendo o que vai aparecer na tela por padrão
	texto.setString("Score: ");
	
	player->setSpriteSheet("Nave");
	mapa->setSpriteSheet("Mapa");
	enemy->inicializar();
	player->inicializaTiro();
}

void Controller::testarColisoes()
{
		
	if (uniTestarColisaoSpriteComSprite(player->getSproteTiro(), player->getXtiro(), player->getYtiro(), 0,enemy->getSpriteInimigo(), enemy->getXIni(), enemy->getYIni(),0,true))
	{
		
		player->matarTiro();
		enemy->morrer();
		//Acrescentando a pontuacao do Player
		player->pontuacao++;
		//Convertando um int para colocar ao lado da String Score
		texto.setString("Score: " + to_string(player->pontuacao));
		
	}
	
}

void Controller::atualizar()
{

	mapa->desenhar();
	player->atualizar();
	enemy->atualizar();
	player->desenhar();
	enemy->desenhar();
	testarColisoes();
	//Desenhando o texto na tela (na posição correta)
	texto.desenhar(100, 30);
}