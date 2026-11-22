#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int maxn = 100005;
int c[maxn];
vector<int> primes;
bool sostavnoe[maxn];

void our_const(){
    c[1] = 1;
    for (int i=2; i<maxn; i++){
        if (!sostavnoe[i]){
            primes.push_back(i);
            c[i] = -1;
        }
        for (int p:primes){
            if (p*i >= maxn) break;
            sostavnoe[i*p] = true;
            if (i % p == 0) {
                c[i * p] = 0;
                break;
            } else {
                c[i * p] = -c[i];
            }
        }
    }
}

void solve() {
    ll A, B, C;
    int N;
    cin >> A >> B >> C >> N;
    
    ll S = N + 3;
    ll res = 0;

    for (ll d = 1; d <= S / 3; ++d) {
        if (S % d == 0) {
            ll s_d = S / d;

            ll sum = (s_d - 1) * (s_d - 2) / 2;
            res += c[d] * sum;
        }
    }
    
    cout << res << '\n';
}


int main(){
    cin.tie(0)->sync_with_stdio(false);
    
    our_const();
    solve();

    return 0;
}