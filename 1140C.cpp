#include <bits/stdc++.h>

using namespace std;

int main(){
    cin.tie(0)->sync_with_stdio(false);

    int n, k;
    cin >> n >> k;
    vector<pair<int, int>> songs(n);
    for (int i=0; i<n; ++i){
        cin >> songs[i].first >> songs[i].second;
    }

    sort(songs.begin(), songs.end(), [](const auto& a, const auto& b){return a.second>b.second;});

    priority_queue<int, vector<int>, greater<int>> pq; 
    long long cur_size = 0;
    long long best_excited = 0;
    for (int i=0; i<n; ++i){
        auto[t, b] = songs[i];

        cur_size += t;
        pq.push(t);
        if (pq.size()>k){
            cur_size -= pq.top();
            pq.pop();
        }
        best_excited = max(best_excited, cur_size*b);
    }
    cout << best_excited << '\n';
    return 0;
}