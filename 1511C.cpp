#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, q = 0;
    cin >> n >> q;

    vector<int> idxs (51);
    int curr = 0;
    for (int i = 0; i < n; ++i){
        cin >> curr;
        if (!idxs[curr]){
            idxs[curr]=i+1;
        }
    }
    for (int j = 0; j < q; ++j){
        int color = 0;
        cin >> color;
        int pos = idxs[color];
        cout << pos << " ";
        for (int c = 1; c <= 50; ++c){
            if (idxs[c] < pos){
                idxs[c]++;
            }
        }
        idxs[color] = 1;
    }

    return 0;
}