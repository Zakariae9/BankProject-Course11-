#include "clsClientListScreen.hpp"

void clsClientListScreen::ShowClientList()
{
	vector <clsBankClient> vClients = clsBankClient::GetClientsList("Clients.txt");
    string  Title = "Client List Screen";
    string  SubTitle = "(" + to_string(vClients.size()) + ") client(s).";
    clsScreen::DrawMainScreenHeader(Title, SubTitle);
    cout << left << setw(8) << "" << "_______________________________________________________________________________________\n";
    cout << left << setw(8) << "" << left << setw(16) << "| Account Number";
    cout << left << setw(15) << "| Client Name";
    cout << left << setw(15) << "| Phone";
    cout << left << setw(10) << "| Pin Code";
    cout << left << setw(10) << "| Balance\n";
    cout << left << setw(8) << "" << "_______________________________________________________________________________________\n";
    for (clsBankClient &C: vClients)
    {
		  _PrintClientRecordBalanceLine(C);
		  cout << endl;
    }
    cout << left << setw(8) << "" << "_______________________________________________________________________________________\n";
}