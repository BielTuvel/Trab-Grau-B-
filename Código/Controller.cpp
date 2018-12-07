#include "Controller.h"

Controller::Controller()
{
	//Iniciando os objetos
	mapa = new Mapa();
	player = new Nave();
	powerUp = new PowerUp();
	powerDown = new PowerUp();
	enemy = new Inimigo();
	boss = new Inimigo();
	
}

Controller::~Controller()
{
}

void Controller::inicializar()
{
	//Setando a fonte para escrever
	texto_Pontuacao.setFonte("Score");
	texto_Nivel.setFonte("Score");
	
	//Colocando cor das palavras
	texto_Pontuacao.setCor(0, 191, 255);
	texto_Nivel.setCor(0, 191, 255);

	//Setando o que vai aparecer na tela por padrão
	texto_Pontuacao.setString("Score: ");
	texto_Nivel.setString("Nível 1");
	
	//Setando os sprites para os objetos de jogo
	player->setSpriteSheet("Nave");
	mapa->setSpriteSheet("Mapa");
	powerUp->setSpriteSheet_PowerUp("powerUp");
	powerDown->setSpriteSheet_PowerUp("Desabilita");

	//Métodos inicializar
	enemy->inicializar();
	boss->inicializar();
	player->inicializaTiro();
}

//Método que executa os testes de colisões do player e inimigos
void Controller::testarColisoes()
{
	//Caso o tiro do player colida com o sprite do inimigo >>		
	if (uniTestarColisaoSpriteComSprite(player->getSpriteTiro(), player->getXtiro(), player->getYtiro(), 0, enemy->getSpriteInimigo(), enemy->getXIni(), enemy->getYIni(), 0, true))
	{
		//O tiro "morre" e o inimigo também
		player->matarTiro();
		enemy->morrer();
		//Acrescentando a pontuacao do Player
		player->pontuacao++;
		
		//Convertando um int para colocar ao lado da String Score
		texto_Pontuacao.setString("Score: " + to_string(player->pontuacao));
		
	}
	
	if (uniTestarColisaoSpriteComSprite(player->getSpriteTiro(), player->getXtiro(), player->getYtiro(), 0, enemy->getSpriteInimigo(), enemy->getAIni2(), enemy->getBIni2(), 0, true))
	{

		player->matarTiro();
		enemy->morrer2();
		player->pontuacao++;
		texto_Pontuacao.setString("Score: " + to_string(player->pontuacao));
		
	}
	if (uniTestarColisaoSpriteComSprite(player->getSpriteTiro(), player->getXtiro(), player->getYtiro(), 0, enemy->getSpriteInimigo(), enemy->getAIni3(), enemy->getBIni3(), 0, true))
	{
		player->matarTiro();
		enemy->morrer3();
		player->pontuacao++;
		texto_Pontuacao.setString("Score: " + to_string(player->pontuacao));
	}
	//Colisão da Nave com o PowerUp >>
	if (uniTestarColisaoSpriteComSprite(player->getSpriteNave(), player->getXNave(), player->getYNave(), 0, powerUp->getSpriteSheet_PowerUp(), powerUp->getXPowerUp(), powerUp->getYPowerUp(), 0, true))
	{
		//atualiza o tiro do PowerUp
		player->atualizar_o_Tiro();
		//Faz com que o powerUp receba false e suma
		powerUp->Some_PowerUp();
	}
	//Colisão da Nave com o PowerDown >>
	if (uniTestarColisaoSpriteComSprite(player->getSpriteNave(), player->getXNave(), player->getYNave(), 0, powerDown->getSpriteSheet_Desabilita(), powerDown->getAdesabilita(), powerDown->getBdesabilita(), 0, true))
	{
		//atualiza o tiro - fazendo ele voltar ao valor anterior
		player->voltar_ao_Tiro();
		//faz com que o PowerUp volte a aparecer recebendo true
		powerUp->sumir = true;
	}
	//Colisão da Nave com o Boss >>
	if (uniTestarColisaoSpriteComSprite(player->getSpriteTiro(), player->getXtiro(), player->getYtiro(), 0, boss->getSpriteBoss(), boss->getxBoss(), boss->getyBoss(), 0, true))
	{
		player->matarTiro();
		//mata o boss - false
		boss->morrerBoss();
		player->pontuacao++;
		texto_Pontuacao.setString("Score: " + to_string(player->pontuacao));
	}
	//Colisões da Nave com os Inimigos >>
	if(uniTestarColisaoSpriteComSprite(player->getSpriteNave(),player->getXNave(),player->getYNave(),0,enemy->getSpriteInimigo(),enemy->getXIni(),enemy->getYIni(),0,true))
	{
		//Nave recebe false e morre
		player->morrer_Nave();
		//setVidaNave recebe o valor de player->Vivo_Nave
		setVidaNave = player->Vivo_Nave;
	}
	if (uniTestarColisaoSpriteComSprite(player->getSpriteNave(), player->getXNave(), player->getYNave(), 0, enemy->getSpriteInimigo(), enemy->getAIni2(), enemy->getBIni2(), 0, true))
	{
		player->morrer_Nave();
		setVidaNave = player->Vivo_Nave;
	}
	if (uniTestarColisaoSpriteComSprite(player->getSpriteNave(), player->getXNave(), player->getYNave(), 0, enemy->getSpriteInimigo(), enemy->getAIni3(), enemy->getBIni3(), 0, true))
	{
		player->morrer_Nave();
		setVidaNave = player->Vivo_Nave;
	}
	if (uniTestarColisaoSpriteComSprite(player->getSpriteNave(), player->getXNave(), player->getYNave(), 0, boss->getSpriteBoss(), boss->getxBoss(), boss->getyBoss(), 0, true))
	{
		player->morrer_Nave();
		setVidaNave = player->Vivo_Nave;
	}
}

