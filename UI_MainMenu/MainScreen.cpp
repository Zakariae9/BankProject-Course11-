#include "MainMenu.hpp"
#include "clsClientListScreen.hpp"
#include "clsAddNewClientScreen.hpp"
#include "clsDeleteClientScreen.hpp"
#include "clsUpdateClientScreen.hpp"
#include "clsFindClientScreen.hpp"
#include "TransactionsScreen/clsTransactionsScreen.hpp"
#include "Users/ManageUsers.hpp"

void    clsScreen::DrawMainScreenHeader(string Title, string SubTitle)
{
    cout << "\t\t\t\t________________________________________\n";
    cout << "\t\t\t\t\t\t" << Title << "\n";
	if (SubTitle != "")
	{
    	cout << "\t\t\t\t\t\t" << SubTitle << "\n";
	}
    cout << "\t\t\t\t________________________________________\n";
}

void clsClientListScreen::_PrintClientRecordBalanceLine(clsBankClient Client)
{
    cout << left << setw(8) << "" << "| " << setw(14) << Client.AccountNumber();
    cout << "| " << setw(13) << left << Client.FullName().substr(0, 13);
    cout << "| " << setw(13) << left << Client.GetPhone();
    cout << "| " << setw(7) << left << Client.GetPinCode();
    cout << "| " << setw(7) << left << Client.GetAccountBalance();
}



void    clsMainScreen::_ShowClientListScreen()
{
	clsClientListScreen::ShowClientList();
}
void    clsMainScreen::_AddNewClientScreen()
{
	clsAddNewClientScreen::ShowAddNewClientScreen();
}
void    clsMainScreen::_DeleteClientInfoScreen()
{
    clsDeleteClientScreen::ShowDeleteClientScreen();
}
void    clsMainScreen::_UpdateClientInfoScreen()
{
    clsUpdateClientScreen::ShowUpdateClientScreen();
}
void   clsMainScreen::_FindClientScreen()
{
    clsFindClientScreen::ShowFindClientScreen();
}
void    clsMainScreen::_TransactionsScreen()
{
    clsTransactionScreen::ShowTransactionClientScreen();
}
void    clsMainScreen::_ManageUsersScreen()
{
    clsUsersScreen::ShowUsresScreen();
}
void    clsMainScreen::_Logout()
{
    cout << "Logout\n";
}

void	clsMainScreen::_PerformMainMenueOption(enMainMenueOption MainMenueOption)
{
	switch(MainMenueOption)
	{
		case enMainMenueOption::eShowClientList:
		{
			system("clear");
			_ShowClientListScreen();
			_GoBackMainMenue();
			break;
		}
		case enMainMenueOption::eAddNewClient:
		{
			system("clear");
			_AddNewClientScreen();
			_GoBackMainMenue();
			break;
		}
		case enMainMenueOption::eDeleteClientInfo:
		{
			system("clear");
			_DeleteClientInfoScreen();
			_GoBackMainMenue();
			break;
		}
		case enMainMenueOption::eUpdateClientInfo:
		{
			system("clear");
			_UpdateClientInfoScreen();
			_GoBackMainMenue();
			break;
		}
		case enMainMenueOption::eFindClient:
		{
			system("clear");
			_FindClientScreen();
			_GoBackMainMenue();
			break;
		}
		case enMainMenueOption::eTransactions:
		{
			system("clear");
			_TransactionsScreen();
			_GoBackMainMenue();
			break;
		}
		case enMainMenueOption::eManageUsers:
		{
			system("clear");
			_ManageUsersScreen();
			_GoBackMainMenue();
			break;
		}
		case enMainMenueOption::eLogout:
		{
			system("clear");
			_Logout();
			break;
		}
		default:
			break;
	}
}


void	clsMainScreen::_GoBackMainMenue()
{
	cout << "\nPress enter to go back Main Menue...";
	cin.get();
	cin.get();
	ShowMainMenue();
}

short clsMainScreen::_ReadMainMenueOption()
{
	cout << "\t\t\tChoose what do you want to do? [1 to 8]? ";
	short Option = clsInputValidate::ReadShortNumberBetween(1, 8, "Enter a number between 1 and 8 ");
	return Option;
}

void    clsMainScreen::ShowMainMenue()
{
	system("clear");
    DrawMainScreenHeader("Main Screen");
	cout << "\t\t\t=====================================================\n";
	cout << "\t\t\t\t\t\tMain Menue\n";
	cout << "\t\t\t=====================================================\n";
	cout << "\t\t\t\t[1] Show Client List.\n";
	cout << "\t\t\t\t[2] Add Client List.\n";
	cout << "\t\t\t\t[3] Delete Client.\n";
	cout << "\t\t\t\t[4] Update Client Info.\n";
	cout << "\t\t\t\t[5] Find Client.\n";
	cout << "\t\t\t\t[6] Transactions.\n";
	cout << "\t\t\t\t[7] Manage Users.\n";
	cout << "\t\t\t\t[8] Logout.\n";
	cout << "\t\t\t=====================================================\n";
	_PerformMainMenueOption((enMainMenueOption)_ReadMainMenueOption());
}