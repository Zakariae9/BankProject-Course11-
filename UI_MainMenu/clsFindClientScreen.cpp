#include "clsFindClientScreen.hpp"

void clsFindClientScreen::ShowFindClientScreen()
{
    DrawMainScreenHeader("Find Client");
    string AccountNumber = clsInputValidate::ReadStr("Enter an Account Number: ");
    if (clsBankClient::IsClientExist(AccountNumber))
        PrintClient(clsBankClient::Find(AccountNumber));
    else 
        cout << "This Account Number isn't exist.\n";
}