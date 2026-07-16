class Solution {
public:
    int maxArea(vector<int>& height) {
        int maxArea=0;
        int i=0, j = height.size()-1;
        while(i<j){
            int b = min(height[i],height[j]);
            int l = j-i;
            int area = l*b;
            if(area>maxArea){
                maxArea = area;
            }
            else{
                if(height[i] > height[j]) j--;
                else i++;
            }

        }
        return maxArea;
    }
};