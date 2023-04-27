class Solution {
public:
    int bulbSwitch(int n) {
        if(n==0)return 0;
        else
        {
            int cont=1,cont2=3;
            for(int i = cont2 ; i < n ;i+=cont2){cont++;cont2+=2;}
            return cont;
        }
    }
};