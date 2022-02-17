#include <bits/stdc++.h>

using namespace std;

int n, m;

int bfs(const vector<vector<int> > &rgraph, int s, int t, vector<int> &parent) {
    vector<int> visited(n, 0);
    
    queue<int> q;
    q.push(s);
    visited[s] = 1;
    parent[s] = -1;
    
    while (!q.empty()) {
        int i = q.front();
        q.pop();
        
        for (int j=0; j<=m+1; j++) {
            if (!visited[j] && rgraph[i][j] > 0) {
                q.push(j);
                visited[j] = 1;
                parent[j] = i;
            }
        }
    }
    
    return visited[t];
}

int ffa(const vector<vector<int> > &graph, int s, int t) {
    vector<vector<int> > rgraph(n, vector<int>(n, 0));
    
    int u, v;
    for (u=0; u<n; u++) {
        for (v=0; v<n; v++) {
            rgraph[u][v] = graph[u][v];
        }
    }
    
    vector<int> parent(n, 0);
    
    int ans = 0;
    while (bfs(rgraph, s, t, parent)) {
        int flow = INT_MAX;
        for (u=t; u!=s; u=parent[u]) {
            v = parent[u];
            flow = min(flow, rgraph[v][u]);
        }
        
        for (u=t; u!=s; u=parent[u]) {
            v = parent[u];
            rgraph[u][v] += flow;
            rgraph[v][u] -= flow;
        }
        
        ans += flow;
    }
    
    return ans;
}

int main() {
    cin >> n >> m;
    
    vector<vector<int> > graph(n, vector<int>(n, 0));
    
    int x, y, z;
    for (int i=0; i<m; i++) {
        cin >> x >> y >> z;
        graph[x][y] = z;
    }
    
    cout << ffa(graph, 0, n-1) << "\n";
    
	return 0;
}