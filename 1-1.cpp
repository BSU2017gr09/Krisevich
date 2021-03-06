//Расположить в порядке возрастания элементы массива А(N), начиная с k-го элемента.
#include <iostream>

using namespace std;

void initArray(int *A, const int N) {
	for (int *p = A; p < A + N; p++) {
		*p = rand() % 11;
	}
}

void printArray(int *A, const int N) {
	for (int *p = A; p < A + N; p++) {
		cout << *p << " ";
	}
}


void sortArray(int *A, const int N, int k) {
	for (int *p = A + k; p < A + N; p++) {
		for (int *q = A + k; q < A + N; q++) {
			if (*p < *q) {
				swap(*q, *p);
			}

		}
	}
}

int *giveMemory(int N) {
	int *A;
	try {
		A = new int[N];
	}
	catch (...) {
		cout << "Error! Failed to creat array";
		return 0;
	}
	return A;
}
int *delMemory(int *A, int N) {
	delete[N] A;
	return 0;
}


int main() {
	setlocale(LC_ALL, "Rus");
	int N = 0;
	int k = 0;
	int *A;
	cout << "Enter the number of elements" << endl;
	cin >> N;
	cout << "Enter the number of element from which the array is sorted" << endl;
	cin >> k;
	A = giveMemory(N);
	initArray(A, N);
	cout << "Initial array: ";
	printArray(A, N);
	sortArray(A, N, k);
	cout << endl;
	cout << "Sorted array: ";
	printArray(A, N);
	delMemory(A, N);
	system("pause");
	return 0;
}