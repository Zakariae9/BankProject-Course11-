#include "clsInputValidate.hpp"

bool clsInputValidate::IsNumberBetween(short Number, short From, short To) { return (Number >= From && Number <= To); }
bool clsInputValidate::IsNumberBetween(int Number , int From, int To) { return (Number >= From && Number <= To); }
bool clsInputValidate::IsNumberBetween(float Number, float From, float To) { return (Number >= From && Number <= To); }
bool clsInputValidate::IsNumberBetween(double Number, double From, double To) { return (Number >= From && Number <= To); }

bool clsInputValidate::IsDateBetween(clsDate Date, clsDate From, clsDate To) {
	if ((clsDate::IsDate1AfterDate2(Date, From) || clsDate::IsDate1EqualDate2(Date, From)) && (clsDate::IsDate1BeforeDate2(Date, To) || clsDate::IsDate1EqualDate2(Date, To))) return true;
	if ((clsDate::IsDate1AfterDate2(Date, To) || clsDate::IsDate1EqualDate2(Date, To)) && (clsDate::IsDate1BeforeDate2(Date, From) || clsDate::IsDate1EqualDate2(Date, From))) return true;
	return false;
}

int clsInputValidate::ReadIntNumber(string ErrorMessage) {
	int Number;
	while (!(cin >> Number)) { cin.clear(); cin.ignore(numeric_limits<streamsize>::max(), '\n'); cout << ErrorMessage; }
	return Number;
}

int clsInputValidate::ReadIntNumberBetween(int From, int To, string ErrorMessage) {
	int Number = ReadIntNumber();
	while (!IsNumberBetween(Number,From,To)) { cout << ErrorMessage; Number = ReadIntNumber(); }
	return Number;
}

string clsInputValidate::ReadStr(string Text)
{
	string Str = "";
	do
	{
		cout << Text;
		cin >> Str;
	} while (Str == "");
	return Str;
}

short clsInputValidate::ReadShortNumberBetween(short From, short To, string ErrorMessage) {
	short Number = ReadIntNumber();
	while (!IsNumberBetween(Number,From,To))
	{
		cout << ErrorMessage; Number = ReadIntNumber();
	}
	return Number;
}

double clsInputValidate::ReadDblNumber(string ErrorMessage) {
	double Number;
	while (!(cin >> Number))
	{
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << ErrorMessage;
	}
	return Number;
}

double clsInputValidate::ReadDblNumberBetween(double From, double To, string ErrorMessage) {
	double Number = ReadDblNumber();
	while (!IsNumberBetween(Number, From, To)) { cout << ErrorMessage; Number = ReadDblNumber(); }
	return Number;
}

bool clsInputValidate::IsValideDate(clsDate Date) { return clsDate::IsValidDate(Date); }