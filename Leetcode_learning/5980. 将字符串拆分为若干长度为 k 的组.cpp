class Solution {
public:
    vector<string> divideString(string s, int k, char fill) {
        vector<string> res;
        int n = s.size();
        for(int i=0;i<s.size();i+=k){
            res.emplace_back(s.substr(i,k));
        }
        if(n%k ==0){
            return res;
        }
        else{
            res.back() +=string(k-n%k,fill);
            return res;
        }

    }
};
