#include<bits/stdc++.h>
#include <fstream>
using namespace std;

class graph {
	int V;
	list<int> *adj;

public: 
	graph(int v) {
		V = v+1;
		adj = new list<int>[V+1];
	}

	void addEdge(int u, int v, bool bi = true) {
		adj[u].push_back(v);
		if (bi) {
			adj[v].push_back(u);
		}
	}

	void printGraph() {
		for (int i = 1; i <= V; i++) {
			cout << i <<"-->";
			for (int x : adj[i]) {
				cout << x << " ";
			}
			cout << "\n";
		}
	}

	void dfs(int src) {
		bool *vis = new bool[V]{ false };

		//Print dfs from all sources
		/*for (int i = 1; i < V; i++) {
			if (vis[i] == false) {
				dfsUtil(i, vis);
			}
		}*/
		dfsUtil(src, vis);
	}

	void dfsUtil(int src,bool vis[]) {
		vis[src] = true;
		cout << src << endl;

		for (int x : adj[src]) {
			if (vis[x] == false) {
				dfsUtil(x, vis);
			}
		}


	}
};

int main() {
	// ifstream cin;
	// cin.open("Text.txt");

	graph g(7);
	g.addEdge(1,2);
	g.addEdge(1,4);
	g.addEdge(1,6);
	g.addEdge(2,3);
	g.addEdge(4,5);
	g.addEdge(2,7);

	g.dfs(1);
	//g.printGraph();

	return 0;
}