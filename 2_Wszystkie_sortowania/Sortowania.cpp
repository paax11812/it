#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;


void wypelnij(int tab[],int a, int b){
	for(int i=0;i<a;i++){
		tab[i]=rand()%b+1;
	}
}

void pokaz(int tab[], int a){
	for(int i=0;i<a;i++){
		if(i==a-1){
			cout<<tab[i]<<".";
			break;
		}
	cout<<tab[i]<<", ";
	}
}

void Babelkowe(int tab[], int a){
	// Porównujemy ka¿dy element tablicy ze sob¹ czy jest wiêkszy
	for(int j=0;j<a;j++){
		for(int i=0;i<a;i++){
			if(tab[i]>tab[i+1]){
				int tmp=tab[i];
				tab[i]=tab[i+1];
				tab[i+1]=tmp;
			}
		}
	}
	
}

void Wybieranie(int tab[], int a){
	
	for(int i=0;i<a;i++){
		
		int min=i;
				
		for(int j=i+1;j<a;j++){		//znalezienie indeksu! min wartoœci tablicy (szukamy za ka¿dym razem jeszcze raz)
			if(tab[j]<tab[min]){
				min = j;
			}
	 }
								   //Przesuwamy min na lewo czyli sprawdzamy czy mniejszy od poprzednika
		if(tab[i]>=tab[min])
		{	int temp=tab[i];
			tab[i]=tab[min];
			tab[min]=temp;
		}
	}
	
}

void Wstawianie(int tab[], int a){	
    
	int j;
	
	for(int i=0;i<a;i++ )
    {
        int temp=tab[i];
        
        for(j=i-1; j>=0 && tab[j]>temp; j--) 
		{
			 tab[j+1]=tab[j];
		}
    	
    	
        tab[j+1]=temp;
    }
	
}

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
	if(i<p)Quicksort(i,p,tab);
}

void Kubelkowe(int tab[], int a){
	
	//znajdŸ min i max
	int min=tab[0],max=tab[0];
	for(int i=0;i<a;i++)	if(tab[i]<min)	min=tab[i];
	for(int i=0;i<a;i++)	if(tab[i]>max)	max=tab[i];
	
	//utwórz kube³ki i je wyzeruj
	int kubel[max-min+1];
		for(int i=min;i<=max;i++){
			kubel[i-min]=0;
		}

	// zliczamy w odpowiednich licznikach wyst¹pienia
	// wartoœci elementów sortowanego zbioru	
	for(int i=0;i<a;i++){
		kubel[tab[i]-min]++;
	}
	
	// zapisujemy do zbioru wynikowego numery niezerowych liczników
	// tyle razy, ile wynosi ich zawartoœæ
	 int j=0;
	 for(int i=min;i<=max;i++) 
	 	while(kubel[i-min]--) 
		 tab[j++]=i;
}

void Merge(int tab[], int l, int p, int a){
	int i,i1,i2,sr;
	int temp[a];
	
	for(int i=0; i<a; i++){
		temp[i]=tab[i];
	}
	
	sr=(p+l)/2;
	i=l;
	i1=l;
	i2=sr+1;
	
	while(i1<=sr && i2<=p){
		if(temp[i1]<temp[i2]){
			tab[i]=temp[i1];
			i1++;
		}else{
			tab[i]=temp[i2];
			i2++;
		}
		i++;
	}
		if(i1>sr)
			while(i2<=p){
				tab[i]=temp[i2];
				i2++;	i++;
			}else{
				while(i1<=sr){
					tab[i]=temp[i1];
					i1++; i++;
				}
			}
	
}

void MergeSort(int tab[], int l, int p, int a){
	int srodek=(l+p)/2;
	if(l<srodek) MergeSort(tab,l,srodek,a);
	if(srodek+1<p) MergeSort(tab,srodek+1,p,a);
	Merge(tab,l,p,a);
}

int main(){
	
	srand(time(NULL));
	setlocale(LC_ALL,"");
	int a,b;
	cout<<"Podaj ile miejsca ma zajmowaæ tablica: "; cin>>a;
	cout<<endl<<"Podaj jaki ma byæ przedzia³ losowanych liczb: "; cin>>b;
	int tab[a];
	wypelnij(tab,a,b);
	cout<<"\nPrzed sortowaniem: "; pokaz(tab,a);
	Wstawianie(tab,a);
	cout<<"\n\nPo sortowaniu:	   "; pokaz(tab,a);
	
	
	
	
	return 0;
}
