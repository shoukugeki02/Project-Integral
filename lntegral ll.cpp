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
// second code//
#include <iostream>
#include <cmath>
using namespace std; 
  
// *** In truth, it takes an intricate formula to find the area, but have to wait to see the coach from the friends, so give examples of problems from the lesson. ***//
float givenFunction(float x, float y) 
{ 
    return pow(pow(x, 4) + pow(y, 5), 0.5); 
} 
  

float doubleIntegral(float h, float k, 
                     float lx, float ux, 
                     float ly, float uy) 
{ 
    int nx, ny; 
    
   
    float z[50][50], ax[50], answer; 
  
   
    nx = (ux - lx) / h + 1; 
    ny = (uy - ly) / k + 1; 
  
    
    for (int i = 0; i < nx; ++i) { 
        for (int j = 0; j < ny; ++j) { 
            z[i][j] = givenFunction(lx + i * h, 
                                    ly + j * k); 
        } 
    } 
  
   
    for (int i = 0; i < nx; ++i) { 
        ax[i] = 0; 
        for (int j = 0; j < ny; ++j) { 
            if (j == 0 || j == ny - 1) 
                ax[i] += z[i][j]; 
            else if (j % 2 == 0) 
                ax[i] += 2 * z[i][j]; 
            else
                ax[i] += 4 * z[i][j]; 
        } 
        ax[i] *= (k / 3); 
    } 
  
    answer = 0; 
  
    
    for (int i = 0; i < nx; ++i) { 
        if (i == 0 || i == nx - 1) 
            answer += ax[i]; 
        else if (i % 2 == 0) 
            answer += 2 * ax[i]; 
        else
            answer += 4 * ax[i]; 
    } 
    answer *= (h / 3); 
  
    return answer; 
} 
  
// Driver Code 
int main() 
{ 
    // lx and ux are upper and lower limit of x integral 
    // ly and uy are upper and lower limit of y integral 
    // h is the step size for integration wrt x 
    // k is the step size for integration wrt y 
    float h, k, lx, ux, ly, uy; 
    cout  << "input h \n";
    cin >> h;
    cout << "input k \n ";
    cin >> k;
    cout << "input lx \n ";
    cin >> lx;
    cout << "input ux \n";
    cin >> ux;
    cout << "input ly \n ";
    cin >> ly;
    cout << "input uy \n";
    cin >> uy;
    printf("%f", doubleIntegral(h, k, lx, ux, ly, uy)); 
    return 0; 
} 
