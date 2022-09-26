class Solution {
public:
    bool isThree(int n) {
        if(n==1 || n==2){
            return false;
        }
       else  if ((ceil(sqrt(n))) != (floor(sqrt(n)))){
             return false;
         }
         for(int i=2;i*i<n;i++){
             if(n%i==0){
                 return false;
             }
         }  
                 return true;
    }
};