#include <iostream>
#include <cstdlib>
#include <math.h>
using namespace std;
double epsilon=0.0000000000001;

double f(double x){
	return 2+pow((x-5),3);
} 

double falsi(double a, double b){

double c,n;	//c - miejsce zerowe; n - poprzedni wynik c

do{
	n=c;
	c=a-f(a)*((b-a)/(f(b)-f(a)));
	if (f(c)==0) return c;
	if(f(a)*f(c)<0) b=c;
	else a=c;

}while(fabs(c-n)>epsilon);

if(isnan(c)==true || f(a)*f(c)>0 && f(b)*f(c)>0){		// isnan() - sprawdza czy c jest puste(brak wartoœci)
	return 0;
}
return c;	
}



int main(){
	
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
