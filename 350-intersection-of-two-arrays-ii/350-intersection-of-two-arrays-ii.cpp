class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
          int n = nums1.size();
          int n2 = nums2.size();
          int p=0;
          int q=0;
          vector<int> answer;
          sort(nums1.begin(),nums1.end());
          sort(nums2.begin(),nums2.end());
         while(p<n && q<n2){
             if(nums1[p]<nums2[q]){
                 p++;
             }
             else if(nums1[p]>nums2[q]){
                 q++;
             }
             else if(nums1[p]==nums2[q]){
                 answer.push_back(nums1[p]);
                 p++;
                 q++;
             }
         }
        return answer;
         
    }
};





