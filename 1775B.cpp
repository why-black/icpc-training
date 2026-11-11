#include <bits/stdc++.h>

using namespace std;

vector<int> freq(200001, 0);

void check_seq(){
    int n;
    cin >> n;
    vector<vector<int>> bits (n);
    
    for (int i = 0; i < n; ++i){
        int k;
        cin >> k;
        bits[i] = vector<int>(k);
        for (int j=0; j<k; ++j){
            int x;
            cin >> x;
            bits[i][j]=x;
            freq[x] += 1;
        }
    }
    bool found = false;
    for (int i = 0; i<n; ++i){
        bool good = true;
        int k = bits[i].size();
        for (int j = 0; j<k; ++j){
            int x = bits[i][j];
            if (freq[x]-1<1) {good = false; break;}
        }
        if (good) {
            found = true;
            break;
        }
    }
    if (found) cout<<"YES"<<'\n';
    else cout << "NO" << '\n';
    for (int i = 0; i < n; ++i) {
        for (int x : bits[i]) {
            freq[x] = 0; 
        }
    }

}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int t;
    cin >> t;
    while(t--){
        check_seq();
    }
    
    return 0;
}