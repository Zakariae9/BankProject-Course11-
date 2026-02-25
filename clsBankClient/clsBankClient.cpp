#include "clsBankClient.hpp"
#include "../UI_MainMenu/MainMenu.hpp"

clsBankClient clsBankClient::_ConvertLinetoClientObject(string Line, string Seperator)
{
    vector<string> vClientData = clsString::Split(Line, Seperator);
    return clsBankClient(enMode::UpdateMode, vClientData[0], vClientData[1], vClientData[2], vClientData[3], vClientData[4], vClientData[5], stod(vClientData[6]));
}

string clsBankClient::_ConverClientObjectToLine(clsBankClient Client, string Seperator)
{
    // Changed property access to getters
    return Client.GetFirstName() + Seperator + Client.GetLastName() + Seperator + Client.GetEmail() + Seperator + Client.GetPhone() + Seperator + Client.AccountNumber() + Seperator + Client.GetPinCode() + Seperator + to_string(Client.GetAccountBalance());
}

vector <clsBankClient> clsBankClient::_LoadClientsDataFromFile() {
    vector <clsBankClient> vClients; fstream MyFile; MyFile.open("Clients.txt", ios::in);
    if (MyFile.is_open()) {
        string Line;
        while (getline(MyFile, Line)) vClients.push_back(_ConvertLinetoClientObject(Line));
        MyFile.close();
    }
    return vClients;
}

void    clsBankClient::Deposite(double Amount)
{
    _AccountBalance += Amount;
    Save();
}
void    clsBankClient::Withdraw(double Amount)
{
    if (Amount > _AccountBalance)
    {
        cout << "You don't have enough mony.\n";
        return;
    }
    _AccountBalance -= Amount;
    Save();
}


void clsBankClient::SaveCleintsDataToFile(vector <clsBankClient> &vClients)
{
    _SaveCleintsDataToFile(vClients);
}
void clsBankClient::_SaveCleintsDataToFile(vector <clsBankClient> &vClients)
{
    fstream MyFile;
    
    MyFile.open("Clients.txt", ios::out);
    if (MyFile.is_open())
    {
        for (clsBankClient C : vClients)
        {
            if (C.MarkedForDeleted() == false)
                MyFile << _ConverClientObjectToLine(C) << endl;

        }
        MyFile.close();
    }
}

void clsBankClient::_Update()
{
    vector <clsBankClient> _vClients = _LoadClientsDataFromFile();
    for (clsBankClient& C : _vClients)
    if (C.AccountNumber() == AccountNumber())
    {
        C = *this;
        break;
    }
    SaveCleintsDataToFile(_vClients);
}

void clsBankClient::_AddNew()
{
    _AddDataLineToFile(_ConverClientObjectToLine(*this));
}

void clsBankClient::_AddDataLineToFile(string stDataLine)
{
    fstream MyFile;
    
    MyFile.open("Clients.txt", ios::out | ios::app);
    if (MyFile.is_open())
    {
        MyFile << stDataLine << endl;
        MyFile.close();
    }
}

clsBankClient clsBankClient::_GetEmptyClientObject() { return clsBankClient(enMode::EmptyMode, "", "", "", "", "", "", 0); }

clsBankClient::clsBankClient(enMode Mode, string FirstName, string LastName, string Email, string Phone, string AccountNumber, string PinCode, float AccountBalance) : clsPerson(FirstName, LastName, Email, Phone) {
    _Mode = Mode; _AccountNumber = AccountNumber; _PinCode = PinCode; _AccountBalance = AccountBalance;
}

bool clsBankClient::IsEmpty() { return (_Mode == enMode::EmptyMode); }
bool clsBankClient::MarkedForDeleted() { return _MarkedForDelete; }
string clsBankClient::AccountNumber() { return _AccountNumber; }
void clsBankClient::SetPinCode(string PinCode)
{
    _PinCode = PinCode;
}
string clsBankClient::GetPinCode()
{
    return _PinCode;
}
void clsBankClient::SetAccountBalance(float AccountBalance)
{
    _AccountBalance = AccountBalance;
}
float clsBankClient::GetAccountBalance() { return _AccountBalance; }


