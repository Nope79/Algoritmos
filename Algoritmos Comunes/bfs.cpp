#include <bits/stdc++.h>

using namespace std;

vector <vector<int>> grafo;
vector <bool> visitados;

void bfs(int origen);

int main(){
	
	int n, m;
	cin >> n >> m;
	
	grafo.resize(n+1);
	visitados.assign(n+1, false);
	
	for(int i = 0; i < m; i++){
		
		int a, b;
		cin >> a >> b;
		grafo[a].push_back(b);
		grafo[b].push_back(a);
	}
	
	for(int i = 1; i < grafo.size(); i++){
		
		cout << i << ": ";
		for(int j = 0; j < grafo[i].size(); j++){
			
			cout << grafo[i][j] << " ";
		}
		
		cout << endl;
	}
	
	bfs(2);
	
	return 0;
}

void bfs(int origen){
	
	queue <int> q;
	q.push(origen);
	visitados[origen] = true;
	
	while(!q.empty()){
		
		int actual = q.front();
		q.pop();
		
		cout << actual << ": ";
		
		for(auto vecino : grafo[actual]){
			
			cout << vecino << " ";
			
			if(!visitados[vecino]){
				
				q.push(vecino);
				visitados[vecino] = true;
			}
		}
		cout << endl;
	}
}