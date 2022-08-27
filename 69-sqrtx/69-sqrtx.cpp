class Solution {
public:
    long long int BinarySearch(int n){
        int s=0;
        int e=n;
      long long  int ans=-1;
     long long   int mid = s +(e-s)/2;
        while(s<=e){
            if(mid*mid>n){
                e=mid-1;
            }
            else if(mid*mid<n){
                ans = mid;
                s=mid+1;
            }
            else if(mid*mid==n){
                return mid;
            }
            mid = s+(e-s)/2;
        }
        return ans;
    }
    
    int mySqrt(int x) {
          return BinarySearch(x);
    }
};