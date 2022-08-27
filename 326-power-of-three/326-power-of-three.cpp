class Solution {
public:
     bool Powerofthree(int n){
         int answer=0;
         for(int i=0;i<=19;i++){
             answer = pow(3,i);
             if(n==answer){
                 return true;
             }
         }
         return false;
         
     }
    bool isPowerOfThree(int n) {
        return Powerofthree(n);
    }
};