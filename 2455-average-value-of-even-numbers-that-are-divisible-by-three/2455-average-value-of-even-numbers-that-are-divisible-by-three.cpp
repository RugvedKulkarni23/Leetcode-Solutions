class Solution {
public:
    int averageValue(vector<int>& nums) {
        int average = 0;
        int answer=0;
        int count=0;
             for(int i=0;i<nums.size();i++){
                 
                   if(nums[i]%3==0 && nums[i]%2==0){
                       average+=nums[i];
                       count++;
                       
                      }
                 
                 
             }
        if(count>0)
         answer = (average/count);
         
        return answer;
         
        
    }
};