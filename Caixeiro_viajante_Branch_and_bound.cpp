#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> readMatrix(string tsp_file, int nhead, int nnodes) {
vector<vector<int>> matrix(nnodes, vector<int>(nnodes, 0));
string line;
int nline, ncol;
int val;
int linecount = 0;
ifstream inputFile(tsp_file);
while (inputFile) {
    getline(inputFile, line);
    linecount += 1;
    if (linecount > nhead and linecount <= nhead + nnodes) {
        nline = linecount - nhead - 1;
        ncol = nline + 1;
        stringstream stream(line);
        while (stream >> val) {
            matrix[ncol][nline] = val;
            matrix[nline][ncol] = val;
            ncol++;
        }
    }
}
return matrix;
}
void printv(vector<int> v) {
    for (auto e : v) {
        cout << e << " ";
    }
    cout<<endl;
}
int h(vector<int> sol) {
    return 0;
}
int custo(vector<int> sol,vector<vector<int>> cost_matrix) {
    int cost = 0;
    for (size_t i = 0; i < sol.size() - 1; i++) {
        cost += cost_matrix[sol[i]][sol[i + 1]];
    }
   // custo do caminho da ultima para a primeira cidade
    cost += cost_matrix[sol[sol.size() - 1]][sol[0]]; 

    return cost;
}
void search(vector<int>& sol,vector<int>& best_sol, int n, int& bound,vector<vector<int>>& cost_matrix,vector<int> domain) {

    if (custo(sol, cost_matrix) + h(sol) < bound) {
        if (sol.size() == n) { //solução completa
            best_sol = sol;
            bound = custo(sol, cost_matrix);
        }else{
            for (auto e : domain) {
                if (find(sol.begin(), sol.end(), e) == sol.end()) {//verifica se o elemento está na solução
                    vector<int> new_sol(sol);
                    new_sol.push_back(e);

                    search(new_sol, best_sol, n, bound, cost_matrix, domain);
                }
            }
        }
    }
}
vector<int> branchAndBound(vector<int>& domain, int n, int bound, vector<vector<int>> &cost_matrix) {
    vector<int> best_path({});
    vector<int> sol({ 0 });
    search(sol, best_path, n, bound, cost_matrix, domain);
    return best_path;
}
int main(){
    string tsp_file = "cidades.tsp";
    int nhead = 0;
    int nnodes = 8;
    vector<vector<int>> cost_matrix = readMatrix(tsp_file, nhead, nnodes);
    for(int i=0; i<cost_matrix.size();i++){
      for(int j=0; j<cost_matrix[0].size();j++){
          cout<<cost_matrix[i][j]<<"   ";
        }
       cout<<endl;
    }
    //vector<int> domain({ 0,1,2,3,4,5,6,7});
    vector<int> domain;
    for (int i = 0; i < nnodes; i++) { domain.push_back(i); }
    int n = domain.size();
    int bound = 2000;
    vector<int> best_path = branchAndBound(domain, n, bound,cost_matrix);
    printv(best_path);
    cout <<"Custo otimo: " <<custo(best_path, cost_matrix); //0 1 2 6 3 7 4 5 Custo otimo para as 8 cidades: 1483
    return 0;
}