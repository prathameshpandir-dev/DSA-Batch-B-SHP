#include <iostream>
#include <queue>
using namespace std;

int adj[100][100], n;
bool visited[100];

void dfs(int v) {
    visited[v] = true;
    cout << v << " ";

    for (int i = 0; i < n; i++) {
        if (adj[v][i] == 1 && !visited[i])
            dfs(i);
    }
}

void bfs(int start) {
    bool vis[100] = {false};
    queue<int> q;

    q.push(start);
    vis[start] = true;

    while (!q.empty()) {
        int v = q.front();
        q.pop();
        cout << v << " ";

        for (int i = 0; i < n; i++) {
            if (adj[v][i] == 1 && !vis[i]) {
                q.push(i);
                vis[i] = true;
            }
        }
    }
}

int main() {
    int e, u, v, start;

    cout << "Enter number of vertices: ";
    cin >> n;

    cout << "Enter number of edges: ";
    cin >> e;

    for (int i = 0; i < e; i++) {
        cout << "Enter edge (u v): ";
        cin >> u >> v;
        adj[u][v] = 1;
        adj[v][u] = 1;
    }

    cout << "Enter starting vertex: ";
    cin >> start;

    cout << "DFS: ";
    dfs(start);

    for (int i = 0; i < n; i++)
        visited[i] = false;

    cout << "\nBFS: ";
    bfs(start);

    return 0;
}
