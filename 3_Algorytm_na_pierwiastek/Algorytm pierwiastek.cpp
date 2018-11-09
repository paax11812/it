#include <iostream>
#include <math.h>
using namespace std;

/*	-algorytmy numeryczne s¹ z definicji niedok³adne
	-po wielu powtórzeniach s¹ ok
*/

// Algorytm Newtona-Raphsona na liczenie pierwiastka

float alg_pierw(float a){
	
	float b(1), P(a), epsilon(0.0001);
	
	while(fabs(a-b)>epsilon){	//fabs(a-b) -> wartoœæ bezwzglêdna
		a=(a+b)/2;
		b=P/a;
	}
	
	return b;
	
}

int main (){
	
	float x;
	
	cout<<"Podaj liczbe: ";
	cin>>x;
	cout<<alg_pierw(x);
	
	return 0;
}
