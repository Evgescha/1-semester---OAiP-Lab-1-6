//---------------------------------------------------------------------------

#pragma hdrstop
 #include <fstream>
#include "DinLst.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)



  Itm * CrItm(int Id,char* Inf)
  {
	Itm *t = new Itm;
	t->next = t->prev = NULL;
	t->id = Id;
	strcpy(t->Info,Inf);
	return t;
  }


 List* CreateList(char* Name, char *Inf) {
	List *lst = new List;
	strcpy(lst->Name,Name);
	lst->getId = 0;
	lst->bg = CrItm(lst->getId,Inf);
	lst->end = lst->bg;
	return lst;
	}

  Itm* AddHead(List* lst, char *Inf) {

	lst->cur = CrItm(++lst->getId,Inf);
	lst->bg->prev = lst->cur;
	lst->cur->next = lst->bg;
	lst->bg = lst->cur;
	return lst->bg;
	}

void ViewLst(List* lst){
printf(" %s \n", lst->Name);
lst->cur = lst->bg;
while( lst->cur) {
printf("%i:  %s \n", lst->cur->id, lst->cur->Info);
lst->cur = lst->cur->next;
}
}

void DelHead(List* lst) {

if(lst->bg == lst->end)
DelLst(lst);
else
{
lst->cur = lst->bg;
lst->bg = lst->bg->next;
lst->bg->prev = NULL;
delete lst->cur;
}
}

void DelLst(List* lst) {
while( lst->bg!=lst->end) DelHead(lst);
 delete lst->bg;
 delete lst;
}


void ViewLstBk(List* lst){
printf(" %s \n", lst->Name);
lst->cur = lst->end;
while( lst->cur) {
printf("%i:  %s \n", lst->cur->id, lst->cur->Info);
			lst->cur = lst->cur->prev;
		}
}



List* Readf(char* fileName, char* lstName)
{
	const int SIZE = 50;
	char* bufer = new char[SIZE];
	ifstream readf(fileName);
	readf.getline(bufer, SIZE);
	List* lst = CreateList(lstName, bufer);
	while(!readf.eof())
	{
		readf.getline(bufer, SIZE);
		AddHead(lst, bufer);
	}
	readf.close();
	return lst;
}

Itm* PlInTail(List* lst, int _id)
{
	//Ёто переставл€ет элемент с заданным id в конец списка
	if(lst->bg->id == _id)   //если указан первый элемент
	{
		lst->cur = lst->bg;
		lst->cur->next->prev = NULL;
		lst->bg = lst->bg->next;
		lst->end->next = lst->cur;
		lst->cur->prev = lst->end;
		lst->end = lst->cur;
		lst->end->next = NULL;
	}
	else if(lst->end->id == _id)   //если указан последний элемент
	{	printf("”же в конце списка.\n");	}
	else                           //если указан элемент "в середине" списка
	{
		lst->cur = lst->bg;
		while(lst->cur)
		{
			if(lst->cur->id == _id)
			{
				lst->cur->next->prev = lst->cur->prev;
				lst->cur->prev->next = lst->cur->next;
				lst->end->next = lst->cur;
				lst->cur->prev = lst->end;
				lst->end = lst->cur;
				lst->cur->next = NULL;
				break;
			}
			else
			{	lst->cur = lst->cur->next;	}
		}
	}

	//это исправл€ет id(чтоб по пор€дку шли). Ќе уверен, что это нужно делать, но так красивее
                                         //раскомменть, если понадобитс€
	/*lst->cur = lst->end;
	lst->cur->id = 0;
	while(lst->cur->prev)
	{
		lst->cur->prev->id = lst->cur->id + 1; //++ нельз€, т.к. увеличитс€ id самого элемента lst->cur
		lst->cur = lst->cur->prev;             //что делать не надо
	}*/

	return lst->end;
}
