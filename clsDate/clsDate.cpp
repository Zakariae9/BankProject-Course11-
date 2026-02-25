#include "clsDate.hpp"

clsDate::clsDate() {
	time_t t = time(0);
	tm* now = localtime(&t);
	_Day = now->tm_mday;
	_Month = now->tm_mon + 1;
	_Year = now->tm_year + 1900;
}

clsDate::clsDate(string sDate) {
	vector <string> vDate = clsString::Split(sDate, "/");
	_Day = stoi(vDate[0]);
	_Month = stoi(vDate[1]);
	_Year = stoi(vDate[2]);
}

clsDate::clsDate(short Day, short Month, short Year) {
	_Day = Day;
	_Month = Month;
	_Year = Year;
}

clsDate::clsDate(short DateOrderInYear, short Year) {
	clsDate Date1 = GetDateFromDayOrderInYear(DateOrderInYear, Year);
	_Day = Date1.GetDay();
	_Month = Date1.GetMonth();
	_Year = Date1.GetYear();
}

void clsDate::SetDay(short Day) { _Day = Day; }
short clsDate::GetDay() { return _Day; }
void clsDate::SetMonth(short Month) { _Month = Month; }
short clsDate::GetMonth() { return _Month; }
void clsDate::SetYear(short Year) { _Year = Year; }
short clsDate::GetYear() { return _Year; }
void clsDate::Print() { cout << DateToString() << endl; }

clsDate clsDate::GetSystemDate() {
	time_t t = time(0); tm* now = localtime(&t);
	return clsDate(now->tm_mday, now->tm_mon + 1, now->tm_year + 1900);
}

bool clsDate::IsValidDate(clsDate Date) {
	if (Date.GetDay() < 1 || Date.GetDay() > 31) return false;
	if (Date.GetMonth() < 1 || Date.GetMonth() > 12) return false;
	if (Date.GetMonth() == 2) {
		if (isLeapYear(Date.GetYear())) { if (Date.GetDay() > 29) return false; }
		else { if (Date.GetDay() > 28) return false; }
	}
	short DaysInMonth = NumberOfDaysInAMonth(Date.GetMonth(), Date.GetYear());
	if (Date.GetDay() > DaysInMonth) return false;
	return true;
}

bool clsDate::IsValid() { return IsValidDate(*this); }
string clsDate::DateToString(clsDate Date) { return to_string(Date.GetDay()) + "/" + to_string(Date.GetMonth()) + "/" + to_string(Date.GetYear()); }
string clsDate::DateToString() { return DateToString(*this); }
bool clsDate::isLeapYear(short Year) { return (Year % 4 == 0 && Year % 100 != 0) || (Year % 400 == 0); }
bool clsDate::isLeapYear() { return isLeapYear(_Year); }
short clsDate::NumberOfDaysInAYear(short Year) { return isLeapYear(Year) ? 365 : 364; }
short clsDate::NumberOfDaysInAYear() { return NumberOfDaysInAYear(_Year); }
short clsDate::NumberOfHoursInAYear(short Year) { return NumberOfDaysInAYear(Year) * 24; }
short clsDate::NumberOfHoursInAYear() { return NumberOfHoursInAYear(_Year); }
int clsDate::NumberOfMinutesInAYear(short Year) { return NumberOfHoursInAYear(Year) * 60; }
int clsDate::NumberOfMinutesInAYear() { return NumberOfMinutesInAYear(_Year); }
int clsDate::NumberOfSecondsInAYear(short Year) { return NumberOfMinutesInAYear(Year) * 60; }
int clsDate::NumberOfSecondsInAYear() { return NumberOfSecondsInAYear(_Year); }

