#include <bits/stdc++.h>

using namespace std;

void solve(){
    long long b, c, d;
    cin >> b >> c >> d;
    
    long long a = 0;
    int borrow = 0;
    bool possible = true;
    
    for (int i = 0; i < 62; ++i){
        int bi = (b>>i)&1LL;
        int ci = (c>>i)&1LL;
        int di = (d>>i)&1LL;
        
        int val = 1 - ci - borrow;
        int next_borrow = 0;
        
        if (val < 0){
            val = 1;
            next_borrow = 1;
        }
        if (val == di){
            a |= (1LL << i);
            borrow = next_borrow;
            continue;
        }
        
        val = bi - 0 - borrow;
        next_borrow = 0;
        
        if (val < 0){
            val = 1;
            next_borrow = 1;
        }
        if (val == di){
            borrow = next_borrow;
            continue;
        }
        
        possible = false;
        break;
    }
    if (possible && borrow == 0){
        cout << a << '\n';
    } else {
        cout << -1 << '\n';
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int t;
    cin >> t;
    while (t--){
        solve();
    }
}