#include<bits/stdc++.h>
#include <fstream>
using namespace std;

class graph {
	int V;
	list<int> *adj;

public:
	graph(int v) {
		V = v+1;
		adj = new list<int>[V];
	}

	void addEdge(int u, int v, bool bi = true) {
		adj[u].push_back(v);
		if (bi) {
			adj[v].push_back(u);
		}
	}

	void printGraph() {
		for (int i = 1; i < V; i++) {
			cout << i << "-->";
			for (int x : adj[i]) {
				cout << x << " ";
			}
			cout << "\n";
		}
	}

	void airBfs(int src, int dest) {
		list<int> res;

		//for lexological ordering given in question
		for (int i = 1; i < V; i++) {
			adj[i].sort();
		}

		queue<int> q;
		bool *vis = new bool[V] {0};
		int *distance = new int[V] {0};
		int *parent = new int[V] {-1};
		parent[src] = -1;

		q.push(src);
		vis[src] = true;
		bool done = false;

		//cout << "Parent src" << parent[src] << endl;

		//bfs 
		while (!q.empty() && !done) {
			int node = q.front();
			q.pop();

			for (int x : adj[node]) {
				if (!vis[x]) {
					q.push(x);
					vis[x] = true;
					distance[x] = distance[node] + 1;
					parent[x] = node;
				}
				if (x == dest) {
					done = true;
					break;
				}
			}
		}

		//print path from src to dest
		//int temp = dest;
		//while (temp != -1) {
		//	res.push_front(temp);
		//	//cout << temp << "-->" << parent[temp] << endl;;
		//	temp = parent[temp];
		//}

		cout << distance[dest] << "\n";

	}

};

int main() {
	// ifstream cin;
	// cin.open("Text.txt");

	int N;
	cin >> N;
	while (N--) {
		int n, m, u, v;
		cin >> n >> m;
		graph g(n);
		while (m--) {
			cin >> u >> v;
			g.addEdge(u, v);
		}

		g.airBfs(1, n);
	}

	return 0;
}