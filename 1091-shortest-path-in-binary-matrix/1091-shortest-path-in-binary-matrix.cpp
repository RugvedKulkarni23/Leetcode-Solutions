class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
         queue<pair<int,int>> q;
        int n = grid.size();
        if(grid[0][0] != 0 || grid[n-1][n-1] != 0)
            return -1;
        if(n-1 == 0)
            return 1;
        grid[0][0] = 1;  
        q.push({0,0});
        int count = 0;
        int flag = 0;
        vector<int> r = {0,1,-1,0,1,-1,1,-1};
        vector<int> c = {1,0,0,-1,1,1,-1,-1};
        while(!q.empty())
        {
            int size = q.size();
            queue<pair<int,int>> temp;
            count++;
            while(size--)
            {
                int row = q.front().first;
                int col = q.front().second;
                q.pop();
                for(int i = 0; i<8; i++)
                {
                    int x = row + r[i], y = col + c[i];
                    if(x == n-1 && y == n-1)
                    {
                        flag = 1;
                        count++;
                        break;
                    }
                    if(x >= 0 && y >= 0 && x < n && y < n)
                    {
                        if(grid[x][y] == 0)
                        {
                            temp.push({x,y});
                            grid[x][y] = 1;
                        }
                    }
                }
                if(flag == 1)
                    break;
            }
            q = temp;
            if(flag == 1)
                break;
        }
        if(flag == 0)
            return -1;
        return count;
    }
};