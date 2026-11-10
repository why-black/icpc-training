#include <bits/stdc++.h>

using namespace std;

void bfs(vector<vector<int>>& connections, vector<bool>& visited, int n){
    queue<int> q;
    q.push(1);

    vector<int> parent (n+1);
    while (!q.empty()){
        int a = q.front();
        q.pop();
        visited[a] = true;
        for (int b : connections[a]){
            if (!visited[b]){
                visited[b] = true;
                parent[b] = a;
                q.push(b);
            }
        }
    }
    if (!visited[n]) {
        cout << "IMPOSSIBLE" << '\n';
        return;
    }

    vector<int> path;
    while (parent[n]!=0){
        path.push_back(n);
        if (n == 1) break;
        n = parent[n];
    }
    path.push_back(1);

    int res = path.size();
    cout << res << '\n';
    for (int i = path.size() - 1; i >= 0; --i) {
        cout << path[i] << ' ';
    }

}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    vector<vector<int>> connections (n+1);
    vector<bool> visited (n+1, false);

    for (int i=0; i<m; ++i){
        int a, b;
        cin >> a >> b;
        connections[a].push_back(b);
        connections[b].push_back(a);
    }
    
    bfs(connections, visited, n);

    return 0;
}