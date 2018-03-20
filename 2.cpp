//54. (7-8) «аменить все слова в строке заданной подстрокой, если длина слова совпадает с длиной подстроки и слово содержит хот€ бы одну цифру.
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <cctype>   

using namespace std;

void *giveMemory(char *&str, int N) {
	try {
		str = new char[N];
	}
	catch (...) {
		exit(0);
	}
}

bool withDigit(char *p, int len) {
	for (int i = 0; i < len; i++)
	{
		if (isdigit(*(p + i))) return true;
	}
	return false;
}

void main() {
	setlocale(LC_ALL, "Ru");
	char substr[]="SUBSTRING";
	int substrlen = strlen(substr);
	char  str[] = "Chicag000, the state of 1llinois, is known as The Second City, which refers to its rebuilding after the fire. The current city is litera11y the second Chicago, after the one that disappeared in 1871. It can also refer to the cityТs long-held position as the United StatesТ second largest city, after New York City.";	
	char pat[6] = "., !?";			
	char *p = str;
	char *q = str;
	char *tmp = nullptr;
	giveMemory(tmp, substrlen);
	while (p<q+strlen(str)) {
		p = p + strspn(p, pat);
		int len = strcspn(p, pat);
		if (len == substrlen && withDigit(p, len))
		{
			strcpy(tmp, p + len);
			*p = '\0';
			strcat(p, substr);
			strcat(p + len, tmp);
		}
		p = p + len;
	}
	cout << q << endl;
	delete[] tmp;
	system("pause");
}