void PrintClient(clsBankClient ClientInfo)
{
    // Changed property access to getters
    if (ClientInfo.IsEmpty())
    {
        cout << "\nClient Card:\n";
        cout << "There is no Client\n";
    }
    cout << "\nClient Card:\n___________________\nFirstName   : " << ClientInfo.GetFirstName()
    << "\nLastName    : " << ClientInfo.GetLastName()
    << "\nFull Name   : " << ClientInfo.FullName() 
    << "\nEmail       : " << ClientInfo.GetEmail() 
    << "\nPhone       : " << ClientInfo.GetPhone() 
    << "\nAcc. Number : " << ClientInfo.AccountNumber() 
    << "\nPassword    : " << ClientInfo.GetPinCode()
    << "\nBalance     : " << ClientInfo.GetAccountBalance() 
    << "\n___________________\n";
}

clsBankClient clsBankClient::Find(string AccountNumber) {
    fstream MyFile; MyFile.open("Clients.txt", ios::in);
    if (MyFile.is_open()) {
        string Line;
        while (getline(MyFile, Line)) {
            clsBankClient Client = _ConvertLinetoClientObject(Line);
            if (Client.AccountNumber() == AccountNumber) { MyFile.close(); return Client; }
        }
        MyFile.close();
    }
    return _GetEmptyClientObject();
}


clsBankClient clsBankClient::Find(string AccountNumber, string PinCode) {
    fstream MyFile; MyFile.open("Clients.txt", ios::in);
    if (MyFile.is_open()) {
        string Line;
        while (getline(MyFile, Line)) {
            clsBankClient Client = _ConvertLinetoClientObject(Line);
            if (Client.AccountNumber() == AccountNumber && Client.GetPinCode() == PinCode) { MyFile.close(); return Client; }
        }
        MyFile.close();
    }
    return _GetEmptyClientObject();
}

clsBankClient::enSaveResults clsBankClient::Save()
{
    switch (_Mode)
    {
    case enMode::EmptyMode:
        if (IsEmpty()) 
            return enSaveResults::svFaildEmptyObject;
    case enMode::UpdateMode:
    {
        _Update();
        return enSaveResults::svSucceeded;
    }
    case enMode::AddNewMode:
        if (clsBankClient::IsClientExist(_AccountNumber))
            return enSaveResults::svFaildAccountNumberExists;
        else
        {
            _AddNew();
            _Mode = enMode::UpdateMode;
            return enSaveResults::svSucceeded;
        }
        break;
    }
    return enSaveResults::svFaildEmptyObject;
}

bool clsBankClient::IsClientExist(string AccountNumber) 
{ 
    clsBankClient Client1 = clsBankClient::Find(AccountNumber); 
    return (!Client1.IsEmpty()); 
}

bool clsBankClient::Delete()
{
    vector <clsBankClient> _vClients = _LoadClientsDataFromFile();
    for (clsBankClient& C : _vClients)
    {
        if (C.AccountNumber() == _AccountNumber)
        {
            C._MarkedForDelete = true;
            break;
        }
    }
    SaveCleintsDataToFile(_vClients);
    *this = _GetEmptyClientObject();
    return true;
}

clsBankClient clsBankClient::GetAddNewClientObject(string AccountNumber)
{
    return clsBankClient(enMode::AddNewMode, "", "", "", "", AccountNumber, "", 0);
}

vector <clsBankClient> clsBankClient::GetClientsList()
{
    return _LoadClientsDataFromFile();
}
float clsBankClient::GetTotalBalances()
{
    vector <clsBankClient> vClients = clsBankClient::GetClientsList();
    double TotalBalances = 0;
    for (clsBankClient &Client : vClients)
        TotalBalances += Client.GetAccountBalance(); // Changed to GetAccountBalance()
    return TotalBalances;
}