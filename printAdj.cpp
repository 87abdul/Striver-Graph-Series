#include<bits/stdc++.h>

using namespace std;

vector<vector<int>> printAdjacency(int V, vector<int>adj[]){
    vector<vector<int>> list(V);
    vector<int> vis(V+1, 0);
    // iterate through all vertex and push it into the answer and also its neighbour nodes
    for(int i = 0 ; i < V ;i++){
        if(!vis[i]){
            vis[i] = 1;
            list[i].push_back(i);
        }
        // neighbour
        for(auto j : adj[i]){
            if(!vis[j]){
                list[i].push_back(j);
            }
        }
    }
    // return the list
    return list;
}

int main() {
    int V = 6; 
    vector<int> adj[V]; 

    // adding edges to the directed graph
    adj[0].push_back(1);
    adj[0].push_back(2);
    adj[1].push_back(3);
    adj[4].push_back(5);
    adj[4].push_back(1);
    adj[5].push_back(5);

    vector<vector<int>> adjList = printAdjacency(V, adj);

    // print the adjacency list
    cout<<"Adjacency List:\n";
    for (int i = 0; i < adjList.size(); i++) {
        cout << i << ": ";
        for (auto j : adjList[i]) {
            cout << j << " ";
        }
        cout << "\n";
    }

    return 0;
}