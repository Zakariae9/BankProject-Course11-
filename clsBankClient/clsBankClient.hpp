#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <iomanip>
#include "../clsPerson/clsPerson.hpp"
#include "../clsString/clsString.hpp"

using namespace std;

class clsBankClient : public clsPerson
{
private:
    enum enMode { EmptyMode = 0, UpdateMode = 1, AddNewMode = 2 };
    enMode _Mode;
    string _AccountNumber;
    string _PinCode;
    float _AccountBalance;
    bool _MarkedForDelete = false;

    static clsBankClient _ConvertLinetoClientObject(string Line, string Seperator = "#//#");
    static string _ConverClientObjectToLine(clsBankClient Client, string Seperator = "#//#");
    static vector <clsBankClient> _LoadClientsDataFromFile();
    static void _SaveCleintsDataToFile(vector <clsBankClient> &vClients);
    void _Update();
    void _AddNew();
    void _AddDataLineToFile(string stDataLine);
    static clsBankClient _GetEmptyClientObject();

public:
    clsBankClient(enMode Mode, string FirstName, string LastName, string Email, string Phone, string AccountNumber, string PinCode, float AccountBalance);

    bool IsEmpty();
    bool MarkedForDeleted();
    string AccountNumber();
    
    void SetPinCode(string PinCode);
    string GetPinCode();
    
    void SetAccountBalance(float AccountBalance);
    float GetAccountBalance();
    
    static clsBankClient Find(string AccountNumber);
    static clsBankClient Find(string AccountNumber, string PinCode);

    enum enSaveResults { svFaildEmptyObject = 0, svSucceeded = 1, svFaildAccountNumberExists = 2 };
    enSaveResults Save();
    static bool IsClientExist(string AccountNumber);
    static void SaveCleintsDataToFile(vector <clsBankClient> &vClients);
    bool Delete();
    static clsBankClient GetAddNewClientObject(string AccountNumber);
    static vector <clsBankClient> GetClientsList();
    static float GetTotalBalances();
    void    Deposite(double Amount);
    void    Withdraw(double Amount);
};

void PrintClient(clsBankClient ClientInfo);
