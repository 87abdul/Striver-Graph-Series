#include<bits/stdc++.h>

    using namespace std;

        bool cycleDetect(int node, int par, vector<int>adj[], vector<int>&vis){

        // vector<int> vis(V+1, 0);
             vis[node] = 1;

        for(auto it : adj[node]){
            if(!vis[it]){
                if(cycleDetect(it, node, adj, vis))
                    return true;
            }

            else if(par != it){
                return true;
            }
        }
            return false;
    }

        bool isCycledfs(int V, vector<int> adj[]){

            vector<int> vis(V+1, 0);

            for(int i = 1 ; i <= V ; i++){
                if(!vis[i]){
                    if(cycleDetect(i, -1, adj, vis))
                        return true;
                }
            }

            return false;
        }

int main() {

    int V = 4; // number of vertices

    vector<int> adj[V+1]; // adjacency list

    // add edges to the graph
    adj[1].push_back(2);
    adj[2].push_back(3);
    adj[2].push_back(4);
    adj[3].push_back(4);

    // check if cycle exists and print result
    bool cycleExists = isCycledfs(V, adj);
    if(cycleExists)
        cout << "Cycle exists in the graph." << endl;
    else
        cout << "No cycle exists in the graph." << endl;

    return 0;
}