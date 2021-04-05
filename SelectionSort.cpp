// Implementacao do algoritmo de ordenacao SelectionSort em C++
#include <iostream>
#include <float.h>
#include <stdlib.h>
#include <math.h>
using namespace std;

int main(){
    int arr[] = {19, 55, 2,85,77, 29,6,30,80, 755,3,10}; // Array exemplo para a ordenacao dos dados
    int n = sizeof(arr)/sizeof(arr[0]);
    int min;
    cout << "Array original :" <<" " ;
    for (int i = 0; i < n; i++){
          cout << arr[i] << " ";
    }
    cout<<" "<<endl; 
    
    for (int i=0; i<n; i++){
        min = i;
        for (int j=i+1; j<n; j++){
            if (arr[j] < arr[min])
                min = j;
        }
        if (min != i){
            swap(arr[i],arr[min]); // Funcao swap para realizar a troca os elementos de lugares
        }
    }
    cout<< "Array ordenado :" <<" ";
    for (int i = 0; i < n; i++){
          cout << arr[i] << " ";
    }
    return (0);
}