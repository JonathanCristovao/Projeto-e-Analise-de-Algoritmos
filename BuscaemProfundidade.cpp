// Implementacao do algoritmo busca em profundidade, criacao de um objeto grafo com os atributos publico
// adicionar aresta e busca em largura.
#include <iostream>
#include <list>
#include <algorithm> 
#include <stack> 
using namespace std;

class Grafo{ //classe grafo
	int V; // numero de vertices
	list<int> *adj; // ponteiro com as listas de adjacencias
public:
	Grafo(int V); //  construtor da classe grafo
	void adicionarAresta(int v1, int v2); // adiciona uma aresta no grafo
	void BuscaProfundidade(int v); // chama a busca de profundidade	
};
Grafo::Grafo(int V){
	this->V = V; // atribui o numero de vertices
	adj = new list<int>[V]; // cria as listas de adjacencias
}
void Grafo::adicionarAresta(int v1, int v2){
	adj[v1].push_back(v2); //adiciona v2 na lista de vertices adjacentes v1
}
void Grafo::BuscaProfundidade(int v){
	stack<int> pilha;
	bool visitados[V]; // vetor de visitados
 	// marca os vertices como nao visitados
	for(int i = 0; i < V; i++)
		visitados[i] = false;
 
	while(true){
		if(!visitados[v]){
			cout << "Visitou o vertice: "<< v <<endl;
			visitados[v] = true; // marca como visitado
			pilha.push(v); // insere na pilha o v
		}
 		bool vizinho_encontrado = false;
		list<int>::iterator it;
 		// procura se existe um vizinho que nao foi visitado
		for(it = adj[v].begin(); it != adj[v].end(); it++){
			if(!visitados[*it]){
				vizinho_encontrado = true;
				break;
			}
		}
 		if(vizinho_encontrado)
			v = *it; // atualiza o valor de v
		else{
			pilha.pop(); // remove da pilha os ja vizitados
		    if(pilha.empty()) // Se a pilha vazia fim da busca
				break;
			v = pilha.top(); // coloca o elemento do topo da pilha em v
		}
	}
}
int main(){
	int V = 10;
	Grafo G(V);
	// adicionando as arestas
    G.adicionarAresta(0, 1);
	G.adicionarAresta(0, 2);
	G.adicionarAresta(1, 3);
	G.adicionarAresta(1, 4);
	G.adicionarAresta(2, 5);
	G.adicionarAresta(2, 6);
	G.adicionarAresta(4, 7);
    G.adicionarAresta(4, 8);
    G.adicionarAresta(6, 9);
    G.adicionarAresta(9, 10);
	G.BuscaProfundidade(0);

	return 0;
}