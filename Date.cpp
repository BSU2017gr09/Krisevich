#include <iostream>
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
	Date() : day(0), month(0), year(0) { };
	Date(int D, int M, int Y) :day(D), month(M), year(Y) {  };
	~Date() {};
	Date(Date &other) : day(other.day), month(other.month), year(other.year) {  };
	Date& operator= (const Date &other)
	{	
		cout << "operator = is working" << endl;
		if (this == &other) {
			return *this;
		}
		else {
			day = other.day;
			month = other.month;
			year = other.year;
		}
		
		
	};

	int operator- (Date &other) {
		int days;
		days = year - other.year;
		days = days / 4 + days * 365;
		days += (*this).daysFromNewYear();
		days -= other.daysFromNewYear();
		return days;
	}

	int daysFromNewYear()
	{	
		int days;
		if ((*this).year - ((*this).year / 4) * 4 == 0 && (*this).month > 2) days += 1;
		switch ((*this).month)
		{
		case 1:
			days = 0 + (*this).day;
			break;
		case 2:
			days = 31 + (*this).day;
			break;
		case 3:
			days = 59 + (*this).day;
			break;
		case 4:
			days = 90 + (*this).day;
			break;
		case 5:
			days = 120 + (*this).day;
			break;
		case 6:
			days = 151 + (*this).day;
			break;
		case 7:
			days = 181 + (*this).day;
			break;
		case 8:
			days = 212 + (*this).day;
			break;
		case 9:
			days = 243 + (*this).day;
			break;
		case 10:
			days = 273 + (*this).day;
			break;
		case 11:
			days = 304 + (*this).day;
			break;
		case 12:
			days = 334 + (*this).day;
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

void printMonth(Date t) { //TODO   переписать, использу€ enum!!!
	enum monthList { jan, feb, mar, apr, may, jun, jul, aug, sep, oct, nov, dec};
	
	switch (t.getmonth()) {
	case 1: { cout << "€нварь" << endl; break; }
	case 2: { cout << "февраль" << endl; break; }
	case 3: { cout << "март" << endl; break; }
	case 4: { cout << "апрель" << endl; break; }
	case 5: { cout << "май" << endl; break; }
	case 6: { cout << "июнь" << endl; break; }
	case 7: { cout << "июль" << endl; break; }
	case 8: { cout << "август" << endl; break; }
	case 9: { cout << "сент€брь" << endl; break; }
	case 10: { cout << "окт€брь" << endl; break; }
	case 11: { cout << "но€брь" << endl; break; }
	case 12: { cout << "декабрь" << endl; break; }
	}
}

void printDay(Date t) {
	int a = (14 - t.getmonth()) / 12;
	int y = t.getyear() - a;
	int m = t.getmonth() + 12 * a - 2;
	int day = (t.getday() + y + y / 4 - y / 100 + y / 400 + (31 * m) / 12) % 7;
	switch (day) { //TODO   переписать, использу€ enum!!!
	case 0: { cout << "воскресенье" << endl; break; }
	case 1: { cout << "понедельник" << endl; break; }
	case 2: { cout << "вторник" << endl; break; }
	case 3: { cout << "среда" << endl; break; }
	case 4: { cout << "четверг" << endl; break; }
	case 5: { cout << "п€тница" << endl; break; }
	case 6: { cout << "суббота" << endl; break; }
	}
}


int main() {
	setlocale(LC_ALL, "ru");
	Date birthday(28, 04, 1999);
	Date holyday;
	Date today(17, 04, 2018);
	Date session(04, 06, 2018);
	cout << "ƒней до сессии: " << session - today << endl;
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
