#include <iostream>

using namespace std;

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int year = 0;
    cin >> year;

    if (year == 2026){
        cout << 4 << "\n";
        cout << "School Qual\nSchool Regional\nICPC Qual\nICPC Regional\n";
    } else if (year == 2019 || year >= 2022){
        cout << 2 << "\n";
        cout << "ICPC Qual\nICPC Regional\n";
    } else {
        cout << 1 << "\n";
        cout << "ICPC Regional\n";
    }
    
    return 0;
}