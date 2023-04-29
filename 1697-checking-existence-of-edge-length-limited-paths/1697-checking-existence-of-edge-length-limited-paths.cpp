
   bool comp(vector<int> &a,vector<int> &b){
    if(a[2] == b[2]){
        return a[1]<b[1];
    }
    return a[2]<b[2];
}

class Solution {
public:
    
    // Union Find data structure
    
    int parent[100005];
    int sz[100005];
    
    void makeset(int v){
        parent[v] = v;
        sz[v] = 1;
    }
    int find(int v){
        if(parent[v] == v) return v;
        return parent[v] = find(parent[v]);
    }
    void Union(int x,int y){
        x = find(x);
        y = find(y);
        if(x == y) return;
        if(sz[x]>sz[y]) swap(x,y);
        parent[y] = x;
        sz[y]+=sz[x];
    }
    
    vector<bool> distanceLimitedPathsExist(int n, vector<vector<int>>& edgeList, vector<vector<int>>& queries) {
        
        for(int i=0;i<n;i++) {
            makeset(i);
        }
        int m = queries.size();
        for(int i=0;i<queries.size();i++) {
            queries[i].push_back(i);
        }
        
        sort(queries.begin(),queries.end(),comp);
        sort(edgeList.begin(),edgeList.end(),comp);
        vector<bool> ans(queries.size(),false);
        int i=0;
        int j=0;
        // two pointer
        // building graph based on weights allowed by queries
        while(j<m){
            int wt = queries[j][2];
            
            while(i<edgeList.size() && edgeList[i][2]<wt){
                int a = edgeList[i][0];
                int b = edgeList[i][1];
                Union(a,b);
                i++;
            }
            if(find(queries[j][0]) == find(queries[j][1])){
                ans[queries[j][3]] = 1;
            }
            j++;
        }
        return ans;
    }
};