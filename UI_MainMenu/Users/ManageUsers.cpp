#include "ManageUsers.hpp"

void    clsUsersScreen::_ListUsers()
{
    cout << "List Users will be here\n";
}

void clsUsersScreen::_AddNewUser()
{
    cout << "Add New User will be here\n";
}

void clsUsersScreen::_DeleteUser()
{
    cout << "Delete User will be here\n";
}

void clsUsersScreen::_UpdateUser()
{
    cout << "Update User will be here\n";
}

void clsUsersScreen::_FindUser()
{
    cout << "Find User will be here\n";
}

clsUsersScreen::enUsersOption clsUsersScreen::_ReadUsersOption()
{
    cout << "\t\t\t\t\tEnter your choose[1-6]: ";
    return (enUsersOption)clsInputValidate::ReadShortNumberBetween(1, 6, "Choose must be between [1-6]: ");
}

void clsUsersScreen::_GoBackUsersMenue()
{
    cout << "Press Enter to go back Users Menue...";
    cin.get();
    cin.get();
    ShowUsresScreen();
}

void clsUsersScreen::_PerformUsersScreenOption(clsUsersScreen::enUsersOption Option)
{
    switch (Option)
    {
        case eListUsers:
        {
            system("clear");
            _ListUsers();
            _GoBackUsersMenue();
        }
        case eAddNewUser:
        {
            system("clear");
            _AddNewUser();
            _GoBackUsersMenue();
        }case eDeleteUser:
        {
            system("clear");
            _DeleteUser();
            _GoBackUsersMenue();
        }case eUpdaetUser:
        {
            system("clear");
            _UpdateUser();
            _GoBackUsersMenue();
        }case eFindUser:
        {
            system("clear");
            _FindUser();
            _GoBackUsersMenue();
        }
        case eMainMenu:
            break;
    }
}

void clsUsersScreen::ShowUsresScreen()
{
    system("clear");
    DrawMainScreenHeader("Manage Users Screen");
    cout << "\t\t\t\t============================================\n";
    cout << "\t\t\t\t\t[1] List Users.\n";
    cout << "\t\t\t\t\t[2] Add New User.\n";
    cout << "\t\t\t\t\t[3] Delete User.\n";
    cout << "\t\t\t\t\t[4] Update User.\n";
    cout << "\t\t\t\t\t[5] Find User.\n";
    cout << "\t\t\t\t\t[6] Main Menue.\n";
    cout << "\t\t\t\t============================================\n";
    _PerformUsersScreenOption(_ReadUsersOption());
}