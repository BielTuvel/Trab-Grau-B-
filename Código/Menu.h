#pragma once
#include<iostream>
#include "libUnicornio.h"
#include<stack>
#include "Controller.h"
#include "InputTexto.h"
#include <fstream>
#include "ContaUsuario.h"
#include "GerenciadorContas.h"
#include <deque>
#include "Nave.h"

//ENUM do Menu Principal e do Login
enum MENU
{
	MAIN,
	JOGAR,
	MENU_LOGAR,
	CADASTRAR,
	LOGAR,
	LEADERBOARD,
	CREDITS,
	GAMEOVER,
	CARREGAR,
	VITORIA

};

//ENUM para Status de Escrita do Login e Cadastro
enum STATUS
{
	USER,
	PSSW,
	CONFIRM,
	LOGADO
};

class Menu
{
public:
	
	Menu();
	~Menu();
	
	//Pilhas
	std::stack <MENU> MenuStack;
	std::stack <STATUS> CadastroMenu;
	std::stack <STATUS> LoginMenu;

	//Sprites 
	Sprite spr, spr2, campoLogin, gameOver, telaDeCarregar;
	//Controlador
	Controller * control;
	
	//Funções da Tela
	void atualizarTelaAtual();
	void inicializar_asset();
	void atualizar_menu();
	void atualizar_jogar();
	void atualizar_leaderboard();
	void atualizar_credits();
	void atalizar_login();
	void atualizar_carregar();
	void atualiar_cadastro();
	void atualizar_logar();
	void setSpriteSheet(string spritesheet);
	void finalizarMenu();
	void GameOver();
	void vitoria();
	//Função de Créditos
	void creditos();
	//Função de organização do Ranking
	void testeRanking(std::string usuario, int pontos, fstream & arquivo);
	
	//Arquivos
	fstream arqRanking;
	fstream userEsenha;
	
	//Login
	ContaUsuario * conta;
	GerenciadorContas * gerenteConta;

	//Botões do Tipo BotaoSprite
	BotaoSprite botaoStart, botaoCarregar, botaoRanking, botaoCreditos, botaoSair;
	BotaoSprite botaoCadastrar, botaoLogar;

	//Textos
	Texto pontuacaoMax;
	Texto logSucess;
	Texto welcome;
	Texto listaRank[6];
	Texto leaderBoard;
	Texto rankPositions[6];
	InputTexto input;
	Texto escritaCreditos;
	Texto venceu;

	//Variáveis do Usuario
	std::string senha;
	std::string username;
	std::string confSenha;
	int pontuacao;
};

