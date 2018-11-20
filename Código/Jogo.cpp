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
	uniInicializar(600, 451, false, "Airplane");
	//Carregando a fonte, coloca lá no carregador pra nós Felipe, é isto.
	gRecursos.carregarFonte("Score", "assets/fontes/fonte_padrao.ttf", 32);

	menuzao = new Menu();
	carregaAssets = new CarregadorDeAssets();
	//carrega os assets do jogo
	carregaAssets->testeSeCarregou();
	//inicializa o menu
	menuzao->inicializar_asset();



	
}

void Jogo::finalizar()
{
	carregaAssets->destroiTodosAseets();
	uniFinalizar();
}

void Jogo::executar()
{
	while(!gTeclado.soltou[TECLA_ESC] && !gEventos.sair)
	{
		uniIniciarFrame();
		uniTerminarFrame();
		//atualiza tela atual a cada frame
		menuzao->atualizarTelaAtual();
	}
}