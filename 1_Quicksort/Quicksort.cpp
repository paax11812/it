/*
Tablica:
{4 2 9 1 6 3 5 2 7 9}


tablica n=10
p=0; k=9; numery wielkosc tablicy

pivot = tab[(p+q)/2];

i=p;
j=k;

*/
#include <iostream>
#include <cstdlib>
#include <time.h>
using namespace std;

void Quicksort(int l, int p, int tab[]){
	int i=l , j=p;
	int pivot=tab[(p+l)/2];
	do{
		while(tab[i]<pivot) i++;
		while(tab[j]>pivot) j--;
		if(i<=j){
			int tmp=tab[i];
			tab[i]=tab[j];
			tab[j]=tmp;
			i++;	j--;
		}
}while(i<=j);

	if(l<j)Quicksort(l,j,tab);
	if(l<p)Quicksort(i,p,tab);
}
	





int main (){

srand(time(NULL));
int n;

cout<<"Podaj n "; cin>>n;

int tab[n];

for (int i=0; i<n;i++)
	{
		tab[i]=rand()%100+1;
	}

int l=0;
int p=n-1;

Quicksort(l,p,tab);	

for (int i=0;i<n;i++){
	cout<<tab[i]<<" ";
}
	
	return 0;
}
