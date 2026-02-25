#include "clsPerson.hpp"

clsPerson::clsPerson(string FirstName, string LastName, string Email, string phone) {
	_FirstName = FirstName; _LastName = LastName; _Email = Email; _Phone = phone;
}
void clsPerson::SetFirstName(string Name) { _FirstName = Name; }
string clsPerson::GetFirstName() { return _FirstName; }
void clsPerson::SetLastName(string Name) { _LastName = Name; }
string clsPerson::GetLastName() { return _LastName; }
void clsPerson::SetEmail(string Email) { _Email = Email; }
string clsPerson::GetEmail() { return _Email; }
void clsPerson::SetPhone(string Phone) { _Phone = Phone; }
string clsPerson::GetPhone() { return _Phone; }
string clsPerson::FullName() { return _FirstName + " " + _LastName; }