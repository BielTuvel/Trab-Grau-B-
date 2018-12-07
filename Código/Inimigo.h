#pragma once
#include "libUnicornio.h"
#include "Sprite.h"
#include <ctime>

//COMENTA AI FELIPE
class Inimigo
{

private:

	int velocidade;
	
	Sprite spr_inimigo;
	Sprite spr_boss;
	
public:
	Inimigo();
	~Inimigo();

	int x_Inimigo1, y_Inimigo1, direcao;
	int a_Inimigo2, b_Inimigo2, direcao2;
	int aIni3, bIni3, direcao3;
	int xBoss, yBoss, direcaoBoss; 
	bool vivoIni;
	bool vivoIni2;
    bool vivoIni3;
	bool vivoBoss;
	int Nivel = 1;

	void inicializar();
	void setSpriteSheet(string spritesheet);
	void setSptitesheetBoss(string spriteheetBoss);
	void atualizar();
	void desenhar();
	void desenharInimigo3();
	void desenharBoss();
	bool getVivo();
	void morrer();
	void morrer2();
	void morrer3();
	void morrerBoss();
	int getXIni();
	int getYIni();
	int getAIni2();
	int getBIni2();
	int getxBoss();
	int getyBoss();
	int getAIni3();
	int getBIni3();
	int nivel();
	
	Sprite getSpriteInimigo();
	Sprite getSpriteBoss();
};


