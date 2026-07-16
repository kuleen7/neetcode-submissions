#include<unordered_set>
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size()==0){
            return 0;
        }

        unordered_set<int> check;
        for(auto &i:nums){
            check.insert(i);
        }

        int len=0;

        for(int i=0; i<nums.size(); i++){
            if(check.count(nums[i]-1)){
                continue;
            }
            int val = nums[i];
            int longest=1;
            while(check.count(val+1)){
                val++;
                longest++;
            }

            len= max(len,longest);
        }

        return len;
    }
};