// 和下一个最大数字一样，只是这里要求得是索引，而不是数字本身得值。，变形以下就好了
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> ans(temperatures.size());
        stack<int> s;//存放的是索引，而不是气温值了
        for(int i=temperatures.size()-1;i>=0;i--){
            while(!s.empty()&&temperatures[s.top()]<=temperatures[i])
            {
                s.pop();
            }
            
            ans[i] = s.empty()?0:(s.top()-i);
            s.push(i);
        }
        return ans;
    }
};