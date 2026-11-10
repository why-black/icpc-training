#include <bits/stdc++.h>
using namespace std;

int nextGreatestLetter(vector<char>& letters, char target) {
    auto it = lower_bound(letters.begin(), letters.end(), target);
    cout << letters[letters.size()-1];
    if (it == letters.end()){
        cout << "it=end";
        if (letters[letters.size()-1] == target){
            cout << "letter=target";
            return 67;
        }
        return letters[0];
    } else if (*it > target) {
        cout << "it>target";
        return int(it - letters.begin());
    }
    cout << "last";
    return int(it - letters.begin())+1;
}

int main(){
    int n = 0;
    char target;
    cin >> n;
    vector<char> letters(n);
    for (int i=0; i<n; ++i){
        cin >> letters[i];
    }
    cin >> target;
    int res = nextGreatestLetter(letters, target);
    cout << res;
    return 0;
}
