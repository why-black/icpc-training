#include <bits/stdc++.h>

using namespace std;

void bfs(int u, vector<vector<int>>& roads, vector<bool>& visited){
    queue<int> q;
    q.push(u);
    visited[u] = true;

    while(!q.empty()){
        u = q.front();
        q.pop();

        for (int city : roads[u]){
            if (visited[city]) continue;
            q.push(city);
            visited[city] = true;
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    vector<vector<int>> roads (n+1);

    for (int i = 0; i<m; ++i){
        int u, v;
        cin >> u >> v;
        roads[u].push_back(v);
        roads[v].push_back(u);
    }

    vector<bool> visited(n+1, false);
    vector<int> capitals;
    int res = 0;
    for (int i=1; i<=n; ++i){
        if (!visited[i]){
            capitals.push_back(i);
            bfs(i, roads, visited);
            res++;
        }
    }

    cout << res - 1 << '\n';
    for (int i=1; i<capitals.size();i++){
        cout << capitals[0] << " " << capitals[i] << '\n';
    }

    return 0;
}