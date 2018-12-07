#include "Menu.h"
#include "libUnicornio.h"

Menu::Menu()
{
	
	//Setando as primeiras telas de cada Stack
	MenuStack.push(MENU_LOGAR);
	CadastroMenu.push(USER);
	LoginMenu.push(USER);

	//Zerando os valores de vari�veis
	pontuacao = 0;
	username = "";
	senha = "";
	logSucess.setString("");
}

Menu::~Menu()
{
	
}

//Switch case para fazer a troca de menus
void Menu::atualizarTelaAtual()
{
	/* Recebendo sempre o topo da Pilha
	Pra cada CASE, uma fun��o � executada
	Dentro delas est�o as execu��es de cada tela/menu */
	switch (MenuStack.top())
	{
	case MAIN:
		atualizar_menu();
		break;
	case JOGAR:
		atualizar_jogar();
		break;
	case MENU_LOGAR:
		atalizar_login();
		break;
	case CADASTRAR:
		CadastroMenu.top();
		atualiar_cadastro();
		break;
	case LOGAR:
		LoginMenu.top();
		atualizar_logar();
		break;
	case LEADERBOARD:
		atualizar_leaderboard();
		break;
	case CREDITS:
		atualizar_credits();
		break;
	case GAMEOVER:
		GameOver();
		break;
	case CARREGAR:
		atualizar_carregar();
		break;
	case VITORIA:
		vitoria();
	default:
		break;
	}
}

void Menu::inicializar_asset()
{
	//Iniciando objetos
	conta = new ContaUsuario;
	gerenteConta = new GerenciadorContas;
	control = new Controller();


	//Os primeiros carregamentos s�o os de arquivos
	//Primeiro o arquivo do Ranking depois Login
	arqRanking.open("ranking.txt", ios::in);
	gerenteConta->inserirRanking(arqRanking, gerenteConta);
	arqRanking.close();
	
	userEsenha.open("info.bin", std::ios::binary | ios::in);
	gerenteConta->inserirPorArquivo(userEsenha, gerenteConta, conta);
	userEsenha.close();

	//Carregando m�sicas
	gRecursos.carregarMusica("menuTheme", "assets/sons/feelgood.mp3");
	gRecursos.carregarMusica("InGame", "assets/sons/ingame.mp3");
	gRecursos.carregarMusica("creditos", "assets/sons/credits.mp3");

	//BOTA LA FELIPE
	gRecursos.carregarSpriteSheet("GameOver", "assets/spritesheets/gameOver.png");
	gRecursos.carregarSpriteSheet("CarregarJogo", "assets/spritesheets/daciolo.png");
	
	
	//Setando as fontes para seus textos
	pontuacaoMax.setFonte("Score");
	logSucess.setFonte("Login");
	welcome.setFonte("Login");
	leaderBoard.setFonte("Score");
	venceu.setFonte("Score");
	
	//FOR para setar a fonte de toda a lista do ranking
	for (int i = 1; i < 6; i++)
	{
		listaRank[i].setFonte("Score");
	}
	//Aqui setando fonte e cor para as posi��es do ranking
	for (int i = 1; i < 6; i++)
	{
		rankPositions[i].setFonte("Score");
		rankPositions[i].setCor(178, 34, 34);
	}
	
	//Setando String e Cor para o titulo do Ranking
	leaderBoard.setString("Leaderboard");
	leaderBoard.setCor(178, 34, 34);
	
	//Setando sprites para bot�es, fundo, logo e etc.
#pragma region SetandoAsSprites
	//Carregados por arquivos
	spr.setSpriteSheet("fundoMenu");
	spr2.setSpriteSheet("logo");
	campoLogin.setSpriteSheet("CampoUser");
	gameOver.setSpriteSheet("GameOver");
	botaoCarregar.setSpriteSheet("carregar");
	botaoStart.setSpriteSheet("start");
	botaoRanking.setSpriteSheet("ranking");
	botaoCreditos.setSpriteSheet("creditos");
	botaoSair.setSpriteSheet("sair");
	botaoCadastrar.setSpriteSheet("cadastrar");
	botaoLogar.setSpriteSheet("logar");
#pragma endregion

	//Setando Posi��es dos Bot�es
#pragma region SetandoAsPosi��es
	botaoStart.setPos(300, 300);
	botaoCarregar.setPos(300, 326);
	botaoRanking.setPos(300, 353);
	botaoCreditos.setPos(300, 379);
	botaoSair.setPos(300, 405);
	botaoCadastrar.setPos(150, 353);
	botaoLogar.setPos(450, 353);
#pragma endregion

	//Inicializando m�todos "Inicializar" dos objetos
	input.inicializar(); //Escrita
	control->inicializar(); //Tela de Jogo
}

