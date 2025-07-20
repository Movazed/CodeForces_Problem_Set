#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5 + 5;

vector<int> adj[MAXN];
int n, edges;
int visited[MAXN], level[MAXN], parent[MAXN];

// Reset helper function to initialize arrays
void reset() {
    memset(visited, 0, sizeof(visited));
    memset(level, 0, sizeof(level));
    memset(parent, -1, sizeof(parent));
}

// Breadth-First Search function
void bfs(int source) {
    set<int> q;  // Using a set to maintain order (smallest node first)
    q.insert(source);
    visited[source] = 1;

    while (!q.empty()) {
        int u = *q.begin();
        cout << u << " ";
        q.erase(q.begin());

        for (int i = 0; i < adj[u].size(); i++) {
            int node = adj[u][i];

            if (!visited[node]) {
                visited[node] = 1;
                q.insert(node);
            }
        }
    }
}

int main() {
    reset();

    cin >> n >> edges;

    // Reading edges
    for (int i = 0; i < edges; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);  // Since the graph is undirected
    }

    // Perform BFS starting from node 1
    bfs(1);

    return 0;
}
