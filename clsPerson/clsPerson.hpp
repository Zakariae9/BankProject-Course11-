#pragma once
#include <iostream>
#include <string>

using namespace std;

class clsPerson 
{
private:
	string _FirstName;
	string _LastName;
	string _Email;
	string _Phone;

public:
	clsPerson(string FirstName, string LastName, string Email, string phone);

	void SetFirstName(string Name);
	string GetFirstName();

	void SetLastName(string Name);
	string GetLastName();

	void SetEmail(string Email);
	string GetEmail();

	void SetPhone(string Phone);
	string GetPhone();

	string FullName();
};