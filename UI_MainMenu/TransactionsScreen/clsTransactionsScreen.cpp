#include "DepositScreen.hpp"
#include "WithDrawScreen.hpp"
#include "TotalBalancesScreen.hpp"

void clsTransactionScreen::_PerformTransactionOption(enTransations Option)
{
    switch (Option)
    {
        case eDeposit:
        {
            system("clear");
            _ShowDepositScreen();
            _GoBackTransactionMenue();
            break;
        }
        case eWithDraw:
        {
            system("clear");
            _ShowWithDrawScreen();
            _GoBackTransactionMenue();
            break;
        }
        case eTotalBalances:
        {
            system("clear");
            _ShowTotalBalancesScreen();
            _GoBackTransactionMenue();
            break;
        }
        default:
            break;
    }
}


clsTransactionScreen::enTransations clsTransactionScreen::_ReadTransactionInfo()
{
    return (enTransations)clsInputValidate::ReadShortNumberBetween(1, 4, "Please enter a number between 1 to 4: ");
}

void clsTransactionScreen::_TransactionMenue()
{
    system("clear");
    DrawMainScreenHeader("Transaction Menue", "(4) serveces");
    cout << "\t\t\t\t===============================================\n";
    cout << "\t\t\t\t\t\tTransaction Menue\n";
    cout << "\t\t\t\t===============================================\n";
    cout << "\t\t\t\t\t[1] Deposite\n";
    cout << "\t\t\t\t\t[2] Withdraw\n";
    cout << "\t\t\t\t\t[3] Total Balances\n";
    cout << "\t\t\t\t\t[4] Main Menue\n";
    cout << "\t\t\t\t===============================================\n";
    cout << "\t\t\t\tPlese Enter your choice: ";
    _PerformTransactionOption(_ReadTransactionInfo());
}

void clsTransactionScreen::_ShowDepositScreen()
{
    clsDeposite::ShowDepositeScreen();
}

void clsTransactionScreen::_ShowTotalBalancesScreen()
{
    clsTotalBalances::ShowTotalBalancesScreen();
}

void clsTransactionScreen::_ShowWithDrawScreen()
{
    clsWithdraw::ShowWithdrawScreen();
}

void clsTransactionScreen::_GoBackTransactionMenue()
{
    cout << "\n\nPress enter to Go Back Transaction Menue Screen function...";
    cin.clear();
    cin.get();
    cin.get();
    ShowTransactionClientScreen();
}

void clsTransactionScreen::ShowTransactionClientScreen()
{
    _TransactionMenue();
}