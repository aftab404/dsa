class Solution {
public:
    string filter_alnum(string s){
        string res = "";
        for(char c: s){
            if(isalnum(c)){
                res += tolower(c);
            }
        }
        return res;
    }

    bool isPalindrome(string s) {
        string filtered_string = filter_alnum(s);
       int half = filtered_string.size() / 2;
       for(int i = 0; i < half; i++){
        if(filtered_string[i] != filtered_string[filtered_string.size() - 1 -i]){
            return false;
        }
       } 
        return true;
    }
};
