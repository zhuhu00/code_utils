class Solution {
public:
    int reverse(int x) {
        int res=0;
        while(x!=0){
            if(res<INT_MIN / 10 || res>INT_MAX/10) {return 0;}
            int digit = x%10;
            x/=10;
            res = res*10+digit;

        }
        return res;
    }
};
