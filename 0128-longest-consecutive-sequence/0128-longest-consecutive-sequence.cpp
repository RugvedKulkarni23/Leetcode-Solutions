class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
           
             if(nums.size()==0)
             {
                 return 0;
             }
             unordered_set<int> s;
        
        
            for(int i=0;i<nums.size();i++)
            {
                   s.insert(nums[i]);
            }
             int result=1;
             for(auto x: s)
             {
                  if(s.find(x-1)==s.end())
                      
                  {
                      int current=1;
                      while(s.find(x+current)!= s.end())
                      {
                          current++;
                      }
                      
                      result = max(result,current);
                  }
             }
        return result;
    }
};