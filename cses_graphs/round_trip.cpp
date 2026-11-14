#include <bits/stdc++.h>

using namespace std;

bool dfs(int u, int& start, int& end, vector<vector<int>>& adj, vector<bool>& visited, vector<int>& parent){
    for (int i=0; i<adj[u].size(); ++i){
        int v = adj[u][i];
        if (!visited[v]){
            parent[v] = u;
            visited[v] = true;
            if (dfs(v, start, end, adj, visited, parent)) return true;
        } else {
            if (parent[u] != v) {
                start = v;
                end = u;
                return true;
            }
        }
    }
    return false;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n+1);
    for (int i=0; i<m; i++){
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    vector<bool> visited(n+1, false);
    vector<int> parent(n+1);
    int res = 0;
    for (int i=1; i<=n; ++i){
        if (!visited[i]){
            visited[i] = true;
            int start, end;
            if (dfs(i, start, end, adj, visited, parent)) {
                vector<int> res;
                res.push_back(start);
                while (start!=end){
                    res.push_back(end);
                    end = parent[end];
                }
                res.push_back(start);
                cout << res.size() << '\n';
                for (int i = 0; i<res.size(); ++i){
                    cout << res[i] << ' ';
                }
                return 0;
            }
        }
    }
    cout << "IMPOSSIBLE\n";
    return 0;
}