
#pragma hdrstop
#include <iostream.h>
#include <cmath>
#include <tchar.h>
#include <Windows.h>
#include "Square.h"
using namespace std;
//---------------------------------------------------------------------------
#pragma argsused
int _tmain(int argc, _TCHAR* argv[])
{
SetConsoleOutputCP(1251);
SetConsoleCP(1251);
float x, y, z, stor, _x=0, _y=0;
float P, S, SP, V;
float Angle;
cout<<"������� ������� ��������  ";
cin >> stor;
cout<<"������� ���������� X ";
cin >> x;
cout<<"������� ���������� Y ";
cin >> y;
	   cout<<"������ �������� �� ������� �������� \n";
	   Square* SqtStor = new Square (stor);
	   S = SqtStor->SFig();
	   P = SqtStor->PFig();
	   cout<<"�������� ��������\n";
	   cout<< P << "\n";
	   cout<<"������� ��������\n";
	   cout<< S << "\n";
	   cout<< "���� ��� �������� \n";
	   cin >> Angle;
	   cout<<"������ �������� �� ��������� ����������� � ������� ��������\n";
	   Square* SqtXYStor = new Square(x, y, stor);
	   cout<<"������� ��������\n";
	   SqtXYStor->RotateFig(Angle);
	   cout<<"���������� � = " << SqtXYStor->x1 << "\n���������� � =  " << SqtXYStor->y1  << endl ;
	   cout<<"�������� ���\n";
	   Cube* c = new Cube(x, y, stor);
	   SP = c->SPoverhnosti();
	   cout<<"������� ����������� ���� = " << SP << " \n";
	   V = c->Objom();
	   cout<<"����� ���� = " << V << " \n";
	   cout<<"������� ����\n";
	   c->RotateFig(Angle);
	cout<<"���������� � = " << c->x1 << "\n���������� � =  " << c->y1 << "\n���������� z =  " << c->z << endl ;
	system("pause");
	return 0;
}
//---------------------------------------------------------------------------
