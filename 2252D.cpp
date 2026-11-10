#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void print_out(){
    int n = 0;
    cin >> n;

    vector<long long> a(n);
    vector<long long> d(n-1);
    cin >> a[0];
    for (int i=1; i < n; i++){
        cin >> a[i];
        d[i-1] = a[i] - a[i-1];
    }

    int l = 0;

    while (l < n-1){
        int r = l;
        while (r+1<n-1 && ((d[r] & 1) == (d[r+1] & 1))){r++;}
        sort(d.begin()+l, d.begin()+r+1);
        l = r + 1;
    }

    cout << a[0] << " ";
    for (int i=1; i < n; i++){
        a[i] = a[i-1] + d[i-1];
        cout << a[i] << " ";
    }

    cout << "\n";
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 0;
    cin >> t;

    while (t--) {print_out();}

    return 0;
}