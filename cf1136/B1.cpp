#include <bits/stdc++.h>

using namespace std;

void solve(){
    int x, y, m;
    cin >> x >> y >> m;
    string s;
    cin >> s;

    int count = x+y;
    if (count == 0){
        cout << 0 << '\n';
        return;
    }

    set<pair<int, int>> states;
    states.insert({x, y});

    int max_count = count;
    for (char c:s){
        set<pair<int, int>> next_states;

        for (auto [cx, cy] : states) {
            if (c == '+'){
                if (cx>0) next_states.insert({cx-1, cy+1});
                if (cy>0) next_states.insert({cx, cy+1});
            } else {
                if (cx>0) next_states.insert({cx-1, cy});
                if (cy>0) next_states.insert({cx+1, cy-1});
            }
        }

        if (next_states.empty()) break;

        states = next_states;
        for (auto[cx, cy]:states){
            max_count = max(max_count, cx + cy);
        }
    }
    cout << max_count << '\n';
    return;
}

int main(){
    cin.tie(0)->sync_with_stdio(false);

    int t;
    cin >> t;
    while(t--){
        solve();
    }
}