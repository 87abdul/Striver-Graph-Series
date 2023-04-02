#include<bits/stdc++.h>
using namespace std;

// Binary grid -->{0,1}
vector<vector<int>> Nearest(vector<vector<int>>& grid) {

    int n = grid.size();
    int m = grid[0].size();

    vector<vector<int>> dist(n, vector<int>(m, 0));
    vector<vector<int>> vis(n, vector<int>(m, 0));
    queue<pair<pair<int, int>, int>> q;

    // Sabse pehle jis cell me 1 hai usko queue me daal do
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == 1) {
                q.push({ {i, j}, 0 }); // jis cell me already 1 hai uska distance 0 hoga
                vis[i][j] = 1;
            }
            else 
                vis[i][j] = 0;
        }
    }

    // Ab bfs lagana hai
    // 4 directions allowed
    // Neighbours
    int delrow[] = {-1, 0 , +1 , 0 };  //TRDL
    int delcol[] = {0 , +1, 0, -1};

    while (!q.empty()) {
        auto it = q.front();
        int row = it.first.first;
        int col = it.first.second;
        int steps = it.second;
        dist[row][col] = steps;
        q.pop();

        for (int i = 0 ;i < 4 ; i++) {
            int nrow = row + delrow[i];
            int ncol = col + delcol[i];

            if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && vis[nrow][ncol] == 0) {
                q.push({ {nrow, ncol}, steps + 1 });
                vis[nrow][ncol] = 1;
            }
        }
    }

    return dist;
}

int main() {

    int n, m;
    cin >> n >> m; // input size of grid

    vector<vector<int>> grid(n, vector<int>(m));

    // input grid values
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> grid[i][j];
        }
    }

    vector<vector<int>> distances = Nearest(grid);

    // print the distances
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << distances[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}