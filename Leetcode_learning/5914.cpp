class Solution {
public:
    int smallestEqual(vector<int>& nums) {
        // int minIdx=0;
        vector<int> Idxs;
        for(int i=0;i<nums.size();i++){
            if(i%10==nums[i]){Idxs.emplace_back(i);}
        }
        // while()
        return Idxs.empty() ?  -1:Idxs[0];
    }
};
