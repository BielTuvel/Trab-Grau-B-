#include "Jogo.h"
#include "Nave.h"
#include "Controller.h"

Jogo::Jogo()
{
}

Jogo::~Jogo()
{
}

void Jogo::inicializar()
{
	uniInicializar(600, 451, false, "Space Destruction");
	
	//Carregando as fontes
	gRecursos.carregarFonte("Score", "assets/fontes/fonte_padrao.ttf", 32);
	gRecursos.carregarFonte("Login", "assets/fontes/loginFont.ttf", 16);
	

	Tela = new Menu();
	carregaAssets = new CarregadorDeAssets();
	//carrega os assets do jogo
	carregaAssets->testeSeCarregou();
	//inicializa o menu
	Tela->inicializar_asset();
}

void Jogo::finalizar()
{
	carregaAssets->destroiTodosAseets();
	Tela->finalizarMenu();
	uniFinalizar();
}

void Jogo::executar()
{
	while(!gTeclado.soltou[TECLA_ESC] && !gEventos.sair)
	{
		uniIniciarFrame();
		uniTerminarFrame();
		//atualiza tela atual a cada frame
		Tela->atualizarTelaAtual();
	}
}