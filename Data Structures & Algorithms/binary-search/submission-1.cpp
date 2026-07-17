class Solution {
public:
    int search(vector<int>& nums, int target) {
        int i=0, j=nums.size()-1;
        while(i<=j){
            int mid = (i+j)/2;
            if(nums[mid] == target) return mid;

            else if(nums[mid] > target) j--;

            else{
                i++;
            }
        }
        return -1;
    }
};
