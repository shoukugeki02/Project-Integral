#include <iostream>
using namespace std;
double fun(double x)
{
	return (x*x)/2 + 3*x-1/x;
}

double Integral(double lowBound, int n, double dx)
{
	double sum =0;
	for(int i = 0; i < n; i++)
	{
		double xi = lowBound+i*dx;
		double funValue = fun(xi);
		double rectangleArea = funValue*dx;
		sum += rectangleArea;
	}
	return sum;
}

double DoubleIntegral(double lowBound1, double lowBound2, int n, double dy)
{
	double Bigsum =0;
	for(int i = 0; i < n; i++)
	{
		double yi = lowBound1+i*dy;
		double dx = (double) (yi-lowBound2)/n;
		double Smallsum = 0;
		
		for(int j = 0; j < 0 ; j++)
		{
			double xi = lowBound2+dx*j;
			double funValue = fun(xi);
			double rectangleArea = funValue*dx;
			Smallsum += rectangleArea;
		}
 		double secondRectangleArea = Smallsum*dy;
		Bigsum += secondRectangleArea;
	}
	return Bigsum;
}

int main()
{
	double lowBound1, upBound1, lowBound2;
	int n = 10000;
	cout << "lowBound1 = "; 
	cin >> lowBound1;
	cout << "upBound1 = ";
	cin >> upBound1;
	cout << "lowBound2 = ";
	cin >> lowBound2;
	double dy =  (double) (upBound1-lowBound1)/n;
	double result = DoubleIntegral(lowBound1, lowBound2, n, dy);
	cout << result;
	return 0;
}
