class Solution {
public:
    int missingNumber(vector<int>& nums) {
           
          int sum1 = 0;
          for(int i=0;i<nums.size();i++){
                sum1^= nums[i];
          }
        
          int sum2=0;
          for(int i=0;i<=nums.size();i++){
              sum2^=i;
          }
        
        int answer = sum1^sum2;
        
        return answer;
    }
};