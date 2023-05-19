class Solution {
public:
    bool dfs(vector<vector<int>> &graph, int cur, int clr, vector<int> &color){
        color[cur] = clr;
        for(auto &child : graph[cur]){
            if(color[child] != -1){
                if(clr == color[child]) return false;
            }else{
                if(dfs(graph, child, abs(clr-1), color) == false) return false;
            }
        }
        return true;
    }
    
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> color(n,-1);
        
        for(int i=0; i<n; ++i){
            if(color[i]==-1){
                if(dfs(graph,i,0,color) == false) return false;
            }
        }
        return true;
    }
};