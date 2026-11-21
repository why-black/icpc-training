#include <bits/stdc++.h>

using namespace std;

void solve(){
    int x;
    cin >> x;
    if (x==1) {
        cout << 1 << '\n';
        return;
    }
    
    int ans=1e9;

    for (int b=0; b<=200; b++){
        int l = 1, r = b;
        int best_n = b;

        while (l<=r){
            int mid = l + (r-l)/2;
            int n = b - mid;

            int sum = n*(b+1) - n*(n-1)/2;
            if (sum >= x){
                l = mid+1;
                best_n = n;
            } else {
                r = mid-1;
            }
        }
        if (best_n*(b+1) - best_n*(best_n-1)/2 >= x){
            ans = min(ans, best_n+b);
        }
    }

    cout << ans << '\n';
}

int main(){
    cin.tie(0)->sync_with_stdio(false);

    int t;
    cin >> t;
    while (t--){
        solve();
    }
}