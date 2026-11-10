#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void print_res(){
    int n = 0;
    int k = 0;
    cin >> n;
    cin >> k;

    int prev = 0;
    cin >> prev;
    int cur = 0;
    bool sorted = true;
    for (int i = 1; i < n; ++i){
        cin >> cur;
        if (cur < prev){
            sorted = false;
        }
        prev = cur;
    }
    if (k >= 2 || sorted) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t = 0;
    cin >> t;

    while (t--){print_res();}

    return 0;
}