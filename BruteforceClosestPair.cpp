// Algoritmo forca bruta para encrontar a distancia entre dois pontos
#include <iostream>
#include <float.h>
#include <stdlib.h>
#include <math.h>
using namespace std;
  
// Estrutura para um ponto bidimencional 
struct Point{
    int x, y;
};
// Funcao para encontrar a ditstancia entre dois pontos
float dist(Point p1, Point p2){    
    return sqrt( (p1.x - p2.x)*(p1.x - p2.x) +(p1.y - p2.y)*(p1.y - p2.y));
}
 
int main(){
    Point P[] = {{1, 2}, {9, 20}, {16, 32}, {7, 21}, {8, 44}, {7, 56},{4, 4}};
    int n = sizeof(P) / sizeof(P[0]);
    float min = FLT_MAX; 
    int i,j;
    int a,b;
    // metodo forca bruta 
    for (i = 0; i < n; i++){
        for (j = i+1; j < n; j++){
          //se a distância entre os dois ponstos for menor que min, armazenar a distância
            if (dist(P[i], P[j]) < min){
               a=i;
               b=j;
               min = dist(P[i], P[j]);
            }
        }       
    }
    cout<<"A menor distancia e: "<<min<<endl;
    cout<<"Entre os pontos: {"<<P[a].x<<","<<P[a].y<<"} e {"<<P[b].x<<","<<P[b].y<<"}"<<endl;          
    return 0;
}