class Solution {
public:
    bool isPerfectSquare(int num) {
             int s=1,e=num;
        
           while(s<=e){
                long   mid = s+(e-s)/2;
               
                if(num == mid*mid){
                     return true;
                }
               else if(num>mid*mid){
                   s=mid+1;
               }
               else{
                    e=mid-1;
               }
           }
        
        return false;
    }
};



