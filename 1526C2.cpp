#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main(){
    cin.tie(0)->sync_with_stdio(false);

    int n;
    cin >> n;

    ll hp = 0;
    int count = 0;
    priority_queue<int, vector<int>, greater<int>> pq;
    for (int i=0; i<n; i++){
        int x;
        cin >> x;
        
        hp += x; 
        count++; 
        if (x < 0) { 
            pq.push(x);
        }
        if (hp<0){
            hp -= pq.top();
            pq.pop();
            count--;
        }
    }
    cout << count << '\n';
    return 0;
}