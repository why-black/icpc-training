#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int mod = 1e9+7;

ll bitpow(ll a, ll b){
    ll res = 1;
    while (b){
        if (b & 1){
            res *= a;
            res %= mod;
        }
        a *= a;
        a %= mod;
        b >>= 1;
    }
    return res;
}

void solve(){
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i=0; i<n; ++i){
        cin >> a[i];
    }
    sort(a.begin(), a.end(), greater<int>());
    
    ll res = 1;
    for (int i=0; i<n; ++i){
        if (i<n-1 && a[i]==a[i+1]){break;}
        res += bitpow(a[i]-1, i+1);
        res %= mod;
    }
    cout << res << '\n';
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