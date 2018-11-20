#pragma once
#include "libUnicornio.h"
#include "fstream"
#include "iostream"

class CarregadorDeAssets
{
public:
	CarregadorDeAssets();
	~CarregadorDeAssets();

	bool carregaTodosAssets(std::fstream & ArquivoRecursos);
	void destroiTodosAseets();
	void testeSeCarregou();

private:

	int numAssets;
	fstream mapaAssets;
};

