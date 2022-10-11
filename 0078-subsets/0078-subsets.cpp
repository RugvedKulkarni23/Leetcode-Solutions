class Solution {
    
    private:
          void solve(vector<int> nums,vector<int> output, int index,vector<vector<int>> &answer){
              //base case
              if(index>= nums.size()){
                  answer.push_back(output);
                  return;
              }
              //exclude
              solve(nums,output,index+1,answer);
              //include
              int element = nums[index];
              output.push_back(element);
              solve(nums,output,index+1,answer);
          }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
         vector<vector<int>> answer;
         vector<int> output;
         int index = 0;
         solve(nums,output,index,answer);
         return answer;
    }
};