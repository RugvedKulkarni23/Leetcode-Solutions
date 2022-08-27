class Solution {
public:
     int  FindMin(vector<int>& nums){
              int s =1;
              int  e = nums.size()-2;
             int mid;
              while(s<=e){
                    mid = s + (e-s)/2;
                    if(nums[mid]<nums[mid-1] && nums[mid]<nums[mid+1]){
                         return nums[mid];
                    }
                    else if(nums[mid]>nums[e]){
                        s=mid+1;
                    }
                    else {
                        e=mid-1;
                    }
                  
              }
             return min(nums[0],nums[nums.size()-1]);
         }
    int findMin(vector<int>& nums) {
         return FindMin(nums);
    }
};