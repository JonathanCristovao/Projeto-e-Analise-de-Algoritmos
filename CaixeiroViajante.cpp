// implementacao do algoritmo caixeiro viajante c++
#include <bits/stdc++.h>
using namespace std;
#define V 4

int CaixeiroViajante(int grafo[][V], int s){
	// adicionar vertices 
	vector<int> vertice;
	for (int i = 0; i < V; i++)
		if (i != s)
			vertice.push_back(i); // adiciona i no final do vertece
    // verificar qual caminho tem o menor custo 
	int valor_min = INT_MAX;
	do{
		int soma = 0; 
		int k = s;
		for (int i = 0; i < vertice.size(); i++){
			soma += grafo[k][vertice[i]]; // soma os valores do possivel caminho
			k = vertice[i];
		}
	soma += grafo[k][s];
	valor_min = min(valor_min, soma);

	}while(next_permutation(vertice.begin(), vertice.end()));
    
	return valor_min;
}
int main(){
	// grafo com os custos de cada caminho
	int grafo[][V] = {{ 0, 5, 10, 25 },
					  { 5, 0, 30, 20 },
					  {10, 30, 0, 40 },
					  {25, 20, 40, 0 }};
	int s = 0;
	cout << "Custo do menor caminho: "<< CaixeiroViajante(grafo, s)<< endl;
	return 0;
}
