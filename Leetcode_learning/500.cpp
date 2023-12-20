# 字典
class Solution {
public:
    vector<string> findWords(vector<string>& words) {
        vector<string> ans;
        string rowInx = "12210111011122000010020202";
        for(auto & word : words){
            bool isValid = true;
            char idx= rowInx[tolower(word[0])-'a'];
            for(int i = 1; i< word.size();i++){
                if(rowInx[tolower(word[i])-'a']!=idx){
                    isValid = false;
                    break;
                }

            }
            if(isValid){
                ans.emplace_back(word);
            }
        }
        return ans;
    }
    
};
