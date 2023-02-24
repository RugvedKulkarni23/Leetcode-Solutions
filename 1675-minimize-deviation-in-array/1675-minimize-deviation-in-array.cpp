class Solution {
public:
    int minimumDeviation(vector<int>& nums) {
        int n = nums.size();
        
       
        int maxi = INT_MIN;
        
        int mini = INT_MAX;
        
        for(int i = 0; i < n; i++)
        {
            if(nums[i] % 2 != 0)
            {
                nums[i] = 2 * nums[i];
            }
            
            maxi = max(maxi, nums[i]);
            
            mini = min(mini, nums[i]);
        }
        
        
        
        priority_queue<int> pq;
        
       
        
        for(int i = 0; i < n; i++)
        {
            pq.push(nums[i]);
        }
        
       
        
        int min_deviation = maxi - mini;
        
        int top = 0;
        
        while(pq.top() % 2 == 0)
        {
            top = pq.top();
            
            pq.pop();
            
            min_deviation = min(min_deviation, top - mini);
            
            mini = min(mini, top / 2);
            
            pq.push(top / 2);
        }
        
        top = pq.top();
        
        min_deviation = min(min_deviation, top - mini);
        
        return min_deviation;
    }
};