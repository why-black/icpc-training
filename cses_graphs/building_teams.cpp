#include <bits/stdc++.h>

using namespace std;

bool dfs(int v, vector<int>& teams, vector<vector<int>>& adj){
    for (int u : adj[v]){
        if (teams[u]){
            if (teams[u]==teams[v]){
                return false;
            }
        } else {
            teams[u] = 3 - teams[v];
            if (!dfs(u, teams, adj)) return false;
        }
    }
    return true;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n+1);
    for (int i=0; i<m; ++i){
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    vector<int> teams(n+1, 0);
    for (int i = 1; i <= n; ++i){
        if (!teams[i]) {
            teams[i] = 1;
            if (!dfs(i, teams, adj)){
                cout << "IMPOSSIBLE\n";
                return 0;
            }
        }
    }
    for (int i = 1; i <= n; ++i){
        cout << teams[i] << " ";
    }
    cout << '\n';

    return 0;
}