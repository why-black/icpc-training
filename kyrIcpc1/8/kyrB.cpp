#include <iostream>
#include <string>

using namespace std;


int main(void){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n = 0;
    cin >> n;

    bool socks = false;
    bool shirts[5] = {false, false, false, false, false};
    int hard[5] = {0, 0, 0, 0, 0};
    int res = 0;
    while (n--){
        string c = "";
        string t = "";
        cin >> c;
        cin >> t;
        if (t == "Socks"){
            socks = true;
        } else if (t == "T-shirt"){
            if (c == "Yellow") shirts[0] = true;
            else if (c == "Red") shirts[1] = true;
            else if (c == "Green") shirts[2] = true;
            else if (c == "White") shirts[3] = true;
            else shirts[4] = true;
        } else {
            if (c == "Yellow") hard[0]++;
            else if (c == "Red") hard[1]++;
            else if (c == "Green") hard[2]++;
            else if (c == "White") hard[3]++;
            else hard[4]++;
        }
    }
    for (int i = 0; i < 5; ++i){
        res += shirts[i];
        res += (hard[i] + 1)/2;
    }
    cout << res+int(socks);

    return 0;
}