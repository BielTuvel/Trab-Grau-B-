#pragma once
#include "Nave.h"
#include "Mapa.h"
#include "Inimigo.h"
#include "Tiro.h"
#include "PowerUp.h"
#include "ContaUsuario.h"

class Controller
{
private:
	//Objetos
	Mapa * mapa;
	Nave * player;
	Inimigo * enemy;
	Inimigo * boss;
	PowerUp * powerUp;
	PowerUp * powerDown;
	
	//Textos
	Texto texto_Pontuacao;
	Texto texto_Nivel;
	
	//Método que puxa a condição de vida da Nave
	bool setVidaNave;
	
public:

	Controller();
	~Controller();

	void atualizar();
	void inicializar();
	void testarColisoes();
	int obterPontuacao();
	void controlaNiveis();
	void controlaGameOver();
	bool getVidaNave();
	bool getVidaBoss();
};