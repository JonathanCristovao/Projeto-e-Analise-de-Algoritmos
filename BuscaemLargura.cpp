
// Implementacao do algoritmo busca em largura, criacao de um objeto grafo com os atributos publico.
#include <iostream>
#include <list>
#include <queue> 
using namespace std;

class Grafo{//classe grafo
	int V; // numero de vertices
	list<int> *adj; // ponteiro com as listas de adjacencias
public:
	Grafo(int V); // construtor da classe grafo
	void adicionarAresta(int v1, int v2); // adiciona uma aresta no grafo
	void BuscaLargura(int v); // chama a busca de largura
};
Grafo::Grafo(int V){
	this->V = V; // atribui o numero de vertices
	adj = new list<int>[V]; // cria as listas de adjacencias
}
void Grafo::adicionarAresta(int v1, int v2){
	adj[v1].push_back(v2); //adiciona v2 na lista de vertices adjacentes v1
}
void Grafo::BuscaLargura(int v){
	queue<int> fila;
	bool visitados[V]; // vetor de vertices visitados

	for(int i = 0; i < V; i++)
		visitados[i] = false;

	cout << "Visitou o vertice: " << v << " ";
    cout<<" "<<endl;
	visitados[v] = true; // marca como visitado

	while(true){
		list<int>::iterator it;
        
		for(it = adj[v].begin(); it != adj[v].end(); it++){ // consulta os vizinhos 
			if(!visitados[*it]){ // marca o vertice como visitado e insere na fila
				cout << "Visitou o vertice: " << *it << " \n";
				visitados[*it] = true; 
				fila.push(*it); 
			}
		}
		if(!fila.empty()){ // se lista vazia pega o primeiro elemento e remove a fila
			v = fila.front(); 
			fila.pop(); 
		}else
			break;
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
	G.BuscaLargura(0);

	return 0;
}
