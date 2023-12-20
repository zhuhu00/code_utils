class Solution {
public:
    int minMoves(int target, int maxDoubles) {
        // 思路：target如果是单数，则最后一次肯定是加，如果是偶数，则为了获得最小行动次数，
        // 则最后一次肯定是加倍，之后就是递归的思路进行，直到加倍次数达到限制，之前的都是加法。
        int res;//最终次数

        if(target==1) return 0;
        if(maxDoubles==0) return target-1;
        while(maxDoubles!=0&&target!=1){
            if(target%2 ==1) {
                target-=1; res++;
            }
            target>>=1;res++;maxDoubles--;//右移一位，偶数的话，右移一位刚好是减半
        }
        return res+target-1;

    }
};
