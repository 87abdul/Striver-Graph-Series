#include<bits/stdc++.h>

/*Given a 2D screen arr[][] where each arr[i][j] is an integer representing the color of that pixel, also given the location of a pixel (X, Y) and a color C, the task is to replace the color of the given pixel and all the adjacent same-colored pixels with the given color.*/


    using namespace std;


    void dfs(int row, int col,vector<vector<int>>&vis,vector<vector<int>>&image, int newColor, int delrow[], int delcol[],int initColor ){

                vis[row][col] = newColor;

                int n = image.size();
                int m = image[0].size();

                for(int i = 0 ;i <4;i++){
                    int nrow = row + delrow[i];
                    int ncol = col + delcol[i];

                    if(nrow >=0 && nrow<n && ncol>=0 && ncol<m && image[nrow][ncol] == initColor && vis[nrow][ncol] != newColor)
                    {
                        dfs(nrow, ncol, vis, image, newColor, delrow, delcol, initColor);
                    }
                }
           }

    vector<vector<int>>floodFill(vector<vector<int>>&image, int sr, int sc, int newColor){

        int initColour = image[sr][sc];

        vector<vector<int>>vis = image;

        // Neighbours

        int delrow[] = {-1,0,+1,0}; // Top Left Down Right
        int delcol[] = {0,+1,0,-1}; // Top Left Down Right

        dfs(sr, sc, vis,image, newColor, delrow, delcol, initColour);

    return vis;
}

int main(){
// Sample Input
vector<vector<int>> image =
    {{1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 0, 0},
	{1, 0, 0, 1, 1, 0, 1, 1},
	{1, 2, 2, 2, 2, 0, 1, 0},
	{1, 1, 1, 2, 2, 0, 1, 0},
	{1, 1, 1, 2, 2, 2, 2, 0},
	{1, 1, 1, 1, 1, 2, 1, 1},
	{1, 1, 1, 1, 1, 2, 2, 1}};

// {{1,1,1},{1,1,0},{1,0,1}};
int sr = 4, sc = 4, newColor = 3;

 // Calling the function to perform flood fill algorithm on given input
 vector<vector<int>> result = floodFill(image, sr, sc, newColor);

 // Outputting the resulting image after flood fill
 for(int i=0;i<result.size();i++){
     for(int j=0;j<result[0].size();j++){
         cout << result[i][j] << " ";
     }
     cout << endl;
    }
}

  