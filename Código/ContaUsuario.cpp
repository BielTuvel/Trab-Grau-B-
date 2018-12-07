#include "ContaUsuario.h"

std::string ContaUsuario::getUserName()
{
	return userName;
}

std::string ContaUsuario::getSenha()
{
	return senha;
}

void ContaUsuario::setUserName(std::string _userName)
{
	userName = _userName;
}

void ContaUsuario::setSenha(std::string _senha)
{
	senha = _senha;
}

ContaUsuario::ContaUsuario()
{
}

ContaUsuario::~ContaUsuario()
{
}
