#include <iostream>
using namespace std;

void subconjuntos(int v[], bool aux[], int i, int n){
	if(i == n){
		cout<<"{"<<" ";
        for(int j = 0; j < n; j++){
			if(aux[j] == 1)
				cout << v[j] << " ";
		}
		cout <<"},"<<"";
	}
	else{
		aux[i] = 1;
		subconjuntos(v, aux, i + 1, n);
		aux[i] = 0;
		subconjuntos(v, aux, i + 1, n);
	}
}

int main(int argc, char *argv[]){
	int v[] = {1, 2, 3};
	int n = sizeof(v)/sizeof(int);
	bool v_bool[n];

	for(int i=0; i<n; i++) 
		v_bool[i] = 0;
   
    cout<<"Subconjuntos: "<<"";
	subconjuntos(v,v_bool,0,n);

	return 0;
}