class Solution {
public:   
    
    void reverseS(vector<char>& s,int start,int end){
          
        
           if(start>=end){
                return;
           }
          
        
           int temp = s[start];
           s[start] = s[end];
           s[end] = temp;
        
        reverseS(s,start+1,end-1);
    }
     
    
    void reverseString(vector<char>& s) {
            
           
            reverseS(s,0,s.size()-1);
           
    }
};