/**
 * 数组变为了循环数组，对循环数组的处理可以看作变成2n的数组，但是这个就没必要
 * 使用取余的符号进行计算，同样也能够得到循环数组的效果。

**/

class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n);
        stack<int> s;

        for(int i=2*n-1;i>=0;i--){
            //循环数组的构建，可以减少空间，
            //思想还是使用i%n，一种取余的函数
            while(!s.empty()&&nums[i%n]>=s.top()){
                s.pop();
            }
            ans[i%n] = s.empty() ? -1:s.top();
            s.push(nums[i%n]);
        }
        return ans;

    }
};