#include<unordered_map>
class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char,int> have;
        unordered_map<char,int> need;

        for(int i=0; i<t.size(); i++){
            need[t[i]]+=1;
        }

        int n_val = need.size();
    
        int l=0;
        int curr=0;
        pair<int,int> res={-1,-1};
        int len= INT_MAX;

        for(int r=0; r<s.size(); r++){
            have[s[r]]++;
            if(need.count(s[r]) && have[s[r]]==need[s[r]]){
                curr++;
            }

            while(curr==n_val){
                if(r-l+1 < len){
                    len = r-l+1;
                    res={l,r};
                }
                have[s[l]]--;
                if(need.count(s[l]) && have[s[l]] < need[s[l]]){
                    curr--;
                }
                l++;
            }
        }
        if(len!=INT_MAX){
            return s.substr(res.first,len);
        }
        else{
            return "";
        }

    }
};