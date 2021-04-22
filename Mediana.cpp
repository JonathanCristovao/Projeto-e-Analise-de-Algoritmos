//Implementacao algoritmo para calcular a mediana mediana sem ordenar o vetor em C++
#include <iostream>
#include <vector>
using namespace std;
void mediana(vector<int> &v){
    int aux1,aux2 = 1000;
     // Encontrar o menor elemento  
    for(int i=0; i<v.size();i++){
        if(v[i]<aux1){
            aux1=v[i];
            
        }
    }
    //cout<<aux1<<endl;
     int mediana =0;
    int n= ((v.size()/2));
    //Se o vetor conter um numero par de elementos a mediana e a media entre os dois valores centrais do vetor ordenado.
    if(v.size()%2==0){
        for(int j=0; j<n; j++){
            for(int i=0; i<v.size();i++){
                
                if((v[i]<aux2)&&(v[i]>aux1)){
                    aux2=v[i];
                }
            }
            //cout<<aux2<<endl;
            mediana =(aux2+aux1)/2;
            aux1=aux2;
            aux2=1000;
        }
    }else{
        for(int j=0; j<n; j++){
            for(int i=0; i<v.size();i++){
                
                if((v[i]<aux2)&&(v[i]>aux1)){
                    aux2=v[i];
                }
            }
            //cout<<aux2<<endl;
            mediana = aux2;
            aux1=aux2;
            aux2=1000;
        }

    }
    cout<<" A mediana e igual a "<<mediana<<endl;
}
int main(){
    vector <int> v1 = {7,5,9,3,1,2,8};
    //           v1 = {1,2,3,5,7,8,9}; Com o vetor ordenado de quantidade impar de elementos, temos que a mediana e igual a 5
    vector <int> v2 = {7,5,9,3,10,1,2,8};
    //           v2 = {1,2,3,5,7,8,9,10}; Com o vetor ordenado de quantidade par de elementos, temos que a mediana e igual a 6
    cout<<"Vetor de quantidade impar de elementos:"<<endl;
    mediana(v1);
    cout<<"vetor de quantidade par de elementos:"<<endl;
    mediana(v2);
    return 0;
}

      



