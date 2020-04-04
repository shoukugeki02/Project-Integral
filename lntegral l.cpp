#include<iostream>
#include<cmath>
using namespace std;
double f(double x)        //fuction integral of integral i
{ 
    
	
	return x;
}
int main()
{
	int n,i;                                    //n for piece and i for loop
	double a,b,c,h,sum=0;
	float integral;
	cout <<"Enter the limit begin\n";           //get limit
	cin >> a;
	cout << "Enter the limit final\n";           
	cin >> b;
	cout << "Enter pow of x\n";                  // get n pow of  f(x^n)dx
	cin >> c;
	cout <<"Enter the number of square\n";      //get no. square
	cin >> n;
	float x[n],y[n];               
	h=(b-a)/n;                    // get the width of suare
	for (i=0;i<=n;i++)
	{
		  x[i]=a+i*h;                    //loop to evaluate x0,...xn and y0,...,yn
		 y[i]=f(x[i]);                         // save in array
	}
	for (i=1;i<n;i++)                //loop to evaluate h*(y1+...+yn-1)
	{
		sum=sum+h*y[i]+0.5;
	}
	 integral = h/2*(y[0]+y[n]+sum);    //formula integral f(x)dx = h/2*[y0+yn+2(y1+y2+y1..y(n-1)]
	cout << "integral is \n"<< integral;
	return 0;
}
