#include<unordered_map>
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;
        unordered_map<string, vector<string>> count;

        for(auto &i:strs){
            string x= i;
            sort(i.begin(), i.end());
            count[i].push_back(x);
        }

        for(auto &[k,v]:count){
            ans.push_back(v);
        }

        return ans;
    }
};