// Algoritmo de ordenacao Bubble Sort em C++
#include <iostream>
using namespace std;

int main(){    
    int arr[] = {19, 55, 2,85,77, 29,6,30,80, 755,3,10}; // Array exemplo para a ordenacao dos dados
    int n = sizeof(arr)/sizeof(arr[0]);
    // Loop para realizar as operacoes ate que todos os elementos do array seja ordenados
    cout << "Array original :" <<" " ;
    for (int i = 0; i < n; i++){
          cout << arr[i] << " ";
    }
    cout<<" "<<endl; 
    
    for (int i=0;i<(n-1);i++){
        
        // Loop para a comparacao de dois elementos
        for (int j=0;j<(n-1);j++){   
            if (arr[j+1]<arr[j]){
                swap(arr[j],arr[j+1]); // Funcao swap para realizar a troca os elementos de lugares
            } 
        }
    }
    cout << "Array ordenado :" <<" " ;
    //Loop para imprimir os elementos do array ordenado
       
    for (int i=0;i<(n);i++){         
        cout<<arr[i]<<" "; 
    }
    return 0;
}
