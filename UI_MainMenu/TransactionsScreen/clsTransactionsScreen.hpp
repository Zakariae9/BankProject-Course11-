#pragma once
#include "../MainMenu.hpp"

class   clsTransactionScreen: protected clsScreen
{
private:
    enum    enTransations{eDeposit = 1, eWithDraw = 2, eTotalBalances = 3, eGoBackMainMenue = 4};
    static void _TransactionMenue();
    static void _PerformTransactionOption(enTransations Option);
    static void _ShowDepositScreen();
    static void _ShowWithDrawScreen();
    static void _ShowTotalBalancesScreen();
    static void _GoBackTransactionMenue();
    static enTransations _ReadTransactionInfo();
public:
    static void ShowTransactionClientScreen();
};