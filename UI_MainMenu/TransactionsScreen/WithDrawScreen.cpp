#include "WithDrawScreen.hpp"

void clsWithdraw::ShowWithdrawScreen()
{
    string AccountNumber;
    double Withdraw;

    DrawMainScreenHeader("Withdraw Screen");
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
    cin >> Withdraw;
    Client.Withdraw(Withdraw);
    cout << "Deposite is sucsseccfully.\n"
         << "New Balance is " << Client.GetAccountBalance();
}