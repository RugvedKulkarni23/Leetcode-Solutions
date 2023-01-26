class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
         vector<pair<int, int>> adj[n];
        vector<int> dis(n, 1e9);
        queue<vector<int>> q;
        
       
        for(auto it: flights){
            adj[it[0]].push_back({it[1], it[2]});
        }
        
       
        q.push({0, src, 0});
        
        dis[src] = 0;
        
        
        while(!q.empty()){
            
            int stop = q.front()[0];
            int node = q.front()[1];
            int cost = q.front()[2];
           
            q.pop();
            
            if(stop > k) continue;
            
           
            for(auto it: adj[node]){
                int adjNode = it.first;
                int weight = it.second;
                
                if(cost + weight < dis[adjNode]) {
                    dis[adjNode] = cost + weight;   
                    q.push({stop+1, adjNode, cost + weight});  
                }
            }
        }
        
      
        return dis[dst] == 1e9 ? -1 : dis[dst];
    }
};