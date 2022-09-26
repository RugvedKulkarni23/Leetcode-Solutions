class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
      int j=0;
       vector<int> answer; 
       for(int i=0;i<nums.size();i++){
           answer.push_back(nums[i]);
       }
       for(int i=0;i<nums.size();i++){
           answer.push_back(nums[i]);
       } 
        return answer;
       
        
    }
};