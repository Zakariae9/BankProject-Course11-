#pragma once
#include "MainMenu.hpp"

class   clsUpdateClientScreen:protected clsScreen
{
private:
   static void    _ReadClientInfo(clsBankClient &ClientObject);
public:
    static void ShowUpdateClientScreen();
};