void Menu::atualizar_menu()
{
	//Toca a m�sica do menu principal
	if (!gMusica.estaTocando())
	{
		gMusica.tocar("menuTheme", true);
	}

	//Desenhando e Atualizando bot�es e spr/spr2
#pragma region Desenhar&Atualizar_tudo
	spr.desenhar(300, 230);
	spr2.desenhar(300, 100);
	//Boas vindas ao User logado
	welcome.setString("Bem vindo, " + username + "!");
	welcome.desenhar(300, 240);
	botaoStart.desenhar();
	botaoStart.atualizar();
	botaoCarregar.atualizar();
	botaoRanking.desenhar();
	botaoRanking.atualizar();
	botaoCarregar.desenhar();
	botaoCreditos.desenhar();
	botaoCreditos.atualizar();
	botaoSair.desenhar();
	botaoSair.atualizar();
#pragma endregion

	//Condi��es para cada bot�o ao serem clicados
	if (botaoStart.estaClicado())
	{
		gMusica.pausar();
		spr.desenhar(300, 230);
		MenuStack.push(JOGAR);
	}

	if (botaoCreditos.estaClicado())
	{
		gMusica.pausar();
		spr.desenhar(300, 230);
		MenuStack.push(CREDITS);
	}

	if (botaoSair.estaClicado())
	{
		gEventos.sair = true;
	}

	if (botaoRanking.estaClicado())
	{
		spr.desenhar(300, 230);
		MenuStack.push(LEADERBOARD);
	}

	if (botaoCarregar.estaClicado())
	{
		spr.desenhar(300, 230);
		MenuStack.push(CARREGAR);
	}

}

void Menu::atualizar_jogar()
{
	//Chama o m�todo de atualizar da tela de Jogo
	control->atualizar();
	//Uma vari�vel que puxa a pontua��o atual do Player
	pontuacao = control->obterPontuacao();
	
	//Caso o Player esteja morto, coloca a tela de GAME OVER
	if (!control->getVidaNave()) 
	{
		MenuStack.push(GAMEOVER);
	}
	//se o boss estiver como false e a pontua��o do player for >= 7
	//colocamos a tela de VITORIA no topo
	if(!control->getVidaBoss()&& control->obterPontuacao() >= 7) 
	{
		MenuStack.push(VITORIA);
	}

	//tocando a m�sica da tela de jogo
	if (!gMusica.estaTocando())
	{
		gMusica.tocar("InGame", true);
	}

	//Apertando 2 retorna
	if (gTeclado.pressionou[TECLA_2])
	{
		gMusica.pausar();
		MenuStack.pop();
	}
}

