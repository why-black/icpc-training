#include <bits/stdc++.h>

using namespace std;

void check_lonely_bit(){
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i=0; i<n; ++i){
        cin >> a[i];
    }
    
    int max_seq = 0;
    for (int i = 0; i<21; ++i){
        int longest_cur_bit_streak = 0;
        
        int cur_bit = 1<<i;
        int cur_streak = 0;
        bool has_one = false;
        for (int j=0; j<n; j++){
            if ((cur_bit&a[j])==0){
                cur_streak++;
            } else {
                has_one = true;
                if (cur_streak>longest_cur_bit_streak){
                    longest_cur_bit_streak = cur_streak;
                }
                cur_streak = 0;
            }
        }
        if (cur_streak>longest_cur_bit_streak){
            longest_cur_bit_streak = cur_streak;
        }
        if(has_one && longest_cur_bit_streak > max_seq){
            max_seq = longest_cur_bit_streak;
        }
    }
    cout << max_seq+1 <<'\n';
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int t;
    cin >> t;
    while(t--){
        check_lonely_bit();
    }
}