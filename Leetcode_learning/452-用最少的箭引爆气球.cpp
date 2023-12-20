/*
 * @Description: 和435题类似，这里需要求出的是无重叠区间的数量，这个数量就是最少的箭数
 */

class Solution {
public:
    static bool cmp(vector<int> &a, vector<int> &b){
        return a[1]<b[1];
    }
    int findMinArrowShots(vector<vector<int>>& points) {
        if(points.size()==0) return 0;
        sort(points.begin(), points.end(), cmp);
        
        int count = 1;
        int x_end = points[0][1];
        for(auto point:points){
            if(point[0]>x_end){
                count++;
                x_end = point[1];
            }
        }
        return count;
    }
};