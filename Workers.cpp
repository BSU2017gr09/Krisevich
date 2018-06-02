#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string.h>
#include <iomanip>

using namespace std;


class Worker
{
private:
	int num;
	char *name;
	int year;
	int salary;
public:
	// Great 4
	Worker() : num(0), name(nullptr), year(0), salary(0)
	{
		//cout << "Constructor is working" << endl;
	};
	Worker(char *N) : num(0), name(nullptr), year(0), salary(0)
	{
		//cout << "SuperPuperConstructor is working" << endl;
		try {
		name = new char[strlen(N) + 1];
		}
		catch (...) {
			cout << "error! connot allocate memory" << endl;
		}
		strcpy(name, N);
	};
	Worker(int Num, char *N, int K, int M) : num(Num), name(nullptr), year(K), salary(M)
	{
		//cout << "MySuperPuperConstructor is working" << endl;
		try {
		name = new char[strlen(N) + 1];
		}
		catch (...) {
			cout << "error! connot allocate memory" << endl;
		}
		strcpy(name, N);
	};
	~Worker() { delete[]name; };
	Worker(Worker &other) : num(other.num), name(nullptr), year(other.year), salary(other.salary)
	{
		//cout << "Copy-constructor is working" << endl;
		try {
			name = new char[strlen(other.name) + 1]; // и тут ВНЕЗАПНО утечка памяти !!!!
		}
		catch (...) {
			cout << "error! connot allocate memory" << endl;
		}
		strcpy(name, other.name);
	};
	void operator= (const Worker &other)
	{
		//cout << "Operator = is working" << endl;
		if (this == &other) return;
		delete[]name;
		try {
		name = new char[strlen(other.name) + 1];
		}
		catch (...) {
			cout << "error! connot allocate memory" << endl;
		}
		strcpy(name, other.name);
		num = other.num;
		year = other.year;
		salary = other.salary;
	};
	void setnum(int Num) { num = Num; };
	void setname(char* str) { 
		delete[]name; 
		try {
			name = new char[strlen(str) + 1];
		}
		catch (...) {
			cout << "error! cannot allocate memory" << endl;
		}
		strcpy((*this).name, str); 
	};
	void setyear(int K) { year = K; };
	void setsalary(int M) { salary = M; };

	int getnum() { return (*this).num; };
	char* getname() { return (*this).name; };
	int getyear() { return (*this).year; };
	int getsalary() { return (*this).salary; };

};

void printWorker(Worker t) {
	cout << setw(4) << left << t.getnum() << " " << setw(20) << left << t.getname() << " " << t.getyear() << " " << t.getsalary() << endl;
}

void printWorker(Worker T[], int N) {
	for (int i = 0; i < N; i++) {
		cout << setw(4) << left << T[i].getnum() << " " << setw(20) << left << T[i].getname() << " " << T[i].getyear() << " " << T[i].getsalary() << endl;
	}
}

void randWorker(Worker T[], int N) {
	char * names[12] = { "Арбайтов", "Арбайтович", "Арбайтицын", "Воркерович", "Воркин", "Воркерцов", "Работников", "Работин", "Работникошвили", "Трабахайтер", "Трабахович", "Трабахин" };
	for (int i = 0; i < N; i++) {
		T[i].setnum(i);
		T[i].setname(names[rand() % 12]);
		T[i].setyear(rand() % 30 + 1970);
		T[i].setsalary(rand() % 300 + 50);
	}
}

Worker findRichest(Worker T[], int N) {
	int richest = 0;
	for (int i = 1; i < N; i++) {
		if (T[i].getsalary() > T[richest].getsalary()) {
			richest = i;
		}
	}
	return T[richest];
}

int averageSalary(Worker T[], int N) {
	int tmp = 0;
	for (int i = 1; i < N; i++) {
		tmp += T[i].getsalary();
	}
	return tmp / N;
}

void sortByAge(Worker T[], int N) {
	bool sorted = false;
	while (!sorted) {
		sorted = true;
		for (int i = 0; i < N - 1; i++)
		{
			if (T[i].getyear() < T[i + 1].getyear()) {
				swap(T[i], T[i + 1]);
				sorted = false;
			}
		}
	}
}

int main() {
	setlocale(LC_ALL, "ru");
	const int N = 10;
	Worker Grisha;
	Worker Barv("Серж");
	Worker Denis(100, "Денис", 1999, 96);
	Worker gr9[N];

	randWorker(gr9, N);
	cout << "Сотрудники 9 группы:" << endl;
	printWorker(gr9, N);
	cout << endl;

	gr9[0] = Denis;
	cout << "До    ";
	printWorker(Denis);
	Denis.setname("Крисевич");
	Denis.setsalary(100);
	cout << "После ";
	printWorker(Denis);
	cout << endl;

	cout << "Сотрудник с наибольшей зарплатой:" << endl;
	printWorker(findRichest(gr9, N));
	cout << endl;

	cout << "Средняя зарплата сотрудника:" << endl;
	cout << averageSalary(gr9, N) << endl << endl;

	cout << "Сотрудники 9 группы отсортированные по возрасту:" << endl;
	sortByAge(gr9, N);
	printWorker(gr9, N);
	cout << endl;

	system("pause");
	return 0;
}
