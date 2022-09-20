class Solution {
public:
    int missingNumber(vector<int>& nums) {
         int n = nums.size();
         int expectedTotal= (n*(n+1)/2);
         int total =0;
         for(int num:nums){
             total += num;
         }
        return expectedTotal-total;
    }
};