void Menu::atualizar_leaderboard()
{
	//Desenha titulo do Ranking
	leaderBoard.desenhar(300, 35);
	
	//Posi��es padr�es dos N�meros e dos Players do Ranking
	int posY = 380;
	int posYrank = 100;

	for (int i = 1; i < 6; i++)
		{
			//N�meros de indice v�o para a tela como posi��es do ranking
			rankPositions[i].desenhar(50, posYrank);
			rankPositions[i].setString(to_string(i) + ".");
			//Alterando a posi��o em Y
			posYrank += 70;
		}

		//Chamando o iterador da Hash e dando um valor de Inicio (inicio da hash)
		gerenteConta->it_ranking = gerenteConta->rankPontuacao.begin();

		//Esse FOR serve para imprimir na tela os Player e Pontua��es do Ranking
	for (int i = 5; i > 0; i--)
		{
				listaRank[i].desenhar(300, posY);
				listaRank[i].setString(gerenteConta->it_ranking->second + " - " + to_string(gerenteConta->it_ranking->first));
				gerenteConta->it_ranking++;
				//Alterando a posi��o em Y
				posY -= 70;
		}

	//Sair da Tela
	if (gTeclado.pressionou[TECLA_2])
	{
		MenuStack.pop();
	}
}

void Menu::atualizar_credits()
{
	//Toca a m�sica de cr�ditos
	if (!gMusica.estaTocando())
	{
		gMusica.tocar("creditos", true);
	}
	
	//Escrita dos cr�ditos
	creditos();

	//Sair da tela
	if (gTeclado.pressionou[TECLA_2])
	{
		gMusica.pausar();
		MenuStack.pop();
	}
}

void Menu::atalizar_login()
{
	//PRIMEIRA TELA do Jogo
	//Desenha fundo e logo
	spr.desenhar(300, 230);
	spr2.desenhar(300, 100);

	//Bot�es de cadastrar ou logar
	botaoCadastrar.desenhar();
	botaoCadastrar.atualizar();
	botaoLogar.desenhar();
	botaoLogar.atualizar();

	//Condi��es para clique nos bot�es
	if (botaoCadastrar.estaClicado())
	{
		spr.desenhar(300, 230);
		MenuStack.push(CADASTRAR);
	}
	if (botaoLogar.estaClicado())
	{
		spr.desenhar(300, 230);
		MenuStack.push(LOGAR);
	}
}

void Menu::atualizar_carregar()
{
	//Desenhando Sprites
	spr.desenhar(300, 230);
	telaDeCarregar.setSpriteSheet("CarregarJogo");
	telaDeCarregar.desenhar(300, 230);
	
	if (gTeclado.pressionou[TECLA_2])
	{
		MenuStack.pop();
	}
}

//Tela de Cadastro
void Menu::atualiar_cadastro()
{
	//Desenhando fundo e logo
	spr.desenhar(300, 230);
	spr2.desenhar(300, 100);
	
	//Desenhando o campo de login
	campoLogin.desenhar(300, 300);
	
	//Desenhar e Atualizar da InputTexto
	input.atualizar();
	input.desenhar();
	
	//Texto para caso surja um Erro de digita��o
	logSucess.desenhar(300, 250);
	
	//Caso o ENTER seja apertado
	if (gTeclado.pressionou[TECLA_ENTER] || gTeclado.pressionou[TECLA_ENTER2]) 
	{
		/* Abrimos outro Stack juntamente com um Switch Case para verificar 
		se o usuario est� digitando User, Senha ou Confirma��o de Senha */

		switch (CadastroMenu.top()) 
		{
		case USER:
			
			logSucess.setString("");
			/* O "campoLogin" por padr�o vem desenhado com a Sprite de colocar Username
			ent�o quando o enter � apertado ele muda para digitar a senha */

			campoLogin.setSpriteSheet("CampoSenha");
			//Cadastrando o que foi digitado na vari�vel de username
			username = input.txt.getString();
			//Apagando texto da tela
			input.apagar_texto();
			//Puxando a tela de cadastro de senha
			CadastroMenu.push(PSSW);
			break;
		case PSSW:
			//Ap�s apertar enter, "campoLogin" muda para o sprite de Confirma��o de Senha
			campoLogin.setSpriteSheet("CampoConfSenha");
			//Cadastrando o que foi digitado na vari�vel de Senha
			senha = input.txt.getString();
			input.apagar_texto();
			//Puxando a tela de Confirma��o de Senha
			CadastroMenu.push(CONFIRM);
			break;
		case CONFIRM:
			//Cadastrando o que foi digitado na vari�vel de confirma��o de senha
			confSenha = input.txt.getString();
			input.apagar_texto();
			//Se a ConfSenha for igual a Senha
			if (confSenha == senha) 
			{
				
				//Salva num arquivo bin�rio todos os dados
				//Abre o arquivo posicionando o ponteiro de escrita no fim
				userEsenha.open("info.bin", std::ios::binary | ios::out | ios::app);
				//Armazena Usuario e Senha na classe conta
				conta->setUserName(username);
				conta->setSenha(senha);
				//Escrevendo no arquivo
				userEsenha.write(reinterpret_cast<char *>(conta), sizeof(ContaUsuario));
				userEsenha.close();
				
				//Vai pro menu principal
				MenuStack.push(MAIN);
			}
			
			//Se n�o conferir
			else
			{
				//Mensagem de Erro
				logSucess.setString("N�o confere! Recomece:");
				//Chama o Campo de escrita do username
				campoLogin.setSpriteSheet("CampoUser");
				//Zera as vari�veis
				username = "";
				senha = "";
				confSenha = "";
				//Puxa a tela de coloca��o de Username
				CadastroMenu.push(USER);
			}
			break;
		}
	}
}

