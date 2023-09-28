class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
            int n = nums.size();
             vector<int> answer(n);
             int count=0;
             for(int i=0;i<nums.size();i++){
                   if(nums[i]%2==0){
                       swap(nums[i],nums[count]);
                       count++;
                   }
             }
        
           for(int i=0;i<nums.size();i++){
                answer[i] = nums[i];
           }
        
        return answer;
    }
};