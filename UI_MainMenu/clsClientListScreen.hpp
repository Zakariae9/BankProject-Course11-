#pragma once
#include "MainMenu.hpp"

class	clsClientListScreen: protected clsScreen
{
private:
	static void	_PrintClientRecordBalanceLine(clsBankClient Client);
public:
	static void ShowClientList();
};