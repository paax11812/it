#include <iostream>
#include <math.h>
using namespace std;
double epsilon=0.0000000000001;
// Funkcja: 

double f(double x){
	return 2+pow((x-5),3);
}

// Algorytm iteracyjny:

void bisekcja(double a, double b){

double c,n,epsilon=0.0000000000000001;

do{
	n=c;
	c=(a+b)/2;
	if(f(a)*f(c)<0) {b=c;}
	else if(f(b)*f(c)<0) {a=c;}
	else if(f(a)*f(c)>0 || f(b)*f(c)>0)
		{
	 		cout<<"Brak miejsca zerowego! "; 
			exit(0);
		}
}while(fabs(c-n)>epsilon && fabs(f(c)-f(n))>epsilon);

cout<<"Miejsce zerowe: "<<c;
	
}

//Algorytm rekurencyjny:

double bisekcja2(double a, double b){
	double c=(a+b)/2;
	
	if(fabs(a-b)>=epsilon || fabs(f(c))>=epsilon){
		if((f(a)*f(c)<=0))
			{return bisekcja2(a,c);}
		else return bisekcja2(c,b);	
		
	}else 
	return c;	
	
}

//Algorytm kosza³a:
double bisekcja3(double a, double b){

double c;

do{
	c=(a+b)/2;
	if(f(a)*f(c)<0) {b=c;}
	else a=c;

}while(fabs(a-b)>=epsilon || fabs(f(c))>=epsilon);

return c;
	
}
int main (){
	
	double a,b;
	cout<<"Podaj a: ";
	cin>>a;
	cout<<endl<<"Podaj b: ";
	cin>>b;
	cout<<"\n\nPrzedzial <"<<a<<","<<b<<"> \n";
	bisekcja(a,b);
	cout<<endl<<"Rekurencyjnie: "<<bisekcja2(a,b);
	cout<<endl<<"Iteracyjne: "<<bisekcja3(a,b);
	
	
	
	
	
	
	return 0;
}
