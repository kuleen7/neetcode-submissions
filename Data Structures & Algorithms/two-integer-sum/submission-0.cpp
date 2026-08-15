class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> check;
        vector<int> ans;
        for(int i=0; i<nums.size(); i++){
            int diff = target-nums[i];
            if(check.count(diff)) {
                ans.push_back(check[diff]);
                ans.push_back(i);
            }
            check[nums[i]]=i;
        }

        sort(ans.begin(), ans.end());
        return ans;
    }
};
