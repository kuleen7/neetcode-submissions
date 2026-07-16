#include<vector>
#include<unordered_map>

class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length() != t.length()){
            return false;
        }
        unordered_map<char,int> sc;
        unordered_map<char,int> tc;
        for(int i=0; i<s.length(); i++){
            sc[s[i]] +=1;
            tc[t[i]] +=1;
        }

        return sc == tc;
    }
};
