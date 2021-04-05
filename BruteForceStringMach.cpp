#include<cstring>
#include<iostream>
#include<cstdio>
using namespace std;

int main(){
string T = "um arranjo e uma estrutura de dados que armazena uma colecao de elementos ";
string P = "dados"; // string a ser procurada em T
cout<<"tamanho de P: "<<P.length()<<endl;
int posicao = 0;
int n = T.length(), m = P.length();
for(int i=0;i<n-m+1;i++){
    cout<<"interacao: "<<i<<endl;
    int j = 0;
        while(T[i+j]==P[j] && j<m){
            j=j+1;
        //cout<<"valor de j: "<<j<<endl;
        }
       if(j==m){
           cout<< "A palavra esta na posicao: "<<i<<endl;
           break;
           }

    }
return 0;
}