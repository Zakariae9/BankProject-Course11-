#pragma once
#include "../MainMenu.hpp"

class   clsUsersScreen: protected clsScreen
{
    enum    enUsersOption{eListUsers = 1, eAddNewUser, eDeleteUser,
                            eUpdaetUser, eFindUser, eMainMenu};
    static void _PerformUsersScreenOption(clsUsersScreen::enUsersOption Option);
    static clsUsersScreen::enUsersOption _ReadUsersOption();
public:
    static void _ListUsers();
    static void _AddNewUser();
    static void _DeleteUser();
    static void _UpdateUser();
    static void _FindUser();
    static void _GoBackUsersMenue();
    static void ShowUsresScreen();
};