#include <iostream>

using namespace std; 


long int factorial(int x)
{
	if (x<0) cerr << "Nie mozna wyliczyc silnii z liczby ujemnej" << endl;
	if (x<2) return 1;
	
	return x*factorial(x-1);
}

float exp(int x, int p)
{
	if (p==0) return 1;
	
	if (p%2!=0){
		if (p>0) return x*exp(x,p-1);
		if (p<0) return (1.0/x)*exp(x,p+1);
	} else {
		float tmp = exp(x,p/2);
		return tmp*tmp;
	}
}

int main()
{
	int x,p;
	
	cout << "Podaj x: ";
	cin >> x;
	cout << "Podaj p: ";
	cin >> p;
	cout << endl << endl << "n!  = " << factorial(x) << endl;
	cout << "x^p = " << exp(x,p) << endl; 
	return 0;
}
