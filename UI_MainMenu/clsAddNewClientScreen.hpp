#pragma once
#include "MainMenu.hpp"

class	clsAddNewClientScreen: protected clsScreen
{
	static	void	_ReadClientInfo(clsBankClient &ClientObject);
public:
	static void ShowAddNewClientScreen();
};