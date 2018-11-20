#include "Menu.h"
#include "libUnicornio.h"


Menu::Menu()
{
	MenuStack.push(MAIN);
}


Menu::~Menu()
{
}


void Menu::atualizarTelaAtual()
{
	switch (MenuStack.top())
	{
	case MAIN:
		atualizar_menu();
		break;
	case JOGAR:
		atualizar_jogar();
		break;
	case LOGIN:
		atalizar_login();
		break;
	case CADASTRAR:
		atualiar_cadastro();
		break;
	case LOGAR:
		atualizar_logar();
	case LEADERBOARD:
		atualizar_leaderboard();
		break;
	case CREDITS:
		atualizar_credits();
		break;
	default:
		break;
	}
}

void Menu::inicializar_asset()
{
	control = new Controller();
	gRecursos.carregarSpriteSheet("fundoMenu", "assets/mapa/anal.png");
	spr.setSpriteSheet("fundoMenu");
	gRecursos.carregarSpriteSheet("logo", "assets/mapa/logo.png");
	spr2.setSpriteSheet("logo");
	
	//Botões
	//Carregando
	gRecursos.carregarSpriteSheet("start", "assets/spritesheets/botoes/novoJogo.png");
	gRecursos.carregarSpriteSheet("carregar", "assets/spritesheets/botoes/carregarJogo.png");
	gRecursos.carregarSpriteSheet("ranking", "assets/spritesheets/botoes/ranking.png");
	gRecursos.carregarSpriteSheet("creditos", "assets/spritesheets/botoes/creditos.png");
	gRecursos.carregarSpriteSheet("sair", "assets/spritesheets/botoes/sair.png");
	//Setando Sprite
	botaoCarregar.setSpriteSheet("carregar");
	botaoStart.setSpriteSheet("start");
	botaoRanking.setSpriteSheet("ranking");
	botaoCreditos.setSpriteSheet("creditos");
	botaoSair.setSpriteSheet("sair");
	//Setando Posição
	botaoStart.setPos(300, 300);
	botaoCarregar.setPos(300, 326);
	botaoRanking.setPos(300, 353);
	botaoCreditos.setPos(300, 379);
	botaoSair.setPos(300, 405);

	control->inicializar();
}

void Menu::atualizar_menu()
{
	spr.desenhar(300, 230);
	spr2.desenhar(300, 100);
	//Desenhando e Atualizando botões
	botaoStart.desenhar();
	botaoStart.atualizar();
	botaoCarregar.desenhar();
	botaoCarregar.atualizar();
	botaoRanking.desenhar();
	botaoRanking.atualizar();
	botaoCreditos.desenhar();
	botaoCreditos.atualizar();
	botaoSair.desenhar();
	botaoSair.atualizar();

	//Se o botão botaoStart for clicado >>
	if (botaoStart.estaClicado()) 
	{
		spr.desenhar(300, 230);
		MenuStack.push(JOGAR);
	}

	if (botaoCreditos.estaClicado()) 
	{
		spr.desenhar(300, 230);
		MenuStack.push(CREDITS);
	}
}

void Menu::atualizar_jogar() 
{
	control->atualizar();
	if (gTeclado.pressionou[TECLA_2])
	{
		MenuStack.pop();
	}
}

void Menu::atualizar_leaderboard()
{

}

void Menu::atualizar_credits()
{
	//Só um teste pra ver se foi pro credits mesmo
	botaoCreditos.desenhar();
	if (gTeclado.pressionou[TECLA_2])
	{
		MenuStack.pop();
	}
}

void Menu::atualizar_jogo()
{
}

void Menu::atalizar_login()
{
}

void Menu::atualiar_cadastro()
{
}

void Menu::atualizar_logar()
{
}

void Menu::setSpriteSheet(string spritesheet)
{
	spr.setSpriteSheet(spritesheet);
}