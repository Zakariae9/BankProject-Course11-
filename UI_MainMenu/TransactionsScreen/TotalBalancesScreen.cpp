#include "TotalBalancesScreen.hpp"

void clsTotalBalances::ShowTotalBalancesScreen()
{
    vector <clsBankClient> vClients = clsBankClient::GetClientsList("Clients.txt");
    string Title = "Total Balances Screen";
    string SubTitle = "Total Balances for [" + to_string(vClients.size()) + "] Clients.";
    DrawMainScreenHeader(Title, SubTitle);
    cout << "\t\t\t=========================================\n";
    cout << "\t\t\t" << setw(15) << "Client" << " " << setw(15) << "Balance\n";
    cout << "\t\t\t=========================================\n";
    for (clsBankClient &C: vClients)
    {
        cout << "\t\t\t" << setw(15) << C.FullName().substr(0, 15) << ':' << setw(15) << C.GetAccountBalance() << endl;
    }
    cout << "\t\t\t=========================================\n";
    cout << "\t\t\t\tTotal Balances: " << vClients[0].GetTotalBalances() << endl;
    cout << "\t\t\t=========================================\n";

}