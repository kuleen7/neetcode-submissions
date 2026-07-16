#include<string>
class Solution {
public:

    string encode(vector<string>& strs) {
        string s;
        for(auto&i:strs){
            int x = i.size();
            s+=to_string(x)+"#"+i;
        }
        return s;
    }

    vector<string> decode(string s) {
        vector<string> str;

        int i=0;
        while(i<s.size()){
            int j=i;
            while(s[j]!='#'){
                j++;
            }
            int x = stoi(s.substr(i,j-i));
            i = j+1;
            str.push_back(s.substr(i,x));
            i += x;
        }

        return str;
    }
};
