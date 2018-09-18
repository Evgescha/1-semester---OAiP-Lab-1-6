//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------



void __fastcall TForm1::FormCreate(TObject *Sender)
{
   Pole = new CPole(Canvas,(Graphics::TColor) 1147483647 , clBtnFace);
}
//---------------------------------------------------------------------------











void __fastcall TForm1::FormMouseUp(TObject *Sender, TMouseButton Button, TShiftState Shift,
          int x, int y)
{
	   if(PointSel->Checked)
	   {
	   Pole->addPoint(x,y);
	   }
	   if(CircSel->Checked)
	   {
	   Pole->addCircle(x,y);
	   }
	   if(RectSel->Checked)
	   {
	   Pole->addRectangl(x,y);
	   }
}
//---------------------------------------------------------------------------





void __fastcall TForm1::Button1MouseDown(TObject *Sender, TMouseButton Button, TShiftState Shift,
          int X, int Y)
{
	 Timer1->Enabled=true;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button1MouseUp(TObject *Sender, TMouseButton Button, TShiftState Shift,
		  int X, int Y)
{
		 Timer1->Enabled=false;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Timer1Timer(TObject *Sender)
{
    Pole->fly(-Form1->Left + 5, -Form1->Top + 10, Form1->ClientWidth, Form1->ClientHeight);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::TrackBar1Change(TObject *Sender)
{
Timer1->Interval=  TrackBar1->Position;
}
//---------------------------------------------------------------------------

