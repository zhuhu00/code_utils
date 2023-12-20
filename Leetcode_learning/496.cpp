// 下一个更大元素1，这道题虽然提供了两个数组，但是不影响。
// 首先在第二个向量中进行处理，得到单调栈，然后得到第二个向量中的下一个最大元素的数组mp,这里用unordered_map表示
// 之后在mp中寻找对应的num1的值，找的函数是用count，找到则放入ans中，之后返回就可以了。
class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans(nums1.size());
        unordered_map<int,int> mp;
        stack<int> res;
        for(int i=nums2.size()-1;i>=0;i--){
            while(!res.empty()&&nums2[i]>=res.top()){
                // mp[res.top()] = nums2[i];
                res.pop();
            }
            mp[nums2[i]] = res.empty()?-1:res.top();
            res.push(nums2[i]);
        }

        for(int i=0;i<nums1.size();i++){
            if(mp.count(nums1[i])){
                ans[i]=mp[nums1[i]];
            }
        }
        return ans;
    }
};