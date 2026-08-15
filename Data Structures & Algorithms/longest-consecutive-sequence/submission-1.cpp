class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> check;
        for(auto &i:nums){
            check.insert(i);
        }
        int longest=0;

        for(int i=0; i<nums.size(); i++){
            if(check.count(nums[i]-1)) continue;

            int x= nums[i];
            int len=1;
            while(check.count(x+1)){
                x++;
                len++;
            }
            longest = max(len,longest);
        }
        return longest;
    }
};
