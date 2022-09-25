class Solution {
public:
    int sumOfUnique(vector<int>& nums) {
         int frequency[101] = {0};
         int sum =0;
         for(int i=0;i<nums.size();i++){
              frequency[nums[i]]++;
         } 
         for(int i=0;i<101;i++){
             if(frequency[i]==1)
                 sum += i;
         }
        return sum;
             
             
         
         
    }
};




