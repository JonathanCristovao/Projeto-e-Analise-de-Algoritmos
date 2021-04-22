#include<iostream>
using namespace std;
struct treenode{
    int info;
    treenode *esquerda;
    treenode *direita;
};
typedef treenode *treenodeptr;
void Inserir(treenodeptr &p, int x){
  
    if (p == NULL){
        p = new treenode;
        p->info = x;
        p->esquerda = NULL;
        p->direita = NULL;
    }
    else{
        if(x < p->info)// Insere na subarvore esquerda caso contrario insere na sbarvore a direita
            Inserir(p->esquerda, x);
        else
            Inserir(p->direita, x);
    }
}
int busca(treenodeptr arvore, int &x){
    if( arvore == NULL){
        return 0;
    }
   treenodeptr aux = arvore;
    while(aux != NULL){
        cout<< aux->info<<" ";
        if (x ==aux->info){
            return 1;
        }
       if ( x < aux->info){
            aux = aux->esquerda;
        }else{
            aux = aux->direita;
        }
        
    }
}
int main(){
    
    treenodeptr arvore = NULL;
    Inserir(arvore,8);
    Inserir(arvore,3);
	Inserir(arvore,10);
	Inserir(arvore,14);
	Inserir(arvore,13);
	Inserir(arvore,1);
	Inserir(arvore,6);
	Inserir(arvore,4);
	Inserir(arvore,7);
	
    //Arvore -->>          8
    //                   /   \
    //                 3      10 
    //               /  \      \
    //              1    6      14 
    //                  / \    /
    //                 4   7  13 
    int x = 7;// chave para a busca na arvore
    if(busca(arvore, x)==1){
        cout<<"Elemento encontrado"<<endl;
    }else{
       cout<<"Elemento inexistente na arvore"<<endl;
    }
   return 0;   
}