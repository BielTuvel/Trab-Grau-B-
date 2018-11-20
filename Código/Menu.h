#pragma once
#include<iostream>
#include "libUnicornio.h"
#include<stack>
#include "Controller.h"
enum MENU
{
	MAIN,
	JOGAR,
	LOGIN,
	CADASTRAR,
	LOGAR,
	LEADERBOARD,
	CREDITS

};



class Menu
{
public:
	std::stack <MENU> MenuStack; 
	Menu();
	~Menu();

	Sprite spr, spr2;
	Controller * control;

	void atualizarTelaAtual();
	void inicializar_asset();
	void atualizar_menu();
	void atualizar_jogar();
	void atualizar_leaderboard();
	void atualizar_credits();
	void atualizar_jogo();
	void atalizar_login();
	void atualiar_cadastro();
	void atualizar_logar();
	void setSpriteSheet(string spritesheet);

	//Botões do Tipo BotaoSprite
	BotaoSprite botaoStart, botaoCarregar, botaoRanking, botaoCreditos, botaoSair;
	
};

