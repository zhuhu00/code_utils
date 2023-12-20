/*
 * @Description: 贪心算法。
 */
class Solution {
public:
    bool canJump(vector<int>& nums) {
        //每次计算跳跃的最大长度，当计算了能够到达最远比数组大时，则有可能
        int n=nums.size();
        int jp_max = nums[0];
        for(int i=0;i<n;i++){
            if(i<=jp_max){//只有jp_max>i后面了，才有可能进行交换。不然就是直接jp_max会一直小于i，也就无法跳跃到后面
            jp_max = max(jp_max,i+nums[i]);}
        }
        return jp_max>=n-1;
    }
};