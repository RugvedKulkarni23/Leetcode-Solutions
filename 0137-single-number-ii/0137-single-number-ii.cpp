class Solution {
public:
    int singleNumber(vector<int>& nums) {
         unordered_map<int,int> mp;
         int n = nums.size();
         for(int i=0;i<n;i++){
              mp[nums[i]]++;
         }
        int i;
        for( i=0;i<n;i++){
            if(mp[nums[i]]<3){
                break;
            }
        }
        
        return nums[i];
    }
};