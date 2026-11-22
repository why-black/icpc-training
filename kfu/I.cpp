#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void dfs(int u, int parent, int depth, vector<vector<int>>& adj, vector<int>& vals, vector<pair<int, int>>& leaves){
    bool is_leaf = true;
    for (int v : adj[u]){
        if (v!=parent){
            is_leaf = false;
            dfs(v, u, depth+1, adj, vals, leaves);
        }
    }
    if (is_leaf){
        leaves.push_back({vals[u], depth});
    }
}

void solve(){
    int n, m;
    cin >> n;

    vector<vector<int>> adj(n+1);
    vector<int> vals(n+1, -1);
    vector<bool> visited(n+1, false);
    vector<pair<int, int>> leaves;

    for (int i = 1; i<n; ++i){
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    cin >> m;
    for (int i=0; i<m; ++i){
        int u, v;
        cin >> u >> v;
        vals[u] = v;
    }

    dfs(1, 0, 0, adj, vals, leaves);


    int sum = 0;
    double res = 0;
    int depth = 0;
    for (auto[a, d]:leaves){
        sum += a;
        depth = d;
    }
    res = pow(1.0 / (sum), 1.0/depth);
    cout << res << '\n';
}

int main(){
    cin.tie(0)->sync_with_stdio(false);
    
    solve();

    return 0;
}