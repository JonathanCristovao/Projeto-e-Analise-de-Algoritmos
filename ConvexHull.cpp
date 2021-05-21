#include <bits/stdc++.h>
#include <iostream>
#include <stdlib.h>
using namespace std;
struct Point{
	int x, y;
};
// Casca convexa 
void Convexhull(Point points[], int n){

	vector<Point> hull;
	int a = 0, c;

	// Adicionar os pontos para a casca 'hull'
	do{
		hull.push_back(points[a]);
		c = (a + 1) % n;
		for (int i = 0; i < n; i++){
			
		    int val = (points[i].y - points[a].y) * (points[c].x - points[i].x) - 
			          (points[i].x - points[a].x) * (points[c].y - points[i].y);
			if (val < 0){
				c = i;
			}
		}
		a = c;
	}while (a != 0);

	cout << "Pontos que pertence a esta casca convexa:" << endl;
	cout<<'{'<<"";
	for (int i = 0; i < hull.size(); i++){
		cout << "(" << hull[i].x << "," << hull[i].y << "),";
	}
	cout<<'}'<<endl;
}

int main(){
	Point points[] = {{1, 2}, {3, 2}, {7, 4}, {8, 5}, {2, 7}, {9, 5},{6, 3},{3, 8},{6, 7},{1,4},{5, -3},{2, -2}};
        int n = sizeof(points) / sizeof(points[0]); 
	Convexhull(points, n);
	
	return 0;
}
