class Solution {
public:
    int longestPath(vector<int>& parent, string s) {
        
        int n = parent.size();
        vector < int > top_1(n, 1), top_2(n, 1), deg(n);
        
        
        for(int i = 1; i < n; i++)
            deg[parent[i]]++;
        
        
        queue < int > topo;

        
        int max_path = 1;

        
        for(int i = 1; i < n; i++)
            if(deg[i] == 0)
                topo.push(i), deg[i]--;
        
        auto update_max = [&](int u, int x){
            
            if(x >= top_1[u])
                top_2[u] = top_1[u], top_1[u] = x;
            else if(x >= top_2[u])
                top_2[u] = x;
        };

        while(!topo.empty() && topo.front()){
            
            int u = topo.front(), p = parent[u];
            topo.pop();

            
            int len = 1 + (s[u] != s[p] ? top_1[u] : 0);
            
            
            update_max(p, len);

            
            if(!--deg[p])
                topo.push(p);

            
            max_path = max(max_path, top_1[p] + top_2[p] - 1);
        }

    
        return max_path;
    }
};