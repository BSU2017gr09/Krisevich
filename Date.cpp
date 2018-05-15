﻿#include <iostream>
#include <string.h>
using namespace std;


class Date
{
private:
	int day;
	int month;
	int year;
public:
	// Great 4
	Date() : day(1), month(1), year(1) { }; //странновато, что именно 1, но я не настаиваю....
	Date(int D, int M, int Y) :day(D), month(M), year(Y) {  };
	~Date() {};
	Date(Date &other) : day(other.day), month(other.month), year(other.year) {  };
	void operator= (const Date &other) // а почему void???
	{
		cout << "operator = is working" << endl;
		day = other.day;
		month = other.month;
		year = other.year;
	};

	int operator- (Date &other) {
		int days, leap;
		days = year - other.year;
		days = days / 4 + days* 365;
		days += (*this).daysFromNewYear();
		days -= other.daysFromNewYear();
		return days;
	}

	int daysFromNewYear()
	{	// Условие if ((*this).year- ((*this).year/ 4) * 4 == 0) записано ДЕСЯТЬ раз!!!! Что за говнокод???? Неужели нельзя 1 раз его использовать?????
		int days;
		switch ((*this).month)
		{
		case 1:
			days = 0 + (*this).day;
			break;
		case 2:
			days = 31 + (*this).day;
			break;
		case 3:
			if ((*this).year- ((*this).year/ 4) * 4 == 0)days = (*this).day + 60;
			else days = 59 + (*this).day;
			break;
		case 4:
			if ((*this).year- ((*this).year/ 4) * 4 == 0)days = 91 + (*this).day;
			else days = 90 + (*this).day;
			break;
		case 5:
			if ((*this).year- ((*this).year/ 4) * 4 == 0) days = 121 + (*this).day;
			else days = 120 + (*this).day;
			break;
		case 6:
			if ((*this).year- ((*this).year/ 4) * 4 == 0) days = 152 + (*this).day;
			else days = 151 + (*this).day;
			break;
		case 7:
			if ((*this).year- ((*this).year/ 4) * 4 == 0) days = 182 + (*this).day;
			else days = 181 + (*this).day;
			break;
		case 8:
			if ((*this).year- ((*this).year/ 4) * 4 == 0) days = 213 + (*this).day;
			else days = 212 + (*this).day;
			break;
		case 9:
			if ((*this).year- ((*this).year/ 4) * 4 == 0) days = 244 + (*this).day;
			else days = 243 + (*this).day;
			break;
		case 10:
			if ((*this).year- ((*this).year/ 4) * 4 == 0) days = 274 + (*this).day;
			else days = 273 + (*this).day;
			break;
		case 11:
			if ((*this).year- ((*this).year/ 4) * 4 == 0) days = 305 + (*this).day;
			else days = 304 + (*this).day;
			break;
		case 12:
			if ((*this).year- ((*this).year/ 4) * 4 == 0) days = 335 + (*this).day;
			else days = 334 + (*this).day;
			break;
		}
		return days;
	}
		
		

	void setday(int D) { day = D; };
	void setmonth(int M) { month = M; };
	void setyear(int Y) { month = Y; };


	int getday() { return (*this).day; };
	int getmonth() { return (*this).month; };
	int getyear() { return (*this).year; };

};

void printDate(Date t) {
	if (t.getday() < 10) cout << "0";
	cout << t.getday() << ".";
	if (t.getmonth() < 10) cout << "0";
	cout << t.getmonth() << "." << t.getyear() << endl;
}

void printMonth(Date t) { //TODO   переписать, используя enum!!!
	switch (t.getmonth()) {
	case 1: { cout << "январь" << endl; break; }
	case 2: { cout << "февраль" << endl; break; }
	case 3: { cout << "март" << endl; break; }
	case 4: { cout << "апрель" << endl; break; }
	case 5: { cout << "май" << endl; break; }
	case 6: { cout << "июнь" << endl; break; }
	case 7: { cout << "июль" << endl; break; }
	case 8: { cout << "август" << endl; break; }
	case 9: { cout << "сентябрь" << endl; break; }
	case 10: { cout << "октябрь" << endl; break; }
	case 11: { cout << "ноябрь" << endl; break; }
	case 12: { cout << "декабрь" << endl; break; }
	}
}

void printDay(Date t) {
	int a = (14 - t.getmonth()) / 12;
	int y = t.getyear() - a;
	int m = t.getmonth() + 12 * a - 2;
	int day = (t.getday() + y + y / 4 - y / 100 + y / 400 + (31 * m) / 12) % 7;
	switch (day) { //TODO   переписать, используя enum!!!
	case 0: { cout << "воскресенье" << endl; break; }
	case 1: { cout << "понедельник" << endl; break; }
	case 2: { cout << "вторник" << endl; break; }
	case 3: { cout << "среда" << endl; break; }
	case 4: { cout << "четверг" << endl; break; }
	case 5: { cout << "пятница" << endl; break; }
	case 6: { cout << "суббота" << endl; break; }
	}
}


int main() {
	setlocale(LC_ALL, "ru");
	Date birthday(28, 04, 1999);
	Date holyday;
	Date today(17, 04, 2018);
	Date session(04, 06, 2018);
	cout <<"Дней до сессии: "<< session - today<<endl;
	printDate(birthday);
	printDate(holyday);
	holyday = birthday;
	printDate(birthday);
	printDate(holyday);
	printDay(birthday);
	printMonth(birthday);

	system("pause");
	return 0;
}
