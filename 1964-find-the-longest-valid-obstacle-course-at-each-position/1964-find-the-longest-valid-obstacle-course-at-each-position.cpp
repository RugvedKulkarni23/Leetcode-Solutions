class Solution {
public:
    vector<int> longestObstacleCourseAtEachPosition(vector<int>& obstacles) {
         int n = obstacles.size();
        
       
        vector<int> lis;
        
       
        
        vector<int> ans;

        for(int i = 0; i < n; i++)
        {
            int idx = upper_bound(lis.begin(), lis.end(), obstacles[i]) - lis.begin();
                
            ans.push_back(idx + 1);
            
            if(idx == lis.size())
                lis.push_back(obstacles[i]);
            
            else
            {
                lis[idx] = obstacles[i];
            }
        }
        
        return ans;
    }
};