//Método para obter a pontução do player
int Controller::obterPontuacao()
{
	return player->pontuacao;
}

//Este método, tem como função passar os níveis do jogo
void Controller::controlaNiveis()
{	
	if (player->pontuacao == 2)
	{
		//aqui quando a pontuação do player for dois,
		//ele revive os inimigos e coloca um novo inimigo na tela
		//também escreve na tela aumentando a variavel nível
		texto_Nivel.setString("Nível " + to_string(enemy->nivel()));
		enemy->vivoIni = true;
		enemy->vivoIni2 = true;
		enemy->vivoIni3 = true;
	
	}
	else if(player->pontuacao == 5 || player->pontuacao == 6)
	{
		//momento do boss
		//quando a pontuação chegar a 5 o boss aparece
		//entretanto se o player consuguir 6 antes de atirar no boss
		//o boss morre com somente um tiro
		texto_Nivel.setString("Nível " + to_string(enemy->nivel() + 1));
		boss->vivoBoss = true;
		boss->desenharBoss();
		boss->atualizar();
	}
	else if(enemy->y_Inimigo1 == 700 || enemy->b_Inimigo2 == 700 || enemy->bIni3 == 700 && player->pontuacao < 5 )
	{
		//para os inimigos ficarem passando na tela e voltando
		//na primeira vez que se faz isso se aumenta um nível

		texto_Nivel.setString("Nível " + to_string(enemy->nivel()));
		enemy->morrer();
		enemy->morrer2();
		
		enemy->vivoIni = true;
		enemy->vivoIni2 = true;
		
	}
}

void Controller::controlaGameOver()
{
	//chamando todos os metodos necessários para fazer a "volta" do gameover
	//com isso ele reinicializa todos os metodos, variaveis...
	//fazendo com que as condições de vida, nivel, pontuaçao...
	//sejam novamente atendidas
	//portanto podendo fazer um "circulo completo" no gameover.
	inicializar();
	player->pontuacao = 0;
	player->Vivo_Nave = true;
	player->x = 300;
	powerUp->sumir = true;
	player->y = 400;
	player->atualizar();
	enemy->atualizar();
	testarColisoes();
	controlaNiveis();
	setVidaNave = true;
	enemy->desenharInimigo3();
}

bool Controller::getVidaNave()
{
	return setVidaNave;
}

bool Controller::getVidaBoss()
{
	return boss->vivoBoss;
}

//Método que executa todas as funções que precisam ser chamadas constantemente
void Controller::atualizar()
{
	//OBS: Essa função é chamada no EXECUTAR do jogo.cpp
	mapa->desenhar();
	player->atualizar();
	enemy->atualizar();
	player->desenhar();
	enemy->desenhar();
	enemy->desenharInimigo3();
	powerUp->desenhar();
	powerDown->desenhar_PowerUp2();
	testarColisoes();
	controlaNiveis();
	//Desenhando o texto na tela
	texto_Pontuacao.desenhar(100, 30);
	texto_Nivel.desenhar(500,30);
}