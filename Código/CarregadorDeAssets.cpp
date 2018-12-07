#include "CarregadorDeAssets.h"

CarregadorDeAssets::CarregadorDeAssets()
{
}

CarregadorDeAssets::~CarregadorDeAssets()
{
}

bool CarregadorDeAssets::carregaTodosAssets(std::fstream & ArquivoRecursos)
{
	bool statusCarregamento = true;
	std::string tipoAsset;
	std::string nomeAsset;
	std::string caminhoAsset;
	std::string numAnimAsset;
	std::string numMaxFramesAsset;
	std::string::size_type size;

	if (ArquivoRecursos)
	{
		char numAss = ArquivoRecursos.get();
		this->numAssets = numAss - '0';

		while (!ArquivoRecursos.eof())
		{
			ArquivoRecursos >> tipoAsset >> nomeAsset >> caminhoAsset >> numAnimAsset >> numMaxFramesAsset;

			if (!ArquivoRecursos.fail())
			{
				
				if (tipoAsset == "sprite_sheet")
				{
					gRecursos.carregarSpriteSheet(nomeAsset, caminhoAsset, std::stoi(numAnimAsset, &size),
						std::stoi(numMaxFramesAsset, &size), QUALIDADE_ESCALA_BAIXA);

				}
				if (!gRecursos.carregouSpriteSheet(nomeAsset))
				{
					gDebug.erro("Não carregou recurso");
					return false;
				}
				
			}


		}
	}
	return true;

	
}

void CarregadorDeAssets::destroiTodosAseets()
{
	gRecursos.descarregar("Mapa");
	gRecursos.descarregar("Nave");
	gRecursos.descarregar("Inimigo1");
	gRecursos.descarregar("tiro");
	gRecursos.descarregar("fundoMenu");
	gRecursos.descarregar("logo");
	gRecursos.descarregar("carregar");
	gRecursos.descarregar("start");
	gRecursos.descarregar("ranking");
	gRecursos.descarregar("creditos");
	gRecursos.descarregar("sair");
	gRecursos.descarregar("cadastrar");
	gRecursos.descarregar("logar");
	gRecursos.descarregar("Boss");
}

void CarregadorDeAssets::testeSeCarregou()
{
	this->mapaAssets.open("..\\Carrega_Assets.txt", ios::in);
	if (!mapaAssets)
	{
		gDebug.erro("não abriu arquivo", this);
	}

	if (!carregaTodosAssets(mapaAssets))
	{
		gDebug.erro("Falha no carregamento de recursos");
	}
}
