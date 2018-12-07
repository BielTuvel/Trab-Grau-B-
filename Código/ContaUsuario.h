#pragma once
#include <iostream>
#include <string>



class ContaUsuario
{
public:
	//Métodos para pegar User e Senha da Conta
	std::string getUserName();
	std::string getSenha();

	//Métodos para setar os valores
	void setUserName(std::string _userName);
	void setSenha(std::string _senha);
	
	ContaUsuario();
	~ContaUsuario();

protected:

	//Informações da classe conta
	std::string userName, senha;
	
};

