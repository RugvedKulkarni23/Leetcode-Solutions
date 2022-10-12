class Solution {
    private:
        void solve(vector<int> nums, int index, vector<vector<int>> &answer){
            //base case 
            if(index>=nums.size()){
                answer.push_back(nums);
                return;
            }
            for(int i=index;i<nums.size();i++){
                 swap(nums[index],nums[i]);
                 solve(nums,index+1,answer);
                 //backtrack
                 swap(nums[index],nums[i]);
            }
        }
public:
    vector<vector<int>> permute(vector<int>& nums) {
           vector<vector<int>> answer;
           int index = 0;
           solve(nums,index,answer);
           return answer;
    }
};