#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve(){
    ll n, k;
    cin >> n >> k;
    
    string num;
    cin >> num;
    ll count_ones = 0;
    for (char c : num) {
        if (c == '1') count_ones++;
    }
    ll zeros = n - count_ones;
    if (zeros > count_ones){
        k = min(count_ones, k);
        ll res = 1 + (zeros+k)*(zeros+k+1)/2 + (count_ones-k)*(count_ones-k+1)/2;
        cout << res << '\n';
    } else {
        k = min(zeros, k);
        ll res = 1 + (zeros-k)*(zeros-k+1)/2 + (count_ones+k)*(count_ones+k+1)/2;
        cout << res << '\n';   
    }
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