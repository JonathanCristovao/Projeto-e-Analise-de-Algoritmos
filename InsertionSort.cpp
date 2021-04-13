//Implementacao algoritmo de ordenacao Insertion Sort e C++
#include <iostream>
#include <vector>
using namespace std;
void InsertionSort(vector<int> &vetor){

    for (int i=1; i<vetor.size();i++){
		int v_aux = vetor[i];
		int j=i-1;
		for(int i=0;i<vetor.size();i++){
            cout<<vetor[i]<<" ";  // imprimir o vetor
        } 
		cout<< " "<<endl;
        while ((j >= 0) && (vetor[j] > v_aux)){
			swap(vetor[j],vetor[j+1]);
            j--;
	    }
		vetor[j + 1] = v_aux;
	}

}
int main(){
    
    vector <int> v = {7,9,2,6,8,5,4,3,1}; // vetor de elementos
    InsertionSort(v);
    cout<< "Vetor ordenado"<<endl;
    for(int i=0;i<v.size();i++){
        printf("%d ", v[i]);
	}
    return 0;
}

      



