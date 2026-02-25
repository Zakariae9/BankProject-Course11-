#pragma once
#include <iostream>
#include <string>
#include <limits> // Added for numeric_limits
#include "../clsString/clsString.hpp"
#include "../clsDate/clsDate.hpp"

using namespace std;

class clsInputValidate
{
public:
	static bool IsNumberBetween(short Number, short From, short To);
	static bool IsNumberBetween(int Number , int From, int To);
	static bool IsNumberBetween(float Number, float From, float To);
	static bool IsNumberBetween(double Number, double From, double To);
	static bool IsDateBetween(clsDate Date, clsDate From, clsDate To);
	static short ReadShortNumberBetween(short From, short To, string ErrorMessage);
	static int ReadIntNumber(string ErrorMessage="Invalid Number, Enter again\n");
	static int ReadIntNumberBetween(int From, int To, string ErrorMessage="Number is not within range, Enter again:\n");
	static double ReadDblNumber(string ErrorMessage = "Invalid Number, Enter again\n");
	static double ReadDblNumberBetween(double From, double To, string ErrorMessage = "Number is not within range, Enter again:\n");
	static string ReadStr(string Text="");
	static bool IsValideDate(clsDate Date);
};