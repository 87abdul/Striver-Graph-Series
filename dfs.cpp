#include<bits/stdc++.h>

using namespace std;

void dfs(int node, vector<int>&vis, vector<int>&Dfs, vector<int>adj[]){

        Dfs.push_back(node);
        vis[node] = 1;

        for(auto it : adj[node]){
            if(!vis[it]){
                dfs(it, vis, Dfs, adj);
            }
        }
}
vector<int>dfsOfGraph(int V, vector<int>adj[]){
    vector<int> vis(V+1, 0);
    vector<int> Dfs;
    for(int i = 0; i< V ; i++ ){

        if(!vis[i]){
            dfs(i, vis, Dfs, adj);
            }
        }

    return Dfs;
}

int main() {
    int V = 6; 
    vector<int> adj[V]; 

    // adding edges to the directed graph
    adj[0].push_back(1);
    adj[0].push_back(2);
    adj[1].push_back(3);
    adj[4].push_back(1);
    adj[4].push_back(5);
    adj[5].push_back(5);

    vector<int> Dfs = dfsOfGraph(V, adj);

    // print the DFS traversal
    cout<<"DFS Traversal: ";
    for (auto node : Dfs) {
        cout << node << " ";
    }
    return 0;
}