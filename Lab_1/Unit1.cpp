//---------------------------------------------------------------------------


#pragma hdrstop
#include <iostream>
#include <windows.h>
#include "DinLst.h"
#include <fstream>
//---------------------------------------------------------------------------

#pragma argsused
int main(int argc, char* argv[])
{
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);



	List* myList = Readf("text.txt", "��������");
	AddHead(myList, "�������� �.�");
	ViewLst(myList);

	PlInTail(myList, 3);
	ViewLst(myList);




system("pause");
        return 0;
}
//---------------------------------------------------------------------------
 