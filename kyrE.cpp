#include <bits/stdc++.h>
using namespace std;

using ll = long long;

struct Fenwick {
    int n;
    vector<int> bits;
    Fenwick(int n): n(n), bits(n+1, 0) {}
    void add (int i, int v) {
        for (; i <= n; i += i & -i) {bits[i]+=v;}
    }
    int sum(int i){
        int s = 0;
        for (; i>0; i -= i & -i){s += bits[i];}
        return s;
    }
    int kth(int k){
        int pos = 0;
        for (int pw = 1 << 20; pw; pw>>=1){
            if (pw+pos<=n && bits[pos+pw]<k){
                pos += pw;
                k -= bits[pos];
            }
        }
        return pos + 1;
    }
};

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int k = 0;
    int n = 0;

    cin >> n;
    cin >> k;

    Fenwick fw(n);

    for(int i = 1; i < n; ++i){fw.add(i, 1);}

    vector<int> res (n+1);
    for (int i = n; i > 0; i--){
        int d = min(i-1, k);
        k -= d;
        int pos = fw.kth(i - d);
        res[pos] = i;
        fw.add(pos, -1);
    }

    for (int i = 1; i <= n; ++i) cout << res[i] << " \n"[i==n];
    return 0;
}