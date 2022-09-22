class Solution {
public:
    int findClosestNumber(vector<int>& nums) {
        int n = INT_MAX;
        int answer;
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size();i++){
             if(abs(nums[i])<=n){
                 n=abs(nums[i]);
                 answer=nums[i];
                 
             }
        }
        return answer;
    }
};