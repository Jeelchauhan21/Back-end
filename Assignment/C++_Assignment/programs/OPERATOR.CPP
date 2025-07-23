#include<iostream.h>
#include<conio.h>

void main()
{
      clrscr();

      int a=10,b=5;
      float result;

      //Arithmetic Operators
      cout<<"\n -:Arithmetic Operators::-\n";
      cout<<"\n A + b = "<<a+b;
      cout<<"\n A - B = "<<a-b;
      cout<<"\n A * B = "<<a*b;
      cout<<"\n A / B = "<<a/b;
      cout<<"\n A % B = "<<a%b;

      //Relational Operators
      cout<<"\n\n -:Relational Operators:-\n";
      cout<<"\n A > B = "<<(a>b);
      cout<<"\n A < B = "<<(a<b);
      cout<<"\n A == b = "<<(a==b);
      cout<<"\n A != b = "<<(a!=b);

      //Logical Operators
      cout<<"\n\n -:Logical Operators:-\n\n";
      result = (a>0) && (b>0);
      cout<<"(a>0) && (b>0) = "<<result;

      result =(a<0) || (b>0);
      cout<<"(a<0) || (b>0) = "<<result;

      result =!(a==b);
      cout<<"!(a==b) ="<<result;


      //Assignment Operators
      cout<<"\n\n -:Assignments operators:-\n";
      int c = a;
      cout <<"\n c += b -> c = "<<c;

      c += b;
      cout<<"\n c +a b -> c = "<<c;

      c *= 2;
      cout<<"\n C *= 2 -> C = "<<c;

      getch();
}