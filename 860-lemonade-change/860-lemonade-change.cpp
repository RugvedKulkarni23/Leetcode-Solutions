class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
          int five = 0; 
          int ten = 0;
          for(int i=0;i<bills.size();i++){
               if(bills[i]==5){
                   five++;
               }
               else if(bills[i]==10){
                   if(five<1){
                       return false;
                   }
                   else{
                       ten++;
                       five--;
                   }
               }
              else{
                  if((ten==0 && five<3 ) || (five==0)){
                       return false;
                  }
                  else if(ten>0 ){
                      ten --;
                      five--;
                  }
                  else{
                      five -= 3;
                  }
              }
               
          }
        return true;
          
          
    }
};