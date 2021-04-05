#include <iostream>
#include <vector>
using namespace std;

int main(){
    
    vector <int> v = {20, 75, 31, 25, 2, 30, 18, 5, 4, 8}; // vetor de elementos
    int chave= 4;// elemento a ser procurado no vetor
    int posicao = -1;
    int i = 0;
    while (v[i]!=chave){
       i++;
       if(v[i] == chave){ 
           posicao = i;
           } 
    }
    if (posicao == -1){
        cout << "Elemento inexistente no arranjo" << endl;
    } else {
        cout << "Posicao do elemento no vetor: " << posicao << endl;
    }
    
    return 0;
}

      



