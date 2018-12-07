#include "InputTexto.h"
#include <algorithm>


InputTexto::InputTexto()
{
}

InputTexto::~InputTexto()
{
}

void InputTexto::inicializar()
{
	//	Setar a fonte e a string para o texto
	txt.setFonte("Login");
	txt.setString("");

	gTeclado.inputTexto.habilitar();
}

void InputTexto::finalizar()
{
	//	5) Quando não for mais necessário, desabilita o input de texto.
	gTeclado.inputTexto.desabilitar();

	//	Apagar o texto
	txt.apagar();
}

void InputTexto::atualizar()
{
	//	2) Controlar a edição do texto.
	//		Apagar o texto com tecla voltar ou delete
	if (gTeclado.pressionou[TECLA_VOLTAR])
	{
		gTeclado.inputTexto.apagar();
	}
	if (gTeclado.pressionou[TECLA_DELETE])
	{
		if (gTeclado.inputTexto.getTamanhoSelecao() != 0)
			gTeclado.inputTexto.apagar();
		else if (gTeclado.inputTexto.getPosCursor() < gTeclado.inputTexto.getString().size())
		{
			gTeclado.inputTexto.moverPosCursorParaDir();
			gTeclado.inputTexto.apagar();
		}
	}

	//		Mover a seleção do texto
	if (gTeclado.segurando[TECLA_SHIFT_ESQ])
	{
		if (gTeclado.pressionou[TECLA_ESQ])
		{
			gTeclado.inputTexto.moverSelecaoParaEsq();
		}
		if (gTeclado.pressionou[TECLA_DIR])
		{
			gTeclado.inputTexto.moverSelecaoParaDir();
		}
		if (gTeclado.pressionou[TECLA_HOME])
		{
			gTeclado.inputTexto.moverSelecaoParaInicio();
		}
		if (gTeclado.pressionou[TECLA_END])
		{
			gTeclado.inputTexto.moverSelecaoParaFim();
		}
	}
	//		Mover o cursor do texto
	else
	{
		if (gTeclado.pressionou[TECLA_ESQ])
		{
			gTeclado.inputTexto.moverPosCursorParaEsq();
		}
		if (gTeclado.pressionou[TECLA_DIR])
		{
			gTeclado.inputTexto.moverPosCursorParaDir();
		}
		if (gTeclado.pressionou[TECLA_HOME])
		{
			gTeclado.inputTexto.moverPosCursorParaInicio();
		}
		if (gTeclado.pressionou[TECLA_END])
		{
			gTeclado.inputTexto.moverPosCursorParaFim();
		}
	}

	//	3) Passar a string do input para o texto
	txt.setString(gTeclado.inputTexto.getString());
}

void InputTexto::desenhar()
{
	//	4) Mostrar o texto na tela
	txt.desenhar(300, 308);

	//	Desenhar seleção
	int tamSelecao = gTeclado.inputTexto.getTamanhoSelecao();
	if (tamSelecao != 0)
	{
		Quad retan;
		retan.larg = 0;
		retan.alt = txt.getFonte()->getAlturaGlifos();
		retan.x = (gJanela.getLargura() / 2) - txt.getLargura() / 2;
		retan.y = (gJanela.getAltura() / 2) - retan.alt / 2;
		
		int posCursor = gTeclado.inputTexto.getPosCursor();
		int inicio = min(posCursor, posCursor + tamSelecao);
		int fim = max(posCursor, posCursor + tamSelecao);

		for (int i = inicio; i < fim; ++i)
			retan.larg += txt.getLetra(i)->glifo->avanco*txt.getEscalaX();

		for (int i = 0; i < inicio; ++i)
			retan.x += txt.getLetra(i)->glifo->avanco*txt.getEscalaX();

		gGraficos.desenharRetangulo(retan, 30, 200, 230);
	}

	//	Desenhar o cursor do texto
	int altCursor = txt.getFonte()->getAlturaGlifos();
	int xCursor = (300) - txt.getLargura() / 2;
	int yCursor = (308) - altCursor / 2;
	int pos = gTeclado.inputTexto.getPosCursor();
	for (int i = 0; i < pos; ++i)
		xCursor += txt.getLetra(i)->glifo->avanco*txt.getEscalaX();

	gGraficos.desenharLinha(xCursor, yCursor, xCursor, yCursor + altCursor);
}

void InputTexto::apagar_texto()
{
	gTeclado.inputTexto.setString("");
}

