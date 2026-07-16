#include<unordered_map>
class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        unordered_map<char,int> count;
        for(int i=0; i<s1.size(); i++){
            count[s1[i]]++;
        }

        int len = count.size();

        for(int i=0; i<s2.size(); i++){
            unordered_map<char,int> check;
            int cur=0;
            for(int j=i; j<s2.size(); j++){
                check[s2[j]]++;
                if (check[s2[j]] > count[s2[j]]) break;
                
                if (check[s2[j]]== count[s2[j]]) cur++;

                if( len==cur) return true;

            }
        }
        return false;
    }
};