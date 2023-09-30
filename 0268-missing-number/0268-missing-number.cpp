class Solution {
public:
    int missingNumber(vector<int>& nums) {
           int X1= nums[0] ;
           int X2 = 1;
           for(int i=1;i<nums.size();i++){
               X1^=nums[i];
           }
           
          for(int i=2;i<=nums.size();i++){
              X2^=i;
          }
        int answer = X1^X2;
        return answer;
    }
};