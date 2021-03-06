//Даны точки плоскости своими координатами в виде двух одномерных массивов. Точки плоскости рассортировать по возрастанию расстояния до прямой ax + by + c = 0.
#include <iostream>

using namespace std;

void initArray(float *A, const int N) {
	for (float *p = A; p < A + N; p++) {
		*p = rand() % 10;
	}
}

void printArray(float *A, const int N) {
	for (float *p = A; p < A + N; p++) {
		cout << *p << "  ";
	}
	cout << endl;
}

float countDist(float x, float y, float a, float b, float c) {
	float dist = abs(a*x + b*y + c) / sqrt(a*a + b*b);
	return dist;
}

float *giveMemory(int N) {
	float *A;
	try {
		A = new float[N];
	}
	catch (...) {
		cout << "Error! Failed to creat array";
		return 0;
	}
	return A;
}

int *delMemory(float *A, int N) {
	delete[N] A;
	return 0;
}

void sortPoints(float *A, float *B, const int N, float a, float b, float c) {
	for (float *p = A, *q = B; p < A + N; p++, q++) {
		for (float *k = p, *i = q; k < A + N; k++, i++) {
			if (countDist(*p, *q, a, b, c) > countDist(*k, *i, a, b, c)) {
				swap(*k, *p);
				swap(*i, *q);
			}

		}
	}
}




int main() {
	setlocale(LC_ALL, "Ru");
	int N = 0;
	float a = 0;
	float b = 0;
	float c = 0;
	float *A;
	float *B;

	cout << "Enter number of points: ";
	cin >> N;
	A = giveMemory(N);
	B = giveMemory(N);
	cout << "Enter coefficients a, b, c of a line:" << endl;;
	cout << "a=";
	cin >> a;
	cout << "b=";
	cin >> b;
	cout << "c=";
	cin >> c;
	initArray(A, N);
	initArray(B, N);
	printArray(A, N);
	printArray(B, N);
	sortPoints(A, B, N, a, b, c);
	cout << "Sorted arrays:" << endl;
	printArray(A, N);
	printArray(B, N);
	system("pause");
	delMemory(A, N);
	return 0;
}