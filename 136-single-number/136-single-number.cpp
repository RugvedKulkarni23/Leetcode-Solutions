class Solution {
public:
    int singleNumber(vector<int>& nums) {
         int answer =0;
        for( auto i:nums){
            answer = answer^i;
        }
        return answer;
    }
};