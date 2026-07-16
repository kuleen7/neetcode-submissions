#include<unordered_map>
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> check;
        for(auto &i:nums){
            check[i]++;
        }

        vector<vector<int>> arr;
        for(auto &[i,f]:check){
            arr.push_back({f,i});
        }

        sort(arr.rbegin(), arr.rend());

        vector<int> ans;
        for(int i=0; i<k; i++){
            ans.push_back(arr[i][1]);
        }

        return ans;
    }
};
