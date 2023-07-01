class Solution {
public:
    vector<int> v;
    int ans=1e9,sz;
    bool calc(int m, int k) {
        sort(v.begin(),v.end());
        do{
            int cnt=0,cur=0;
            for(int i=0;i<sz;i++) {
                if(cur+v[i]>m) {
                    cnt++; cur=v[i];
                }
                else cur+=v[i];
            }
            cnt++;
            if(cnt<=k) return 1;
        }while(next_permutation(v.begin(),v.end()));
        return 0;
    }
    int distributeCookies(vector<int>& cookies, int k) {
        v=cookies; 
        sz=v.size();
        int l=*max_element(v.begin(),v.end()), r=1e6;
        while(l<=r) {
            int m=(l+r)/2;
            if(calc(m,k)) {
                r=m-1;
            }
            else {
                l=m+1;
            }
        }
        return r+1;
    }
};