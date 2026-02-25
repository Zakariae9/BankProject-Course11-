#include "DepositScreen.hpp"

void clsDeposite::ShowDepositeScreen()
{
    string AccountNumber;
    double Deposite;

    DrawMainScreenHeader("Deposite Screen");
    cout << "Enter an Account Number: ";
    cin >> AccountNumber;
    while (!clsBankClient::IsClientExist(AccountNumber))
    {
        cout << "\nAccount Number [" + AccountNumber + "] isn't exist.\n";
        return ;
    }
    clsBankClient Client = clsBankClient::Find(AccountNumber);
    PrintClient(Client);
    cout << "Enter Deposite amount: ";
    cin >> Deposite;
    Client.Deposite(Deposite);
    cout << "Deposite is sucsseccfully.\n"
         << "New Balance is " << Client.GetAccountBalance();
}