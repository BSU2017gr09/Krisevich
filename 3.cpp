//59. В массиве А(N, M) расположить столбцы в порядке возрастания количества нулевых элементов в каждом столбце.
#include <iostream>

using namespace std;

int** giveMemory(int N, int M)
{
	int* *tmp = new int*[N];
	for (int i = 0; i < N; i++)
		tmp[i] = new int[M];
	return tmp;
}

void printArray(int* *p, int N, int M)
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
			cout << p[i][j] << '\t';
		cout << endl;
	}
}

void initArray(int* *p, int N, int M)
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
			p[i][j] = rand() % 3 - 1;
	}
}

void ifnull(int* *p, int N, int M)
{
	int* null;
	try
	{
		null = new int[N];
	}
	catch (...)
	{
		exit(1);
	}
	int count = 0;
	int j = 0;
	while (j < M)
	{
		for (int i = 0; i < N; i++)
		{
			if (p[i][j] == 0)
			{
				count++;
			}
		}
		null[j] = count;
		count = 0;
		j++;
	}
	bool ifsort = false;
	while (!ifsort)
	{
		ifsort = true;
		for (int j = 0; j < M - 1; j++)
		{
			if (null[j] < null[j + 1])
			{
				for (int i = 0; i < N; i++)
				{
					swap(p[i][j], p[i][j + 1]);
				}
				swap(null[j], null[j + 1]);
				ifsort = false;
			}
		}

	}
}

int main()
{
	int N, M;
	cout << "enter N" << endl;
	cin >> N; 
	cout << "enter N" << endl;
	cin >> M;
	int* *p = nullptr;
	p = giveMemory(N, M);
	initArray(p, N, M);
	cout << "-----------------------------------------------------------" << endl;
	cout << "initial array:" << endl;
	printArray(p, N, M);
	cout << "-----------------------------------------------------------" << endl;
	cout << "sorted array:" << endl;
	ifnull(p, N, M);
	printArray(p, N, M);
	system("pause");
}