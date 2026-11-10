#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void bfs(int x, int y, int n, int m, vector<vector<char>>& grid){
    queue<pair<int, int>> q;
    q.push({x, y});
    // vector<vector<bool>> visited(n, vector<bool> (m, false));
    // visited[x][y] = true;

    int dx[] = {-1, 1, 0, 0};
    int dy[] = {0, 0, -1, 1};

    while(!q.empty()){
        auto [x, y] = q.front();
        q.pop();

        for (int i=0; i<4; i++){
            int new_x = x + dx[i];
            int new_y = y + dy[i];

            if (new_x >= 0 && new_x < n && new_y >= 0 && new_y < m){
                if (grid[new_x][new_y]!='#'){
                    grid[new_x][new_y] = '#';
                    q.push({new_x, new_y});
                }
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;

    vector<vector<char>> grid (n, vector<char> (m));
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            cin >> grid[i][j];
        }
    }
    int res = 0;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            if (grid[i][j]!='#'){
                bfs(i, j, n, m, grid);
                res++;
            }
        }
    }
    cout << res << '\n';
    return 0;
}