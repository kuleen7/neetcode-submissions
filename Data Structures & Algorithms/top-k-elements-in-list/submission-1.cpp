class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> count;
        for(auto &i:nums){
            count[i]++;
        }

        vector<vector<int>> temp;
        for(auto &[v,f]:count){
            temp.push_back({f,v});
        }

        vector<int> ans;
        sort(temp.rbegin(), temp.rend());
        for(int i=0; i<k; i++){
            ans.push_back(temp[i][1]);
        }

        return ans;
    }
};
