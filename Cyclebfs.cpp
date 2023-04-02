#include<bits/stdc++.h>

    using namespace std;

        bool cycleDetect(int s, int V, vector<int>adj[], vector<int>&vis){

        // vector<int> vis(V+1, 0);

        queue<pair<int , int>>q;

        vis[s] = true;

        q.push({s,-1});

        while(!q.empty()){

            int node = q.front().first;
            int par = q.front().second;
            q.pop();

        for(auto it : adj[node]){
            if(!vis[it]){
                vis[it] = true;
                q.push({it, node});
            }

            else if(par != it){
                return true;
            }
        }
    }
            return false;
    }

        bool isCyclebfs(int V, vector<int> adj[]){

            vector<int> vis(V+1, 0);

            for(int i = 1 ; i <= V ; i++){
                if(!vis[i]){
                    if(cycleDetect(i, V, adj, vis))
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
    adj[1].push_back(3);
    adj[1].push_back(4);
    adj[2].push_back(1);
    adj[2].push_back(3);
    adj[3].push_back(2);
    adj[3].push_back(4);
    // adj[5].push_back(4);
    adj[4].push_back(3);
    adj[4].push_back(1);
    // adj[5].push_back(4);

    // check if cycle exists and print result
    bool cycleExists = isCyclebfs(V, adj);
    if(cycleExists)
        cout << "Cycle exists in the graph." << endl;
    else
        cout << "No cycle exists in the graph." << endl;

    return 0;
}