// REGU£A SIECZNYCH
#include <iostream>
#include <cstdlib>
#include <math.h>
using namespace std;
double epsilon=0.0000000000001;

double f(double x){
	return log(x)+x;
} 
double f1(double x){
	return sin(x)-1/x;
}

double falsi(double a, double b){

double x,i(64);
do{
	x=a-f(a)*(b-a)/(f(b)-f(a));
	b=a;
	a=x;
	if(!(--i))
	{
		cout<<"Przekroczony limit obiegów!";
		return 0;
	}
}while(fabs(f(x))>=epsilon);

return x;

}

int main (){
	
	double a,b;
	cout<<"Podaj a: ";
	cin>>a;
	cout<<endl<<"Podaj b: ";
	cin>>b;
	cout<<"\n\nPrzedzial <"<<a<<","<<b<<"> \n";
	if(falsi(a,b)==0) cout<<"Brak miejsca zerowego!";
	else cout<<falsi(a,b);	
	
	
	
	
	
	
	
	return 0;
}
