#include "clsUpdateClientScreen.hpp"

void	clsUpdateClientScreen::_ReadClientInfo(clsBankClient &ClientObject)
{    
    ClientObject.SetFirstName(clsInputValidate::ReadStr("Enter first name: "));
    ClientObject.SetLastName(clsInputValidate::ReadStr("Enter last name: "));
    ClientObject.SetPinCode(clsInputValidate::ReadStr("Enter pin code: "));
    ClientObject.SetEmail(clsInputValidate::ReadStr("Enter Email: "));
    ClientObject.SetPhone(clsInputValidate::ReadStr("Enter Phone number: "));
    cout << "Enter an Account Balance: ";
    ClientObject.SetAccountBalance(clsInputValidate::ReadDblNumber());
}

void clsUpdateClientScreen::ShowUpdateClientScreen()
{
	DrawMainScreenHeader("Update client screen");
    string  AccountNumber = clsInputValidate::ReadStr("Please enter an Acount Number: ");
	char	Answer;

	while (!clsBankClient::IsClientExist(AccountNumber))
		AccountNumber = clsInputValidate::ReadStr("The Account Number isn't exist, Enter another one: ");
	clsBankClient Client = clsBankClient::Find(AccountNumber);
	PrintClient(Client);
	do
	{
		cout << "\nAre you sure you want to update client info?[Y/N]: ";
		cin >> Answer;
	}while (Answer != 'Y' && Answer != 'N');
	if (Answer == 'N')
		return ;
	_ReadClientInfo(Client);
	if (Client.Save() == clsBankClient::svSucceeded)
		cout << "Client Updated successfully.\n";
	else
		cout << "Client Updated Failed.\n";
}