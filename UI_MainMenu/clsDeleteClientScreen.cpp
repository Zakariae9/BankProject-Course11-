#include "clsDeleteClientScreen.hpp"


void clsDeleteClientScreen::ShowDeleteClientScreen()
{
    string  AccountNumber = "";
    char    Checking;
    
    DrawMainScreenHeader("Delete Client Screen");
    AccountNumber = clsInputValidate::ReadStr("\nEnter An Account Number that you want to delete: ");
    while (!clsBankClient::IsClientExist(AccountNumber))
        AccountNumber = clsInputValidate::ReadStr("This Account Number isn't exist, Please Enter one already exist: ");
    clsBankClient Client = clsBankClient::Find(AccountNumber);
    PrintClient(Client);
    do
    {
        cout << "Are you sure, do you want delete " + AccountNumber + " Client [Y/N]: ";
        cin >> Checking;
    }while (Checking != 'Y' && Checking != 'N');
    if (Checking == 'N')
        return ;
    
     Client.Delete()? cout <<  "Client is Deleted successfully-)\n": cout <<  "Delete Client Failed.\n";
}