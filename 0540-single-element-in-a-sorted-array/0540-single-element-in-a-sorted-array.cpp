class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
         int lmt = nums.size() - 1, mid;
       
        for (int l = 0, r = lmt, prev, nxt; l <= r;) {
           
            mid = (l + r) >> 1;
            prev = mid ? nums[mid - 1] : nums[mid] - 1;
            nxt = mid != lmt ? nums[mid + 1] : nums[mid] + 1;
            
            if (nums[mid] != prev && nums[mid] != nxt) return nums[mid];
           
            else if (nums[mid] != (mid & 1 ? prev : nxt)) r = mid - 1;
            
            else l = mid + 1;
        }
        return nums[mid];
    }
};