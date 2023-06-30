class Solution {
public:
    bool solve(int row,int col,vector<vector<int>>& cells,int mid)
    {

        vector<vector<int>> arr(row,vector<int>(col,0));
        for(int i=0;i<mid;i++)
        {
            arr[cells[i][0]-1][cells[i][1]-1]=1;

        }
        queue<pair<int,int>> q;
        for(int i=0;i<col;i++){
            if(arr[0][i]==0)
            {
                q.push({0,i});
                arr[0][i]=1;
            }
        }

        int dir[5] = {0, 1, 0, -1, 0};
        while(!q.empty())
        {
            int x=q.front().first;
            int y=q.front().second;
            q.pop();
            if(x==row-1) return 1;
            for(int i=0;i<4;i++)
            {
                int xx=x+dir[i];
                int yy=y+dir[i+1];
                if(xx<0 || yy<0 || xx>=row || yy>=col || arr[xx][yy]==1) continue;
                arr[xx][yy]=1;
                q.push({xx,yy});
            }
        }
        return 0;
    }
    int latestDayToCross(int row, int col, vector<vector<int>>& cells) {
        
        int i=1,j=cells.size();
        int ans=0;
        while(i<=j)
        {
            int m=(i+j)/2;
            if(solve(row,col,cells,m))
            {
                ans=m;
                i=m+1;
            }
            else j=m-1;
        }
        return ans;
    }
};