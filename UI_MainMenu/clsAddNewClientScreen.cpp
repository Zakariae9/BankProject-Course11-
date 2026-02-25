#include "clsAddNewClientScreen.hpp"

void	clsAddNewClientScreen::_ReadClientInfo(clsBankClient &ClientObject)
{    
    ClientObject.SetFirstName(clsInputValidate::ReadStr("Enter first name: "));
    ClientObject.SetLastName(clsInputValidate::ReadStr("Enter last name: "));
    ClientObject.SetPinCode(clsInputValidate::ReadStr("Enter pin code: "));
    ClientObject.SetEmail(clsInputValidate::ReadStr("Enter Email: "));
    ClientObject.SetPhone(clsInputValidate::ReadStr("Enter Phone number: "));
    cout << "Enter an Account Balance: ";
    ClientObject.SetAccountBalance(clsInputValidate::ReadDblNumber());
}

void    clsAddNewClientScreen::ShowAddNewClientScreen()
{
    string                  AccountNumber = "";
    vector<clsBankClient>   ClientsList = clsBankClient::GetClientsList();

    DrawMainScreenHeader("Add New Client Screen");
    AccountNumber = clsInputValidate::ReadStr("Enter An Account Number: ");
    while(clsBankClient::IsClientExist(AccountNumber))
    {
        cout << "This Account Number is already exist.\n";
        AccountNumber = clsInputValidate::ReadStr("Enter An Account Number");
    }
    clsBankClient           NewClient = clsBankClient::GetAddNewClientObject(AccountNumber);
    _ReadClientInfo(NewClient);
    ClientsList.push_back(NewClient);
    clsBankClient::enSaveResults SaveResults =  NewClient.Save();

    switch (SaveResults)
    {
        case clsBankClient::enSaveResults::svSucceeded:
        {
            cout << "New Client Added Successfully.\n";
            PrintClient(NewClient);
            break;
        }
        case clsBankClient::enSaveResults::svFaildEmptyObject:
        {
            cout << "New Client Doesn't Added\n";
            break;
        }
    }
}
