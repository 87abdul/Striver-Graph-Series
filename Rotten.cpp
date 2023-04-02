#include<bits/stdc++.h>

    using namespace std;

// 0 : empty cell
// 1 : fresh orange
// 2 : rotten orange

    int OrangeRotting(vector<vector<int>>&grid){
        int n = grid.size();
        int m = grid[0].size();

        // {{row, col} , time}

        queue<pair<pair<int, int>, int>>q;

        vector<vector<int>> vis;

        // Sabse pehle jis bhi cell me rotten oranges(2) ha usko queue me daal do

        for(int i = 0 ;i < n ; i++){
            for(int j = 0 ; j < m ;j++){
                if(grid[i][j] == 2){
                    q.push({{i, j}, 0});

                    vis[i][j] = 2;
                }
                else
                    vis[i][j] = 0;
            }
        }


        // Ab bfs lagana hai

        int time = 0;

        // Neighbour nodes ko lena hai

        int delrow[] = {-1, 0 , +1 , 0 };  //TRDL
        int delcol[] = {0 , +1, 0, -1};

        while(!q.empty()){

            auto it = q.front();

                int row = it.first.first;
                int col = it.first.second;
                int t = it.second;

                time = max(t, time);

                q.pop();

                // Neighbours

                for(int i = 0 ;i < 4 ; i++){
                    int nrow = row + delrow[i];
                    int ncol = col + delcol[i];

                    if(nrow >= 0 && nrow<n && ncol >= 0 && ncol < m && grid[nrow][ncol] == 1 && vis[nrow][ncol] != 2){
                        q.push({{nrow, ncol}, time + 1});
                        vis[nrow][ncol] = 2;
                    }
                }
            }
    }


int main() {
    int n, m;
    cin >> n >> m; // input size of grid

    vector<vector<int>> grid(n, vector<int>(m));

    cout<<"input grid values\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> grid[i][j];
        }
    }

    int timeTaken = OrangeRotting(grid);
    cout << "Time taken to rot all fresh oranges: " << timeTaken << endl;

    return 0;
}