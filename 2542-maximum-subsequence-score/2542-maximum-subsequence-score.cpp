class Solution {
public:
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
        int n=nums1.size();
        long long h=INT_MIN;
        if(k==1)
        {
            for(int i=0;i<n;i++)
            {
                if(h<nums1[i]*nums2[i])
                    h=nums1[i]*nums2[i];
            }
            return h;
        }
        priority_queue<int, vector<int>, greater<int>> pq;
        
        vector<long long> dp(n);
        long long sum=0, ans=-1;
        vector<pair<int, int>> v;
        for(int i=0;i<nums1.size();i++)
            v.push_back({nums2[i], nums1[i]});
        
        sort(v.begin(), v.end());
        int l=k-1, i=n-1;
        while(l--)
        {
            sum+=v[i].second;
            pq.push(v[i].second);
            int f=v[i].second;
            i--;
        }
        dp[n-k+1]=sum;
        for(int i=n-k;i>=0;i--)
        {
            if(v[i].second>pq.top())
            {
                int y=v[i].second-pq.top();
                sum+=y;
                dp[i]=sum;
                pq.pop();
                
                pq.push(v[i].second);
                continue;
            }
            dp[i]=dp[i+1];
        }
        long long my=INT_MIN;
        int g=n-k;
        for(int i=g;i>=0;i--)
        {
            if(my<(dp[i+1]+v[i].second)*v[i].first)
                my=(dp[i+1]+v[i].second)*v[i].first;
        }
        return my;
    }
};