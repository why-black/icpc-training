#include <bits/stdc++.h>

using namespace std;

struct DSU{
    vector<int> p;
    
    DSU(int n){
        p.resize(n+1);
        for (int i = 0; i <= n; ++i){
            p[i] = i;
        }
    }
    int find(int v){
        return p[v] == v ? v : p[v] = find(p[v]);
    }
    bool unit(int a, int b){
        a = find(a);
        b = find(b);
        if (a==b) return false;
        p[a] = b;
        return true;
    }
    
};


void find_ostov(){
    int n, m;
    cin >> n >> m;
    
    
    
    vector<tuple<int, int, int>> edges(m);
    
    for (int i=0; i<m; i++){
        int u, v, w;
        cin >> u >> v >> w;
        edges[i] = {u, v, w};
    }
    
    int res = (1<<30)-1;
    for (int bit=29; bit>=0; bit--){
        
        int test_mask = res & ~(1 << bit);
        DSU dsu = DSU(n);
        int edges_count = 0;
        
        for (auto [u, v, w] : edges){
            if ((w|test_mask)==test_mask){
                if (dsu.unit(u, v)){
                    edges_count++;
                }
            }
        }
        if (edges_count == n - 1){
            res = test_mask;
        }
    }
    cout << res << '\n';
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int t;
    cin >> t;
    while(t--){
        find_ostov();
    }
    return 0;
}