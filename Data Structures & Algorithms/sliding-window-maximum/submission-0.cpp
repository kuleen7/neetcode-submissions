class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ans;

        for(int i=0; i<nums.size()-k+1; i++){
            int m=INT_MIN;
            for(int j=i; j<k+i; j++){
                if(nums[j] > m) m=nums[j];
            }
            ans.push_back(m);
        }
        return ans;
    }
};