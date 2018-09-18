#include "Square.h"
#include <iostream.h>
#include <math.h>
Square :: Square ()
		{
		  x1=0;
		  y1=0;
		  storona = 5;
		}
Square :: Square (float storon)
		{
		  x1=0;
		  y1=0;
		  storona = storon;
		}
Square :: Square(float x, float y, float storon)
		{
		  x1=x;
		  y1=y;
		  storona=storon;
		}
float Square :: SFig()
	  {
	   float S;
	   S = storona*storona;
	   return S;
	  }
float Square :: PFig()
	  {
	  float PF;
	  PF = storona * 4;
	  return PF;
	  }
void Square ::  RotateFig(float Angle)
	  {
	  Angl = Angle;
	  float xc=0, yc=0, a, b;

		a = (xc +(x1-xc))* cos(Angl*M_PI/180)+(yc-y1)*sin(Angl*M_PI/180);
		b = (yc + (x1 - xc)) * sin(Angl*M_PI/180) + (y1 - yc) * cos(Angl*M_PI/180);
		x1=a;
		y1=b;
	 };

Cube :: Cube(float x, float y, float storona):Square(x,y,storona)
	{
	z = storona;
	}

float Cube :: SPoverhnosti()
	{
	return (6 * SFig());
	}

float Cube :: Objom()
	{
	return (z * SFig());
	}

void Cube :: RotateFig(float Angle)
	 {
	 Angl = Angle;
	 float xc, yc,a,b;
	 z = storona;
	xc = 0;
	yc = 0;
	a = (xc +(x1-xc))* cos(Angl*M_PI/180)+(yc-y1)*sin(Angl*M_PI/180);
	b = (yc + (x1 - xc)) * sin(Angl*M_PI/180) + (y1 - yc) * cos(Angl*M_PI/180);
	x1=a;
	y1=b;
	}
