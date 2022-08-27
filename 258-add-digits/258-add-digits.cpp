class Solution {
public:
         
     int divide(int num){
             if(num<10){
                 return num;
             }
             int ans =0;
             while(num>0){
                
              
              ans += num%10;
              num = num/10;
             }
         return divide(ans);
          
     }
     
    int addDigits(int num) {
        return divide(num);
    }
};