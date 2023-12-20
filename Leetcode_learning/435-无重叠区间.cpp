/**属于贪心算法的最开始。首先对区间进行排列，之后挨个去除。
 * 
 * **/ 

class Solution {
public:
    static bool cmp(const vector<int>& a, const vector<int>& b){
        return a[1]<b[1];
    }

    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        //先对区间进行升序排列
        if(intervals.size()==0) return 0;
        sort(intervals.begin(),intervals.end(),cmp);
        
        int count = 1;
        
        int x_end = intervals[0][1];

        for(auto interval: intervals){
            if(interval[0]>=x_end) {
                count++;
                x_end = interval[1];
            }
        }
        return intervals.size()-count;
    }
};