//Tela de Login
void Menu::atualizar_logar()
{
	spr.desenhar(300, 230);
	spr2.desenhar(300, 100);
	campoLogin.desenhar(300, 300);
	input.atualizar();
	input.desenhar();
	
	if (gTeclado.pressionou[TECLA_ENTER] || gTeclado.pressionou[TECLA_ENTER2]) {
		
		//Outra pilha com Switch Case para situa��o da escrita
		switch (LoginMenu.top())
		{
		case USER:
			campoLogin.setSpriteSheet("CampoSenha");
		
			//Colocando o Login
			username = input.txt.getString();
			input.apagar_texto();
			LoginMenu.push(PSSW);
			break;
		
		case PSSW:
			//Colocando a Senha
			senha = input.txt.getString();
			input.apagar_texto();
			
			//Iterador � igual ao username digitado
			gerenteConta->it_hashContas = gerenteConta->hashContas.find(username);
			//Se o username for igual ao Username cadastrado na Conta puxada
			if (username == gerenteConta->it_hashContas->second.getUserName())
			{
				//Se a senha for igual a Senha cadastrada na Conta puxada
				if(senha == gerenteConta->it_hashContas->second.getSenha())
				//Vai pro menu
				MenuStack.push(MAIN);
			}
			else 
			{
				//Se n�o, volta ao in�cio
				LoginMenu.push(USER);
			}
			break;
		}
	}
}

void Menu::setSpriteSheet(string spritesheet)
{
	spr.setSpriteSheet(spritesheet);
}

//Seta os cr�ditos
void Menu::creditos()
{
	//Setando a fonte
	escritaCreditos.setFonte("Login");
	//Setando a escrita
	escritaCreditos.setString("Demorou, mas ta ai! Valeu Raphael n�s te amamos \n" 
	"Valeu Nathalia, n�s tamb�m te amamos \n Por: Gabriel Ribeiro \n Felipe Marzanasco \n Thiago Leal");
	//Desenhando na posi��o
	escritaCreditos.desenhar(300, 100);
}

void Menu::GameOver()
{
	//Desenha o fundo
	spr.desenhar(300, 230);
	//Desenha o sprite de GameOver
	gameOver.desenhar(300, 150);
	
	//Desenhando a pontua��o final do Player
	pontuacaoMax.desenhar(300, 350);
	pontuacaoMax.setString("Sua pontua��o: " + to_string(pontuacao));

	//Pressionando a tecla 2, volta ao Menu
	if (gTeclado.pressionou[TECLA_2])
	{
		gMusica.pausar();
		control->controlaGameOver();
		MenuStack.push(MAIN);
	}
}

