class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        map<vector<int>, int> mp;
        int m = grid.size();
        int n = grid[0].size();
        
        for(int i =0; i<m; i++){
            mp[grid[i]]++;
        }
        
        int ans = 0;
        
        for(int j = 0; j<n; j++){
            vector<int> col;
            for(int i = 0; i<m; i++){
                col.push_back(grid[i][j]);
            }

            if(mp[col]>0) ans += mp[col];
        }
        return ans;
    }
};