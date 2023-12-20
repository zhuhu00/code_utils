class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
       int n=mat.size();
        int m=mat[0].size();
        vector<int> ans;
        for(int i=0;i<n;i++) ans.push_back(i);
        sort(ans.begin(),ans.end(),[&](const int& a,const int & b){return mat[a]==mat[b]?a<b:mat[a]<mat[b];});
        vector<int> r(ans.begin(),ans.begin()+k);
        return r;
    }
};