void Menu::vitoria()
{
	//colocando o texto de vitoria na tela
	spr.desenhar(300, 230);
	venceu.setString("Voc� venceu! \n Aperte a tecla 2 \n para voltar ao menu.");
	venceu.desenhar(300, 230);
	
	if (gTeclado.pressionou[TECLA_2])
	{
		control->controlaGameOver();
		MenuStack.push(MAIN);

	}
}

//Fun��o que testa se a Pontua��o do jogador deve entrar no Ranking ou n�o
void Menu::testeRanking(std::string usuario, int pontos, fstream & arquivo)
{
	//Se a Hash estiver vazia
	if (gerenteConta->rankPontuacao.size() == 0)
	{
		//Insere a pontua��o com o User na Hash
		gerenteConta->inserirNoRanking(usuario, pontos, gerenteConta);
		
		//Coloca no arquivo txt
		gerenteConta->it_ranking = gerenteConta->rankPontuacao.begin();
		arquivo << gerenteConta->it_ranking->second << " ";
		arquivo << gerenteConta->it_ranking->first << std::endl;
	}
	
	//Se n�o for vazia, mas for menor que 5
	else if (gerenteConta->rankPontuacao.size() < 5) 
	{
		//Insere a pontua��o com o User na Hash
		gerenteConta->inserirNoRanking(usuario, pontos, gerenteConta);
		//Percorre a Hash e coloca no arquivo txt
		for (gerenteConta->it_ranking = gerenteConta->rankPontuacao.begin(); gerenteConta->it_ranking != gerenteConta->rankPontuacao.end(); gerenteConta->it_ranking++)
		{
			arquivo << gerenteConta->it_ranking->second << " ";
			arquivo << gerenteConta->it_ranking->first << std::endl;
		}
	}
	
	//Se a Hash for maior ou igual a 5 (nunca vai ser maior)
	else if (gerenteConta->rankPontuacao.size() >= 5)
	{
		//Iterador � igual ao inicio da Hash (pior pontua��o)
		gerenteConta->it_ranking = gerenteConta->rankPontuacao.begin();
		
		//Caso a pontua��o do player atual for maior que a do Iterador (a pior)
		if (pontos >= gerenteConta->it_ranking->first) 
		{
			//Exclui o primeiro da Hash
			gerenteConta->rankPontuacao.erase(gerenteConta->it_ranking);
			//Insere a pontua��o com o User na Hash
			gerenteConta->inserirNoRanking(usuario, pontos, gerenteConta);
			//Percorre a Hash e adiciona tudo no arquivo txt
			for (gerenteConta->it_ranking = gerenteConta->rankPontuacao.begin(); gerenteConta->it_ranking != gerenteConta->rankPontuacao.end(); gerenteConta->it_ranking++)
			{
				arquivo << gerenteConta->it_ranking->second << " ";
				arquivo << gerenteConta->it_ranking->first << std::endl;
			}
		}
		//Caso n�o seja maior, somente percorre a Hash e readiciona tudo no arquivo txt
		else 
		{
			for (gerenteConta->it_ranking = gerenteConta->rankPontuacao.begin(); gerenteConta->it_ranking != gerenteConta->rankPontuacao.end(); gerenteConta->it_ranking++)
			{
				arquivo << gerenteConta->it_ranking->second << " ";
				arquivo << gerenteConta->it_ranking->first << std::endl;
			}
		}
	}
}

void Menu::finalizarMenu()
{
	//Teste de pontua��o
	arqRanking.open("ranking.txt", ios::out |ios::trunc);
	testeRanking(username, pontuacao, arqRanking);
	arqRanking.close();
	
	input.finalizar();
}


