// Implementacao algoritmo Johnson and Trotter para gerar pemurtacoes de n em C++ 
#include <bits/stdc++.h>
using namespace std;


int Johnson_Trotter(int v[],int n){
    
	for(int i=0;i<n-1;i++){
			// movendo da direita para a esquerda 
			for(int i=n-1;i>0;i--){
				swap(v[i],v[i-1]);
				for(int i=0;i<n;i++){
					printf("%d",v[i]);
				}
				printf("\n");
			}    
			//troca os 2 ultimos elementos e a direcao
			swap(v[n-1],v[n-2]);
				for(int i=0;i<n;i++){
					printf("%d",v[i]);
					}
			printf("\n");
			
			// movendo da esquerda para direita
			for(int i=0;i<n-1;i++){
				swap(v[i],v[i+1]);
				for(int i=0;i<n;i++){
					printf("%d",v[i]);
				}
				printf("\n");
			}    
			//troca os 2 primeiros elementos e a direcao novamente
			swap(v[0],v[1]);
			for(int i=0;i<n;i++){
					printf("%d",v[i]);
					}
			printf("\n");
			
		}
}


int main(){
    //int v[] = {1, 2, 3, 4};
	//int n = sizeof(v) / sizeof(int);
    int n=4;
    int v[n];
    for (int i = 0; i < n; i++){
		v[i] = i + 1; //preencher o vetor
    }	
    Johnson_Trotter(v,n);
    
    
    return 0;



}
