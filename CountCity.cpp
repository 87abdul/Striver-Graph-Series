Dijkstra's  c++ Solution:-

int findCity(int n, int m, vector<vector<int>>& edges, int distanceThreshold)
    {
       vector<pair<int, int>>adj[n];
       for(auto it: edges)
       {
           int u= it[0];
           int v=it[1];
           int wt= it[2];
           
           adj[u].push_back({v, wt});
           adj[v].push_back({u, wt});
       }
       priority_queue<pair<int, int>, vector< pair<int, int>>, greater<pair<int, int>>> pq;
       vector<vector < int>> dis;
       
       for(int i=0; i<n; i++)
       {
           vector<int>dst(n, 1e8);
           
           dst[i]=0;
           pq.push({0, i});
           
           while(!pq.empty())
           {
               int wt= pq.top().first;
               int node= pq.top().second;
               
               pq.pop();
               
              for(auto it: adj[node])
              {
                  if(dst[node]+it.second< dst[it.first])
                  {
                      dst[it.first]=dst[node]+it.second;
                      pq.push({dst[it.first], it.first});
                  }
                
              }
           }
           dis.push_back(dst);
       }
        int cntCity=n;
        int cityNo=-1;
        for(int i=0; i<n; i++)
        {
            int count=0;
            for(int j=0; j<n; j++)
            {
                if(dis[i][j]<=distanceThreshold)
                    count++;
                
            }
            if(count<=cntCity)
            {
                cntCity=count;
                cityNo=i;
            }
        }
        return cityNo;
    }