#include <iostream>
using namespace std;





double fun(double x)

{
	return x*x;
}

int main()
{
	double a,b,h,sum=0,integral,x;
	int n;
	cout << "Enter lnital limit\nn: ";
	cin >> a;
	cout << "Enter lnital upper(final)limit\nn: ";
	cin >> b;
	cout << "Enter the number of sub\nn:";
	cin >>n;
	h=(b-a)/n;
	int i;
	for(i=1;i<n;i++)
	{
		x=a+i*h;
		sum=sum+fun(x);
	}
	integral = h/2.0*(fun(a)+2*sum+fun(b));
	cout << "integral is:" << integral ;
   

    
}
