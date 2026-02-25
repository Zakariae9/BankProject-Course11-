#include "clsUtil.hpp"

void clsUtil::Srand() { srand((unsigned)time(NULL)); }
int clsUtil::RandomNumber(int From, int To) { return rand() % (To - From + 1) + From; }

char clsUtil::GetRandomCharacter(enCharType CharType) {
    if (CharType == MixChars) CharType = (enCharType)RandomNumber(1, 3);
    switch (CharType) {
    case enCharType::SamallLetter: return char(RandomNumber(97, 122));
    case enCharType::CapitalLetter: return char(RandomNumber(65, 90));
    case enCharType::SpecialCharacter: return char(RandomNumber(33, 47));
    case enCharType::Digit: return char(RandomNumber(48, 57));
    default: return char(RandomNumber(65, 90));
    }
}

string clsUtil::GenerateWord(enCharType CharType, short Length) {
    string Word; for (int i = 1; i <= Length; i++) Word = Word + GetRandomCharacter(CharType); return Word;
}

string clsUtil::GenerateKey(enCharType CharType) {
    return GenerateWord(CharType, 4) + "-" + GenerateWord(CharType, 4) + "-" + GenerateWord(CharType, 4) + "-" + GenerateWord(CharType, 4);
}

void clsUtil::GenerateKeys(short NumberOfKeys, enCharType CharType) {
    for (int i = 1; i <= NumberOfKeys; i++) { cout << "Key [" << i << "] : " << GenerateKey(CharType) << endl; }
}

void clsUtil::FillArrayWithRandomNumbers(int arr[100], int arrLength, int From, int To) { for (int i = 0; i < arrLength; i++) arr[i] = RandomNumber(From, To); }
void clsUtil::FillArrayWithRandomWords(string arr[100], int arrLength, enCharType CharType, short Wordlength) { for (int i = 0; i < arrLength; i++) arr[i] = GenerateWord(CharType, Wordlength); }
void clsUtil::FillArrayWithRandomKeys(string arr[100], int arrLength, enCharType CharType) { for (int i = 0; i < arrLength; i++) arr[i] = GenerateKey(CharType); }
void clsUtil::Swap(int& A, int& B) { int Temp = A; A = B; B = Temp; }
void clsUtil::Swap(double& A, double& B) { double Temp = A; A = B; B = Temp; }
void clsUtil::Swap(bool& A, bool& B) { bool Temp = A; A = B; B = Temp; }
void clsUtil::Swap(char& A, char& B) { char Temp = A; A = B; B = Temp; }
void clsUtil::Swap(string& A, string& B) { string Temp = A; A = B; B = Temp; }
void clsUtil::Swap(clsDate& A, clsDate& B) { clsDate::SwapDates(A, B); }
void clsUtil::ShuffleArray(int arr[100], int arrLength) { for (int i = 0; i < arrLength; i++) Swap(arr[RandomNumber(1, arrLength) - 1], arr[RandomNumber(1, arrLength) - 1]); }
void clsUtil::ShuffleArray(string arr[100], int arrLength) { for (int i = 0; i < arrLength; i++) Swap(arr[RandomNumber(1, arrLength) - 1], arr[RandomNumber(1, arrLength) - 1]); }
string clsUtil::Tabs(short NumberOfTabs) { string t = ""; for (int i = 1; i < NumberOfTabs; i++) { t = t + "\t"; cout << t; } return t; }

string clsUtil::NumberToText(int Number) {
    if (Number == 0) return "";
    if (Number >= 1 && Number <= 19) { string arr[] = { "", "One","Two","Three","Four","Five","Six","Seven","Eight","Nine","Ten","Eleven","Twelve","Thirteen","Fourteen","Fifteen","Sixteen","Seventeen","Eighteen","Nineteen" }; return arr[Number] + " "; }
    if (Number >= 20 && Number <= 99) { string arr[] = { "","","Twenty","Thirty","Forty","Fifty","Sixty","Seventy","Eighty","Ninety" }; return arr[Number / 10] + " " + NumberToText(Number % 10); }
    if (Number >= 100 && Number <= 199) return "One Hundred " + NumberToText(Number % 100);
    if (Number >= 200 && Number <= 999) return NumberToText(Number / 100) + "Hundreds " + NumberToText(Number % 100);
    if (Number >= 1000 && Number <= 1999) return "One Thousand " + NumberToText(Number % 1000);
    if (Number >= 2000 && Number <= 999999) return NumberToText(Number / 1000) + "Thousands " + NumberToText(Number % 1000);
    if (Number >= 1000000 && Number <= 1999999) return "One Million " + NumberToText(Number % 1000000);
    if (Number >= 2000000 && Number <= 999999999) return NumberToText(Number / 1000000) + "Millions " + NumberToText(Number % 1000000);
    if (Number >= 1000000000 && Number <= 1999999999) return "One Billion " + NumberToText(Number % 1000000000);
    else return NumberToText(Number / 1000000000) + "Billions " + NumberToText(Number % 1000000000);
}