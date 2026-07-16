class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> prefix(nums.size(),0);
        vector<int> postfix(nums.size(),0);

        for(int i=0; i<nums.size(); i++){
            if(i==0) {prefix[i] = nums[i];}
            else{
                prefix[i] = prefix[i-1]* nums[i];
            }
        }

        for(int i=nums.size()-1; i>=0; i--){
            if(i==nums.size()-1) {postfix[i] = nums[i];}
            else{
                postfix[i] = postfix[i+1]* nums[i];
            }
        }

        vector<int> ans(nums.size(),0);
        for(int i=0; i<nums.size(); i++){
            if(i==0) {
                ans[i] = postfix[i+1];
            }
            else if(i==nums.size()-1){ 
                ans[i] = prefix[i-1];
            }
            else{
                ans[i] = prefix[i-1]*postfix[i+1];
            }
        }

        return ans;
    }
};