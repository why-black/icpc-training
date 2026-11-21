#include <bits/stdc++.h>

using namespace std;

int main(){
    cin.tie(0)->sync_with_stdio(false);
    
    priority_queue<int, vector<int>, less<int>> pq;
    int n, m;
    cin >> n >> m;
    int cur_sum = 0;
    vector<int> res (n, 0);
    for (int i=0; i<n; ++i){
        int t;
        cin >> t;
        cur_sum += t;
        if (cur_sum > m){
            int cur_sum_copy = cur_sum;
            priority_queue<int, vector<int>, less<int>> pq_copy = pq;
            while (cur_sum_copy > m){
                cur_sum_copy -= pq_copy.top();
                pq_copy.pop();

                res[i]++;
            }
        }

        pq.push(t);
    }

    for (int i=0; i<n; i++){
        cout << res[i] << " ";
    }
    cout << '\n';
}