class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
    
        int n= nums1.size();
        int n1= nums2.size();
        int p=0;
        int q=0;
        set<int> s;
        sort(nums1.begin(),nums1.end());
        sort(nums2.begin(),nums2.end());
        while(p<n && q<n1){
            if(nums1[p]<nums2[q]){
                p++;
            }
            else if(nums2[q]< nums1[p])
                q++;
            
            else if(nums1[p]==nums2[q]){
                s.insert(nums1[p]);
                p++;
                q++;
            }
            
        }
        vector<int> answer;
        for(auto i:s) answer.push_back(i);
        return answer ;
        
    }   
    
};