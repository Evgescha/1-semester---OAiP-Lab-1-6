#include "stdafx.h" 
#include <string> 
#include <fstream> 
#include <iostream> 
#include <windows.h> 
#include <queue> 
#include <conio.h> 

using namespace std;

bool* wave(int A[8][8],int N, int St)
// Волновой алгоритм
{
	queue<int> iQueue;
	int *distance = new int[N];
	// заполняем заранее максимальными знач
	for (int i = 0; i < N; i++)
		distance[i] = INT_MAX;
	// начальная точка в очередь
	iQueue.push(St-1); // В программе всё с нуля ,а мы считаем с 1.
	// дистанция до нач точки = 0
	distance[St-1] = 0; // В программе всё с нуля ,а мы считаем с 1.
	// пока очередь не пуста

	bool* a = new bool[8]; 
		for (int i = 0; i < N; i++)
		{
			a[i] = 0;
		}
	while (!iQueue.empty())
	{
		// ДОСТАЁМ ИЗ ОЧЕРЕДИ номер очередной вершины
		int Curr = iQueue.front();
		iQueue.pop();
		// перебираем все вершины
		for (int i = 0; i < N; i++)
		{
			//если связь есть curr вершины и вершины i
			if (A[Curr][i] >= 1)  //Сurr-от  i-куда
				// если дистанция от начала до данной вершины (i) большая INT_MAX, т.е. не ещё установлена
				// или вершина i расположена ближе к началу чем Curr чтобы не перейти к уже обработанной вершине
				if (distance[i] > distance[Curr] + A[Curr][i])
				{
					// то устанавливаем её равной дистанции от начала до исследуемой вершины (Curr) +
					// + 1 (в массиве А все 1 т.к. граф не взвешенный (расстояния м/у вершинами =1))
					distance[i] = distance[Curr] + A[Curr][i];
					// и записываем вершину i в очередь
					iQueue.push(i);
					a[i] = true;
				}
		}
	}
	return a;
}

int main()
{
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);
	ifstream fil("Graf.txt");
		if (!fil.is_open())
	{
		cout << "Не получилось открыть файл" << endl;
		system("pause");
	}
	const int n = 8;
	int A[n][n];
		for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			A[i][j] = 0;
		}
	}
	while (!fil.eof())
	{
		int a, b;
		char c;
		fil >> a;
		fil >> c;
		fil >> b;
		cout << a << " " << c << " " << b << endl;
		A[a - 1][b - 1] = 1;
	}
	fil.close();
	cout << endl;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << A[i][j] << " ";
		}
		cout << endl;
	}
	int x;
	cout <<"\nВведите столицу город: ";
	cin >> x;
	if (x > n)
	{
		cout << "Такого города не существует." << endl;
		getch();
		return 0;
	}
	
	bool* v = wave(A, n, x ); 
	for (int i = 0; i < n; i++)
	{
		if (v[i] == 0)
		{
			cout << "Из города " << x << " по дороге нельзя попасть в город " << i + 1 << endl;
		}
	}
	getch();
    return 0;
}

