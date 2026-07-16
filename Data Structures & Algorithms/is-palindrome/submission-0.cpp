class Solution {
public:
    bool isPalindrome(string s) {
        string res;
        for(auto &i:s){
            if(isalnum(i)){
                res+= tolower(i);
            }
        }
        if(res.size()==0){
            return true;
        }
        int i=0, j=res.size()-1;
        while(i<j){
            if(res[i]==res[j]){
                i++;
                j--;
            }
            else{
                return false;
            }
        }
        return true;
    }
};