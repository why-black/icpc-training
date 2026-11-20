#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main(){
    cin.tie(0)->sync_with_stdio(0);

    int n;
    cin >> n;
    string method;
    int x;
    priority_queue<int, vector<int>, greater<int>> pq;
    vector<int> res_methods;
    vector<int> res_nums;
    for (int i=0; i<n; i++){
        cin >> method;
        if (method[0]=='i'){
            res_methods.push_back(1);
            cin >> x;
            res_nums.push_back(x);
            pq.push(x);

        } else if (method[0]=='g'){
            cin >> x;

            while (!pq.empty() && x > pq.top()){
                pq.pop();
                res_methods.push_back(3);
            }
            if (pq.empty() || pq.top()>x){
                res_methods.push_back(1);
                res_nums.push_back(x);
                pq.push(x);
            }
            
            res_methods.push_back(2);
            res_nums.push_back(x);

        } else {
            if (pq.empty()){
                res_methods.push_back(1);
                res_nums.push_back(1);
                pq.push(1);
            }
            pq.pop();
            res_methods.push_back(3);
        }
    }

    n = res_methods.size();
    cout << n << '\n';
    int val_idx = 0;

    for (int i=0; i<n; ++i){
        int method = res_methods[i];
        if (method == 1){
            cout << "insert " << res_nums[val_idx++] << '\n';
        } else if (method==3){
            cout << "removeMin\n"; 
        } else if (method==2){
            cout << "getMin " << res_nums[val_idx++] << '\n';
        }
    }
    return 0;
}