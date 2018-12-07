#pragma once
#include <iostream>
#include <string>



class ContaUsuario
{
public:
	//M�todos para pegar User e Senha da Conta
	std::string getUserName();
	std::string getSenha();

	//M�todos para setar os valores
	void setUserName(std::string _userName);
	void setSenha(std::string _senha);
	
	ContaUsuario();
	~ContaUsuario();

protected:

	//Informa��es da classe conta
	std::string userName, senha;
	
};

