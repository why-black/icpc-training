#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <algorithm>

using namespace std;

void bfs(int start_i, int start_j, int n, int m, vector<vector<char>>& grid, vector<vector<int>>& monster_dist){
    queue<tuple<int, int, int>> q;
    q.push({start_i, start_j, 0});
    grid[start_i][start_j] = '#';

    vector<vector<int>> parent_x(n, vector<int>(m));
    vector<vector<int>> parent_y(n, vector<int>(m));
    vector<vector<char>> move(n, vector<char>(m));

    int dx[] = {1, -1, 0, 0};
    int dy[] = {0, 0, 1, -1};
    char moves[] = {'D', 'U', 'R', 'L'};
    while (!q.empty()){
        auto [x, y, dist] = q.front();
        q.pop();

        for (int i=0; i<4; ++i){
            int new_x = x+dx[i];
            int new_y = y+dy[i];

            if (new_x<n && new_x>=0 && new_y<m && new_y>=0){
                if (grid[new_x][new_y]!='#' && 
                        (monster_dist[new_x][new_y] == -1 || dist + 1 < monster_dist[new_x][new_y])){
                    parent_x[new_x][new_y] = x;
                    parent_y[new_x][new_y] = y;
                    move[new_x][new_y] = moves[i];

                    if (new_x==(n-1) || new_y==(m-1) || new_x==0 || new_y==0){
                        int res = 1;
                        string path = "";
                        path += moves[i];
                        while (x!=start_i || y!=start_j){
                            path += move[x][y];
                            int temp = x;
                            x = parent_x[x][y];
                            y = parent_y[temp][y];
                            res++;
                        }
                        reverse(path.begin(), path.end());
                        cout << "YES\n";
                        cout << res << '\n';
                        cout << path << '\n';
                        return;
                    }
                    q.push({new_x, new_y, dist+1});
                    grid[new_x][new_y] = '#';
                }
            }
        }
    }
    cout << "NO\n";
    return;
}

int main(){
    cin.tie(0)->sync_with_stdio(0);

    int n, m;
    cin >> n >> m;
    vector<vector<char>> grid(n, vector<char>(m));
    vector<vector<int>> monster_dist(n, vector<int>(m, -1));
    int start_i, start_j;
    queue<pair<int, int>> q;
    for (int i=0; i<n; ++i){
        for (int j=0; j<m; ++j){
            cin >> grid[i][j];
            if (grid[i][j]=='A'){
                start_i=i;
                start_j=j;
            } else if (grid[i][j]=='M'){
                q.push({i, j});
                monster_dist[i][j] = 0;
            }
        }
    }
    if (start_i == 0 || start_i == n-1 || start_j == 0 || start_j == m-1) {
        cout << "YES\n0\n";
        return 0;
    }
    
    int dx[] = {1, -1, 0, 0};
    int dy[] = {0, 0, 1, -1};
    while (!q.empty()){
        auto [x, y] = q.front();
        q.pop();
        for (int i=0; i<4; i++){
            int nx = x+dx[i];
            int ny = y+dy[i];
            if (nx<n && nx>=0 && ny<m && ny>=0 && grid[nx][ny]!='#' && monster_dist[nx][ny]==-1){
                monster_dist[nx][ny] = monster_dist[x][y]+1;
                q.push({nx, ny});
            }
        }
    }

    bfs(start_i, start_j, n, m, grid, monster_dist);
    return 0;
}