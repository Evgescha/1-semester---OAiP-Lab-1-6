#include "stdafx.h" 
#include <string> 
#include <fstream> 
#include <iostream> 
#include <windows.h> 
#include <queue> 
#include <conio.h> 

using namespace std;

bool* wave(int A[8][8],int N, int St)
// �������� ��������
{
	queue<int> iQueue;
	int *distance = new int[N];
	// ��������� ������� ������������� ����
	for (int i = 0; i < N; i++)
		distance[i] = INT_MAX;
	// ��������� ����� � �������
	iQueue.push(St-1); // � ��������� �� � ���� ,� �� ������� � 1.
	// ��������� �� ��� ����� = 0
	distance[St-1] = 0; // � ��������� �� � ���� ,� �� ������� � 1.
	// ���� ������� �� �����

	bool* a = new bool[8]; 
		for (int i = 0; i < N; i++)
		{
			a[i] = 0;
		}
	while (!iQueue.empty())
	{
		// ������� �� ������� ����� ��������� �������
		int Curr = iQueue.front();
		iQueue.pop();
		// ���������� ��� �������
		for (int i = 0; i < N; i++)
		{
			//���� ����� ���� curr ������� � ������� i
			if (A[Curr][i] >= 1)  //�urr-��  i-����
				// ���� ��������� �� ������ �� ������ ������� (i) ������� INT_MAX, �.�. �� ��� �����������
				// ��� ������� i ����������� ����� � ������ ��� Curr ����� �� ������� � ��� ������������ �������
				if (distance[i] > distance[Curr] + A[Curr][i])
				{
					// �� ������������� � ������ ��������� �� ������ �� ����������� ������� (Curr) +
					// + 1 (� ������� � ��� 1 �.�. ���� �� ���������� (���������� �/� ��������� =1))
					distance[i] = distance[Curr] + A[Curr][i];
					// � ���������� ������� i � �������
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
		cout << "�� ���������� ������� ����" << endl;
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
	cout <<"\n������� ������� �����: ";
	cin >> x;
	if (x > n)
	{
		cout << "������ ������ �� ����������." << endl;
		getch();
		return 0;
	}
	
	bool* v = wave(A, n, x ); 
	for (int i = 0; i < n; i++)
	{
		if (v[i] == 0)
		{
			cout << "�� ������ " << x << " �� ������ ������ ������� � ����� " << i + 1 << endl;
		}
	}
	getch();
    return 0;
}

