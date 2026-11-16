#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve(){
    int n;
    cin >> n;
    if (n <= 3){
        cout << -1 << '\n';
        return;
    }
    cout << 4 << " " << 3 << " " << 2 << " " << 1 << " ";
    if (n > 4){}
    for (int i=5; i<=n; ++i){
        cout << i << " ";
    }
    cout << '\n';
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while(t--){
        solve();
    }

    return 0;
}