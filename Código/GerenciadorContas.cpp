#include "GerenciadorContas.h"

GerenciadorContas::GerenciadorContas()
{
}

GerenciadorContas::~GerenciadorContas()
{
}

/*Este m�todo serve para retirar a lista de User e Senhas de um arquivo e armazenar numa tabela hash
do tipo unordered_multimap*/
void GerenciadorContas::inserirPorArquivo(fstream  & arquivo, GerenciadorContas * hash, ContaUsuario * _conta)
{
	if (arquivo.is_open())
	{
		while (!arquivo.eof())
		{
			//Ele l� um objeto _conta interpretando ele no maximo do tamanho de um objeto do tipo ContaUsuario
			//Ap�s isso ele armazena em um par e coloca na hash
			//Par First = Nome de Usuario
			//Par Second = _conta (que carrega consigo User e Senha)
			arquivo.read(reinterpret_cast<char *>(_conta), sizeof(ContaUsuario));
			hash->parHashContas.first = _conta->getUserName();
			hash->parHashContas.second = *_conta;
			hash->hashContas.insert(hash->parHashContas);
		}
	}
}

/*Aqui temos algo parecido, por�m para colocar um ranking de um arquivo.txt em uma hash
to tipo Multimap */
void GerenciadorContas::inserirRanking(fstream & arquivo, GerenciadorContas * hash)
{
	//Uma vari�vel armazenar� o score e a outra o user
	int score;
	std::string _user;
	
	
	if (arquivo.is_open())
	{
		//Testa se o arquivo est� vazio ou n�o
		/*Se estiver vazio ele pula essa etapa, evitando do sistema armazenar
		lixos de mem�ria */
		if (!is_empty(arquivo)) 
		{
			//Enquanto _user e score receberem alguma informa��o v�lida
			while (arquivo >> _user >> score)
			{
				//Ele armazena na Hash
				hash->parRankPontuacao.first = score;
				hash->parRankPontuacao.second = _user;
				hash->rankPontuacao.insert(hash->parRankPontuacao);
			}
		}
	}
}

//M�todo pr�tico para acrescentar Score e User na Hash
void GerenciadorContas::inserirNoRanking(std::string user, int score, GerenciadorContas * hash)
{
	hash->parRankPontuacao.first = score;
	hash->parRankPontuacao.second = user;
	hash->rankPontuacao.insert(hash->parRankPontuacao);
}

//Fun��o que verifica se um arquivo � vazio ou n�o
bool GerenciadorContas::is_empty(std::fstream & pFile)
{
	return pFile.peek() == std::ifstream::traits_type::eof();
}

