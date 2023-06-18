class Solution {
public:
    int mod = 1e9 + 7;
    int DX[4] = {-1, 1, 0, 0};
    int DY[4] = {0, 0, -1, 1};
    
    int func(vector<vector<int>>& grid, vector<vector<int>>& dp, int x, int y, int m, int n) {
        long long seju = 1;
        

        if (dp[x][y] != -1) {
            return dp[x][y];
        }
        
      
        for (int i = 0; i < 4; i++) {
            int cx = x + DX[i];
            int cy = y + DY[i];
            
           
            if (cx >= 0 && cx < m && cy >= 0 && cy < n && grid[x][y] < grid[cx][cy]) {
                seju += func(grid, dp, cx, cy, m, n);
            }
        }
        
        return dp[x][y] = seju % mod;
    }
    
    int countPaths(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
      
        vector<vector<int>> dp(m, vector<int>(n, -1));
        
        long long seju = 0;
        
       
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
               
                seju += func(grid, dp, i, j, m, n);
            }
        }
        
       
        return seju % mod;
    }
};