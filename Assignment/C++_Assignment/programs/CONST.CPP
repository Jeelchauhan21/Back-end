#include<iostream.h>
#include<conio.h>

void main()
{
     clrscr();

     //simple Variable
     int a=10;
     float b =5.5;
     char c = 'j';
     double d = 12.34555;

     //Constant variable
     const int const_value = 100;

     cout<<"\nInteger A = "<<a;
     cout<<"\nFloat b = "<<b;
     cout<<"\nCharacter C = "<<c;
     cout<<"\nDouble D = "<<d;
     cout<<"\nConstant Const_value = "<<const_value;


     int sum = a + const_value;
     float product = b * a;

     cout<<"\nSum Of A and Const_value ="<<sum;
     cout<<"\nProduct of B anf A ="<<product;

     getch();
}