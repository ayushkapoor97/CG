#include<iostream.h>
#include<stdlib.h>
#include<graphics.h>
#include<stdio.h>
#include<conio.h>
#include<math.h>
#include<dos.h>

void myline(int x0,int y0,int x1,int y1)
{
    int x;
    double dy = y1 - y0;
    double dx = x1 -x0;
    double m = dy/dx;
    double y = y0;
    cout<<"Value of m is :\n"<<m<<"\n";
    int gdrive = DETECT, gmode;
    initgraph(&gdrive, &gmode,"C:\\TurboC3\\BGI");

    if(m<=1)
    {
	y=y0;
	for(x=x0; x<=x1; x++)
	{
	    y = y+m;
	    //cout<<"When k<1 "<<"Value of y ="<<y<<"Value of x = "<<x<<"\n";
	    putpixel(x,floor(y+0.5),WHITE);
	}
    }
    else
    {
	x=x0;
	for(y=y0; y<=y1; y++)
	{
	    x=x+(1/m);
	    //cout<<"When k>1 "<<"Value of y ="<<y<<"Value of x = "<<x<<"\n";
	    putpixel(floor(x+0.5), y,WHITE);
	}
    }
    getch();
}

int main()
{
    int x0;
    int x1;
    int y0;
    int y1;

    cout<<"Enter starting corrdinate\n";
    cin>>x0>>y0;
    cout<<"Enter ending corodinates\n";
    cin>>x1>>y1;
    myline(x0, y0, x1, y1);
return 0;
}
