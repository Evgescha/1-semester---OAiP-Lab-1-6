//---------------------------------------------------------------------------

#pragma hdrstop

#include "Model.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)

void CPoint::Move (double dx, double dy)
{
  Hide();
  SetX(x+dx);
  SetY(y+dy);
  return;
}
CPoint::CPoint (double n_x, double n_y, TCanvas * Cnv, TColor nClr, TColor nBgClr)
{
  x = n_x;
  y = n_y;
  pCnv = Cnv;
  Clr = nClr;
  BgClr = nBgClr;
}
void CPoint::Hide()
{
  TColor t = pCnv->Brush->Color;
  pCnv->Pen->Color = BgClr;
  Paint();
  pCnv->Pen->Color = t;
  return;
}
void CPoint::Show()
{
  TColor t = pCnv->Brush->Color;
  pCnv->Pen->Color = Clr;
  Paint();
  pCnv->Pen->Color = t;
  return;
}
void CPoint::Paint()
{
	pCnv->Rectangle(x,y,x+10,y+10);
}
void CCircle::Paint()
{
	pCnv->Ellipse(x,y,x+40,y+40);
}
void CRectangl::Paint()
{
	pCnv->Rectangle(x,y,x+50,y+70);
}

 void CPole::addPoint(double n_x, double n_y)
{
	  CPoint *r1 = new CPoint(n_x,n_y,Cnv,Clr,BgClr);
	  r1->Show();
	  pPtLst->Add(r1);
}

 void CPole::addCircle(double n_x, double n_y)
{
	  CCircle *r1 = new CCircle(n_x,n_y,Cnv,Clr,BgClr);
	  r1->Show();
	  pPtLst->Add(r1);
}

 void CPole::addRectangl(double n_x, double n_y)
{
	  CRectangl *r1 = new CRectangl(n_x,n_y,Cnv,Clr,BgClr);
	  r1->Show();
	  pPtLst->Add(r1);
}

 CPole::CPole(TCanvas * Cnv, TColor Clr, TColor BgClr)
 {
	pPtLst = new TList;
   this->Cnv = Cnv;
   this->Clr = Clr;
   this->BgClr = BgClr;
 }

  CPole::~CPole()
 {
  for (int i = 0; i < pPtLst->Count; i++)
  {
	CPoint *p = (CPoint*) pPtLst->Items[i];
	delete p;
  }
	pPtLst->Free();
 }

 void CPole::fly(int left, int top, int right, int bottom
 )
 {
	  for (int i = 0; i < pPtLst->Count; i++)
	  {
		CPoint *p = (CPoint*) pPtLst->Items[i];
		p->Move(20-random(40),20-random(40));
	  }
		for (int i = 0; i < pPtLst->Count; i++)
	  {
		CPoint *p = (CPoint*) pPtLst->Items[i];
		p->Show();
	  }
  }
