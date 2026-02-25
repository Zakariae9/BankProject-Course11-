#pragma once
#include "../clsInputValidate/clsInputValidate.hpp"
#include "../clsBankClient/clsBankClient.hpp"

class   clsScreen
{
public:
    static void    DrawMainScreenHeader(string Title, string SubTitle = "");
};


class   clsMainScreen: protected clsScreen
{
private:
	enum	enMainMenueOption{eShowClientList = 1, eAddNewClient,
								eDeleteClientInfo, eUpdateClientInfo,
							eFindClient, eTransactions, eManageUsers, eLogout};
	static short _ReadMainMenueOption();
    static void	_ShowClientListScreen();
    static void	_AddNewClientScreen();
    static void	_DeleteClientInfoScreen();
    static void	_UpdateClientInfoScreen();
    static void	_FindClientScreen();
    static void	_TransactionsScreen();
    static void	_ManageUsersScreen();
    static void	_Logout();
	static void _GoBackMainMenue();
    static void	_PerformMainMenueOption(enMainMenueOption MainMenueOption);
public:
    static  void ShowMainMenue();
};