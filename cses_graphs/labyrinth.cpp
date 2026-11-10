#include <vector>
#include <iostream>
#include <string>
#include <queue>
#include <algorithm>

using namespace std;

pair<int, string> bfs(int start_x, int start_y, int n, int m, vector<vector<char>>& grid){
    queue<tuple<int, int>> q;
    q.push({start_x, start_y});
    grid[start_x][start_y] = '#';
    
    vector<vector<int>> parent_x (n, vector<int> (m));
    vector<vector<int>> parent_y (n, vector<int> (m));
    vector<vector<char>> move (n, vector<char> (m));

    while (!q.empty()){
        auto [x, y] = q.front();
        q.pop();

        int dx[] = {-1, 1, 0, 0};
        int dy[] = {0, 0, -1, 1};
        char vec[] = {'U', 'D', 'L', 'R'};
        for (int i = 0; i<4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx >= 0 && nx < n && ny >= 0 && ny < m){
                if (grid[nx][ny]!='#'){

                    parent_x[nx][ny] = x;
                    parent_y[nx][ny] = y;
                    move[nx][ny] = vec[i];

                    if (grid[nx][ny]=='B'){
                        int res = 0;
                        string path = "";
                        int cx = nx, cy = ny;
                        while (cx!=start_x || cy != start_y){
                            path += move[cx][cy];
                            int old_cx = cx;
                            cx = parent_x[cx][cy];
                            cy = parent_y[old_cx][cy];
                            res++;
                        }
                        reverse(path.begin(), path.end());
                        return {res, path};
                    }
                    
                    q.push({nx, ny});
                    grid[nx][ny] = '#';
                }
            }            
        }
    }
    return {-1, ""};
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    vector<vector<char>> grid (n, vector<char> (m));
    for (int i=0; i<n; ++i){
        for (int j=0; j<m; ++j){
            cin >> grid[i][j];
        }
    }

    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            if (grid[i][j]=='A'){
                auto [res, way] = bfs(i, j, n, m, grid);
                if (res == -1){
                    cout << "NO" << '\n';
                } else {
                    cout << "YES" << '\n';
                    cout << res << '\n';
                    cout << way << '\n';
                }
                return 0;
            }
        }
    }
}