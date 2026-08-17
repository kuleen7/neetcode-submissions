class Solution {
public:
    int trap(vector<int>& height) {
        int maxL=INT_MIN;
        int maxR=INT_MIN;
        int l=0;
        int r=height.size()-1;
        int ans=0;

        while(l<r){
            if(height[l] > maxL) maxL = height[l];
            if(height[r] > maxR) maxR = height[r];

            if(height[l]<height[r]){
                ans+= maxL-height[l];
                l++;
            }
            else{
                ans+= maxR-height[r];
                r--;
            }        
        }
        return ans;
    }
};
