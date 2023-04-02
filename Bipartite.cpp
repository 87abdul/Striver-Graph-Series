#include<bits/stdc++.h>

    using namespace std;

        bool bipartite(int src, vector<int>adj[], int col[]){

            queue<int>q;
            q.push(src);

            col[src] = 1;

            while(!q.empty()){
                int node = q.front();
                q.pop();

                for(auto it : adj[node]){

                    if(col[it] == -1){
                        col[it] = !col[node]; // opposite colour
                        q.push(it);
                    }

                    else if(col[it] == col[node]) 
                    return false;
                }
            }
            return true;
    } 

        bool checkBipartite(int V, vector<int> adj[]){

                int col[V];
                memset(col, -1, sizeof(col));
            for(int i = 1 ; i <= V ; i++){
                
                if(col[i] == -1){
                    if(bipartite(i, adj, col)){
                        return false;
                    }
                }
            }

            return true;
        }


// int main() {
//     int V = 5; // number of vertices
//     vector<int> adj[V+1]; // adjacency list

//     // add edges to the graph
//     adj[1].push_back(2);
//     adj[2].push_back(1);
//     adj[2].push_back(3);
//     adj[3].push_back(2);
//     adj[3].push_back(4);
//     adj[4].push_back(3);
//     adj[4].push_back(5);
//     adj[5].push_back(4);

//     // check if graph is bipartite and print result
//     bool isBipartite = checkBipartite(V, adj);
//     if(isBipartite)
//         cout << "Graph is bipartite." << endl;
//     else
//         cout << "Graph is not bipartite." << endl;

//     return 0;
// }

