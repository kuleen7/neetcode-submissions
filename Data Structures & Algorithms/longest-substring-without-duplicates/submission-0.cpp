#include<unordered_set>
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> win;
        int left=0;
        int maxlen=0;

        for(int r=0; r<s.size(); r++){
            while(win.count(s[r])){
                win.erase(s[left]);
                left++;
            }
            win.insert(s[r]);
            maxlen = max(maxlen, r-left+1);
        }
        return maxlen;
    }
};