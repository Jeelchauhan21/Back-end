#include<iostream.h>
#include<conio.h>

float rectangle(float length,float width)
{
	return length*width;
}

void main()
{
	float length,width,area;
	clrscr();

	cout<<"\n Enter lenght of rectangle:";
	cin>>length;
	cout<<"\n Enter width of rectangle:";
	cin>>width;

	area=rectangle(length,width);

	cout<<"\n Area Of Rectangle is : "<<area;

	getch();
}