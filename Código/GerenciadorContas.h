#pragma once
#include <iostream>
#include <map>
#include <unordered_map>
#include "ContaUsuario.h"
#include "libUnicornio.h"
#include <fstream>

class GerenciadorContas
{

public:

	//Definindo Unordered Multimap junto com seu par, são usados para o Login
	typedef std::unordered_multimap <std::string, ContaUsuario> _contas;
	typedef std::pair<std::string, ContaUsuario> par;

	//Definindo Multimap  e seu par, são usados para o Ranking
	typedef std::multimap <int, std::string> ranking;
	typedef std::pair<int, std::string> parRanking;

	//Hash de Contas e o seu Iterador
	_contas::iterator  it_hashContas;
	_contas  hashContas;
	par  parHashContas;

	//Hash do Ranking e o seu iterador
	ranking rankPontuacao;
	parRanking parRankPontuacao;
	ranking::iterator it_ranking;

	//Funções
	void inserirPorArquivo(fstream & arquivo, GerenciadorContas * hash, ContaUsuario * conta);
	void inserirRanking(fstream & arquivo, GerenciadorContas * hash);
	void inserirNoRanking(std::string user, int score, GerenciadorContas * hash);
	bool is_empty(std::fstream& pFile);
	
	GerenciadorContas();
	~GerenciadorContas();
};