#include <iostream>
#include <cstdlib>
using namespace std;

int main() {

    constexpr int ROZMIAR = 12;
    int wyl_liczby[ROZMIAR];
    for(int i = 0; i < ROZMIAR; i++){
        int random = rand() % 25 + 1;
        wyl_liczby[i] = random;
        cout<<wyl_liczby[i]<<" ";
    }



void sortowanie_babelkowe(int tab[],int n)
{	
	for(int i=0;i<n;i++)
		for(int j=1;j<n-i;j++) 
		if(tab[j-1]>tab[j])
			swap(tab[j-1], tab[j]);
}

void scal(int tab[], int lewy, int srodek, int prawy) 
{
  int i, j;
 
 
  for(i = srodek + 1; i>lewy; i--) 
    pom[i-1] = tab[i-1]; 
 
  
  for(j = srodek; j<prawy; j++) 
    pom[prawy+srodek-j] = tab[j+1]; 
 
  
  for(int k=lewy;k<=prawy;k++) 
    if(pom[j]<pom[i])
      tab[k] = pom[j--];
    else
      tab[k] = pom[i++];
}    
    
}
