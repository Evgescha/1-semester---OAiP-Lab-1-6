
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
cout<<"Введите сторону квадрата  ";
cin >> stor;
cout<<"Введите координату X ";
cin >> x;
cout<<"Введите координату Y ";
cin >> y;
	   cout<<"Фигура задается по стороне квадрата \n";
	   Square* SqtStor = new Square (stor);
	   S = SqtStor->SFig();
	   P = SqtStor->PFig();
	   cout<<"Периметр квадрата\n";
	   cout<< P << "\n";
	   cout<<"Площадь квадрата\n";
	   cout<< S << "\n";
	   cout<< "Угол для поворота \n";
	   cin >> Angle;
	   cout<<"Фигура задается по начальным координатам и стороне квадрата\n";
	   Square* SqtXYStor = new Square(x, y, stor);
	   cout<<"Поворот квадрата\n";
	   SqtXYStor->RotateFig(Angle);
	   cout<<"Координата х = " << SqtXYStor->x1 << "\nКоордината у =  " << SqtXYStor->y1  << endl ;
	   cout<<"Задается куб\n";
	   Cube* c = new Cube(x, y, stor);
	   SP = c->SPoverhnosti();
	   cout<<"Площадь поверхности куба = " << SP << " \n";
	   V = c->Objom();
	   cout<<"Объем куба = " << V << " \n";
	   cout<<"Поворот куба\n";
	   c->RotateFig(Angle);
	cout<<"Координата х = " << c->x1 << "\nКоордината у =  " << c->y1 << "\nКоордината z =  " << c->z << endl ;
	system("pause");
	return 0;
}
//---------------------------------------------------------------------------