short clsDate::NumberOfDaysInAMonth(short Month, short Year) {
	if (Month < 1 || Month>12) return 0;
	int days[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
	return (Month == 2) ? (isLeapYear(Year) ? 29 : 28) : days[Month - 1];
}
short clsDate::NumberOfDaysInAMonth() { return NumberOfDaysInAMonth(_Month, _Year); }
short clsDate::NumberOfHoursInAMonth(short Month, short Year) { return NumberOfDaysInAMonth(Month, Year) * 24; }
short clsDate::NumberOfHoursInAMonth() { return NumberOfDaysInAMonth(_Month, _Year) * 24; }
int clsDate::NumberOfMinutesInAMonth(short Month, short Year) { return NumberOfHoursInAMonth(Month, Year) * 60; }
int clsDate::NumberOfMinutesInAMonth() { return NumberOfHoursInAMonth(_Month, _Year) * 60; }
int clsDate::NumberOfSecondsInAMonth(short Month, short Year) { return NumberOfMinutesInAMonth(Month, Year) * 60; }
int clsDate::NumberOfSecondsInAMonth() { return NumberOfMinutesInAMonth(_Month, _Year) * 60; }

short clsDate::DayOfWeekOrder(short Day, short Month, short Year) {
	short a = (14 - Month) / 12; short y = Year - a; short m = Month + (12 * a) - 2;
	return (Day + y + (y / 4) - (y / 100) + (y / 400) + ((31 * m) / 12)) % 7;
}
short clsDate::DayOfWeekOrder() { return DayOfWeekOrder(_Day, _Month, _Year); }

string clsDate::DayShortName(short DayOfWeekOrder) { string arrDayNames[] = { "Sun","Mon","Tue","Wed","Thu","Fri","Sat" }; return arrDayNames[DayOfWeekOrder]; }
string clsDate::DayShortName(short Day, short Month, short Year) { string arrDayNames[] = { "Sun","Mon","Tue","Wed","Thu","Fri","Sat" }; return arrDayNames[DayOfWeekOrder(Day, Month, Year)]; }
string clsDate::DayShortName() { string arrDayNames[] = { "Sun","Mon","Tue","Wed","Thu","Fri","Sat" }; return arrDayNames[DayOfWeekOrder(_Day, _Month, _Year)]; }

string clsDate::MonthShortName(short MonthNumber) {
	string Months[12] = { "Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec" };
	return (Months[MonthNumber - 1]);
}
string clsDate::MonthShortName() { return MonthShortName(_Month); }

void clsDate::PrintMonthCalendar(short Month, short Year) {
	int current = DayOfWeekOrder(1, Month, Year);
	int NumberOfDays = NumberOfDaysInAMonth(Month, Year);
	printf("\n  _______________%s_______________\n\n", MonthShortName(Month).c_str());
	printf("  Sun  Mon  Tue  Wed  Thu  Fri  Sat\n");
	int i; for (i = 0; i < current; i++) printf("     ");
	for (int j = 1; j <= NumberOfDays; j++) {
		printf("%5d", j);
		if (++i == 7) { i = 0; printf("\n"); }
	}
	printf("\n  _________________________________\n");
}
void clsDate::PrintMonthCalendar() { PrintMonthCalendar(_Month, _Year); }

void clsDate::PrintYearCalendar(int Year) {
	printf("\n  _________________________________\n\n");
	printf("           Calendar - %d\n", Year);
	printf("  _________________________________\n");
	for (int i = 1; i <= 12; i++) PrintMonthCalendar(i, Year);
}
void clsDate::PrintYearCalendar() { PrintYearCalendar(_Year); }

short clsDate::DaysFromTheBeginingOfTheYear(short Day, short Month, short Year) {
	short TotalDays = 0;
	for (int i = 1; i <= Month - 1; i++) TotalDays += NumberOfDaysInAMonth(i, Year);
	TotalDays += Day; return TotalDays;
}
short clsDate::DaysFromTheBeginingOfTheYear() { return DaysFromTheBeginingOfTheYear(_Day, _Month, _Year); }

clsDate clsDate::GetDateFromDayOrderInYear(short DateOrderInYear, short Year) {
	clsDate Date; short RemainingDays = DateOrderInYear; short MonthDays = 0; 
	Date.SetYear(Year); Date.SetMonth(1);
	while (true) {
		MonthDays = NumberOfDaysInAMonth(Date.GetMonth(), Year);
		if (RemainingDays > MonthDays) { RemainingDays -= MonthDays; Date.SetMonth(Date.GetMonth() + 1); }
		else { Date.SetDay(RemainingDays); break; }
	}
	return Date;
}

void clsDate::AddDays(short Days) {
	short RemainingDays = Days + DaysFromTheBeginingOfTheYear(_Day, _Month, _Year);
	short MonthDays = 0; _Month = 1;
	while (true) {
		MonthDays = NumberOfDaysInAMonth(_Month, _Year);
		if (RemainingDays > MonthDays) {
			RemainingDays -= MonthDays; _Month++;
			if (_Month > 12) { _Month = 1; _Year++; }
		}
		else { _Day = RemainingDays; break; }
	}
}

bool clsDate::IsDate1BeforeDate2(clsDate Date1, clsDate Date2) { 
	return (Date1.GetYear() < Date2.GetYear()) ? true : ((Date1.GetYear() == Date2.GetYear()) ? (Date1.GetMonth() < Date2.GetMonth() ? true : (Date1.GetMonth() == Date2.GetMonth() ? Date1.GetDay() < Date2.GetDay() : false)) : false); 
}
bool clsDate::IsDateBeforeDate2(clsDate Date2) { return IsDate1BeforeDate2(*this, Date2); }

bool clsDate::IsDate1EqualDate2(clsDate Date1, clsDate Date2) { 
	return (Date1.GetYear() == Date2.GetYear()) ? ((Date1.GetMonth() == Date2.GetMonth()) ? ((Date1.GetDay() == Date2.GetDay()) ? true : false) : false) : false; 
}
bool clsDate::IsDateEqualDate2(clsDate Date2) { return IsDate1EqualDate2(*this, Date2); }

bool clsDate::IsLastDayInMonth(clsDate Date) { return (Date.GetDay() == NumberOfDaysInAMonth(Date.GetMonth(), Date.GetYear())); }
bool clsDate::IsLastDayInMonth() { return IsLastDayInMonth(*this); }
bool clsDate::IsLastMonthInYear(short Month) { return (Month == 12); }

clsDate clsDate::AddOneDay(clsDate Date) {
	if (IsLastDayInMonth(Date)) {
		if (IsLastMonthInYear(Date.GetMonth())) { Date.SetMonth(1); Date.SetDay(1); Date.SetYear(Date.GetYear() + 1); }
		else { Date.SetDay(1); Date.SetMonth(Date.GetMonth() + 1); }
	} else { Date.SetDay(Date.GetDay() + 1); }
	return Date;
}
void clsDate::AddOneDay() { *this = AddOneDay(*this); }

void clsDate::SwapDates(clsDate & Date1, clsDate & Date2) { clsDate TempDate = Date1; Date1 = Date2; Date2 = TempDate; }

int clsDate::GetDifferenceInDays(clsDate Date1, clsDate Date2, bool IncludeEndDay) {
	int Days = 0; short SawpFlagValue = 1;
	if (!IsDate1BeforeDate2(Date1, Date2)) { SwapDates(Date1, Date2); SawpFlagValue = -1; }
	while (IsDate1BeforeDate2(Date1, Date2)) { Days++; Date1 = AddOneDay(Date1); }
	return IncludeEndDay ? ++Days * SawpFlagValue : Days * SawpFlagValue;
}
int clsDate::GetDifferenceInDays(clsDate Date2, bool IncludeEndDay) { return GetDifferenceInDays(*this, Date2, IncludeEndDay); }

short clsDate::CalculateMyAgeInDays(clsDate DateOfBirth) { return GetDifferenceInDays(DateOfBirth, clsDate::GetSystemDate(), true); }
clsDate clsDate::IncreaseDateByOneWeek(clsDate & Date) { for (int i = 1; i <= 7; i++) Date = AddOneDay(Date); return Date; }
void clsDate::IncreaseDateByOneWeek() { IncreaseDateByOneWeek(*this); }
clsDate clsDate::IncreaseDateByXWeeks(short Weeks, clsDate& Date) { for (short i = 1; i <= Weeks; i++) Date = IncreaseDateByOneWeek(Date); return Date; }
void clsDate::IncreaseDateByXWeeks(short Weeks) { IncreaseDateByXWeeks(Weeks, *this); }

clsDate clsDate::IncreaseDateByOneMonth(clsDate& Date) {
	if (Date.GetMonth() == 12) { Date.SetMonth(1); Date.SetYear(Date.GetYear() + 1); } else { Date.SetMonth(Date.GetMonth() + 1); }
	short NumberOfDaysInCurrentMonth = NumberOfDaysInAMonth(Date.GetMonth(), Date.GetYear());
	if (Date.GetDay() > NumberOfDaysInCurrentMonth) Date.SetDay(NumberOfDaysInCurrentMonth);
	return Date;
}
void clsDate::IncreaseDateByOneMonth() { IncreaseDateByOneMonth(*this); }
clsDate clsDate::IncreaseDateByXDays(short Days, clsDate& Date) { for (short i = 1; i <= Days; i++) Date = AddOneDay(Date); return Date; }
void clsDate::IncreaseDateByXDays(short Days) { IncreaseDateByXDays(Days, *this); }
clsDate clsDate::IncreaseDateByXMonths(short Months, clsDate& Date) { for (short i = 1; i <= Months; i++) Date = IncreaseDateByOneMonth(Date); return Date; }
void clsDate::IncreaseDateByXMonths(short Months) { IncreaseDateByXMonths(Months, *this); }

clsDate clsDate::IncreaseDateByOneYear(clsDate& Date) { Date.SetYear(Date.GetYear() + 1); return Date; }
void clsDate::IncreaseDateByOneYear() { IncreaseDateByOneYear(*this); }
clsDate clsDate::IncreaseDateByXYears(short Years, clsDate& Date) { Date.SetYear(Date.GetYear() + Years); return Date; }
void clsDate::IncreaseDateByXYears(short Years) { IncreaseDateByXYears(Years, *this); }
clsDate clsDate::IncreaseDateByOneDecade(clsDate& Date) { Date.SetYear(Date.GetYear() + 10); return Date; }
void clsDate::IncreaseDateByOneDecade() { IncreaseDateByOneDecade(*this); }
clsDate clsDate::IncreaseDateByXDecades(short Decade, clsDate& Date) { Date.SetYear(Date.GetYear() + (Decade * 10)); return Date; }
void clsDate::IncreaseDateByXDecades(short Decade) { IncreaseDateByXDecades(Decade, *this); }
clsDate clsDate::IncreaseDateByOneCentury(clsDate& Date) { Date.SetYear(Date.GetYear() + 100); return Date; }
void clsDate::IncreaseDateByOneCentury() { IncreaseDateByOneCentury(*this); }
clsDate clsDate::IncreaseDateByOneMillennium(clsDate& Date) { Date.SetYear(Date.GetYear() + 1000); return Date; }
clsDate clsDate::IncreaseDateByOneMillennium() { return IncreaseDateByOneMillennium(*this); }

clsDate clsDate::DecreaseDateByOneDay(clsDate Date) {
	if (Date.GetDay() == 1) {
		if (Date.GetMonth() == 1) { Date.SetMonth(12); Date.SetDay(31); Date.SetYear(Date.GetYear() - 1); }
		else { Date.SetMonth(Date.GetMonth() - 1); Date.SetDay(NumberOfDaysInAMonth(Date.GetMonth(), Date.GetYear())); }
	} else { Date.SetDay(Date.GetDay() - 1); }
	return Date;
}
void clsDate::DecreaseDateByOneDay() { DecreaseDateByOneDay(*this); }
clsDate clsDate::DecreaseDateByOneWeek(clsDate &Date) { for (int i = 1; i <= 7; i++) Date = DecreaseDateByOneDay(Date); return Date; }
void clsDate::DecreaseDateByOneWeek() { DecreaseDateByOneWeek(*this); }
clsDate clsDate::DecreaseDateByXWeeks(short Weeks, clsDate &Date) { for (short i = 1; i <= Weeks; i++) Date = DecreaseDateByOneWeek(Date); return Date; }
void clsDate::DecreaseDateByXWeeks(short Weeks) { DecreaseDateByXWeeks(Weeks ,*this); }

clsDate clsDate::DecreaseDateByOneMonth(clsDate &Date) {
	if (Date.GetMonth() == 1) { Date.SetMonth(12); Date.SetYear(Date.GetYear() - 1); } else Date.SetMonth(Date.GetMonth() - 1);
	short NumberOfDaysInCurrentMonth = NumberOfDaysInAMonth(Date.GetMonth(), Date.GetYear());
	if (Date.GetDay() > NumberOfDaysInCurrentMonth) Date.SetDay(NumberOfDaysInCurrentMonth);
	return Date;
}
void clsDate::DecreaseDateByOneMonth() { DecreaseDateByOneMonth(*this); }
clsDate clsDate::DecreaseDateByXDays(short Days, clsDate &Date) { for (short i = 1; i <= Days; i++) Date = DecreaseDateByOneDay(Date); return Date; }
void clsDate::DecreaseDateByXDays(short Days) { DecreaseDateByXDays(Days, *this); }
clsDate clsDate::DecreaseDateByXMonths(short Months, clsDate &Date) { for (short i = 1; i <= Months; i++) Date = DecreaseDateByOneMonth(Date); return Date; }
void clsDate::DecreaseDateByXMonths(short Months) { DecreaseDateByXMonths( Months, *this); }

clsDate clsDate::DecreaseDateByOneYear(clsDate &Date) { Date.SetYear(Date.GetYear() - 1); return Date; }
void clsDate::DecreaseDateByOneYear() { DecreaseDateByOneYear(*this); }
clsDate clsDate::DecreaseDateByXYears(short Years, clsDate &Date) { Date.SetYear(Date.GetYear() - Years); return Date; }
void clsDate::DecreaseDateByXYears(short Years) { DecreaseDateByXYears(Years ,*this); }
clsDate clsDate::DecreaseDateByOneDecade(clsDate &Date) { Date.SetYear(Date.GetYear() - 10); return Date; }
void clsDate::DecreaseDateByOneDecade() { DecreaseDateByOneDecade(*this); }
clsDate clsDate::DecreaseDateByXDecades(short Decades, clsDate &Date) { Date.SetYear(Date.GetYear() - (Decades * 10)); return Date; }
void clsDate::DecreaseDateByXDecades(short Decades) { DecreaseDateByXDecades(Decades, *this); }
clsDate clsDate::DecreaseDateByOneCentury(clsDate &Date) { Date.SetYear(Date.GetYear() - 100); return Date; }
void clsDate::DecreaseDateByOneCentury() { DecreaseDateByOneCentury(*this); }
clsDate clsDate::DecreaseDateByOneMillennium(clsDate &Date) { Date.SetYear(Date.GetYear() - 1000); return Date; }
void clsDate::DecreaseDateByOneMillennium() { DecreaseDateByOneMillennium(*this); }

short clsDate::IsEndOfWeek(clsDate Date) { return DayOfWeekOrder(Date.GetDay(), Date.GetMonth(), Date.GetYear()) == 6; }
short clsDate::IsEndOfWeek() { return IsEndOfWeek(*this); }
bool clsDate::IsWeekEnd(clsDate Date) { short DayIndex = DayOfWeekOrder(Date.GetDay(), Date.GetMonth(), Date.GetYear()); return (DayIndex == 5 || DayIndex == 6); }
bool clsDate::IsWeekEnd() { return IsWeekEnd(*this); }
bool clsDate::IsBusinessDay(clsDate Date) { return !IsWeekEnd(Date); }
bool clsDate::IsBusinessDay() { return IsBusinessDay(*this); }
short clsDate::DaysUntilTheEndOfWeek(clsDate Date) { return 6 - DayOfWeekOrder(Date.GetDay(), Date.GetMonth(), Date.GetYear()); }
short clsDate::DaysUntilTheEndOfWeek() { return DaysUntilTheEndOfWeek(*this); }

short clsDate::DaysUntilTheEndOfMonth(clsDate Date1) {
	clsDate EndOfMontDate; EndOfMontDate.SetDay(NumberOfDaysInAMonth(Date1.GetMonth(), Date1.GetYear())); EndOfMontDate.SetMonth(Date1.GetMonth()); EndOfMontDate.SetYear(Date1.GetYear());
	return GetDifferenceInDays(Date1, EndOfMontDate, true);
}
short clsDate::DaysUntilTheEndOfMonth() { return DaysUntilTheEndOfMonth(*this); }

short clsDate::DaysUntilTheEndOfYear(clsDate Date1) {
	clsDate EndOfYearDate; EndOfYearDate.SetDay(31); EndOfYearDate.SetMonth(12); EndOfYearDate.SetYear(Date1.GetYear());
	return GetDifferenceInDays(Date1, EndOfYearDate, true);
}
short clsDate::DaysUntilTheEndOfYear() { return DaysUntilTheEndOfYear(*this); }

short clsDate::CalculateBusinessDays(clsDate DateFrom, clsDate DateTo) {
	short Days = 0;
	while (IsDate1BeforeDate2(DateFrom, DateTo)) { if (IsBusinessDay(DateFrom)) Days++; DateFrom = AddOneDay(DateFrom); }
	return Days;
}
short clsDate::CalculateVacationDays(clsDate DateFrom, clsDate DateTo) { return CalculateBusinessDays(DateFrom, DateTo); }
clsDate clsDate::CalculateVacationReturnDate(clsDate DateFrom, short VacationDays) {
	short WeekEndCounter = 0;
	for (short i = 1; i <= VacationDays; i++) { if (IsWeekEnd(DateFrom)) WeekEndCounter++; DateFrom = AddOneDay(DateFrom); }
	for (short i = 1; i <= WeekEndCounter; i++) DateFrom = AddOneDay(DateFrom);
	return DateFrom;
}
bool clsDate::IsDate1AfterDate2(clsDate Date1, clsDate Date2) { return (!IsDate1BeforeDate2(Date1, Date2) && !IsDate1EqualDate2(Date1, Date2)); }
bool clsDate::IsDateAfterDate2(clsDate Date2) { return IsDate1AfterDate2(*this, Date2); }
clsDate::enDateCompare clsDate::CompareDates(clsDate Date1, clsDate Date2) {
	if (IsDate1BeforeDate2(Date1, Date2)) return enDateCompare::Before;
	if (IsDate1EqualDate2(Date1, Date2)) return enDateCompare::Equal;
	return enDateCompare::After;
}
clsDate::enDateCompare clsDate::CompareDates(clsDate Date2) { return CompareDates(*this, Date2); }