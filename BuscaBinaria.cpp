// Impletementacao algoritmo de busca binaria em C++ 
#include <bits/stdc++.h>
using namespace std;

int BuscaBinaria(int arr[], int l, int r, int x){
	
	while(r>=l){
	
		int m = l+(r-l)/2;

		if (arr[m] == x)
			return m;

		else if (arr[m] > x)
			return BuscaBinaria(arr, l, m - 1, x);
	    else 
		    return BuscaBinaria(arr, m + 1, r, x);
	}
	return -1; // retornar -1 se o elemento nao for encontrado
}

int main(){
	int arr[] = {1,2,3,4,5,6,7,8,9,10};
	int x = 8;
	int n = sizeof(arr)/sizeof(arr[0]);
	int pos = BuscaBinaria(arr, 0, n - 1, x);
	(pos == -1) ? cout << "Elemento nao esta no array"
				: cout << "Elemento encontrado na posicao " << pos;
	return 0;
}
