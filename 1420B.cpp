#include <bits/stdc++.h>

using namespace std;

int get_msb(int x){
    int t = 1;
    int pos = 0;
    if (x >= t << 16) {t <<=16; pos+=16;} 
    if (x >= t << 8) {t <<=8; pos+=8;}
    if (x >= t << 4) {t <<=4; pos+=4;}
    if (x >= t << 2) {t <<=2; pos+=2;}
    if (x >= t << 1) {t <<=1; pos+=1;}
    return pos;
}

void correct_bitops(){
    int n;
    cin >> n;
    vector<int> a (n);
    for (int i=0; i < n; ++i){
        cin >> a[i];
    }
    
    vector<int> freq (31);
    for (int i = 0; i<n; ++i){
        freq[get_msb(a[i])] += 1;
    }
    
    long long res = 0;
    for (int i = 0; i<31; ++i){
        long long count = freq[i];
        res += count * (count-1)/2;
    }
    cout << res << '\n';
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int t;
    cin >> t;
    while (t--){
        correct_bitops();
    }
    return 0;
}
