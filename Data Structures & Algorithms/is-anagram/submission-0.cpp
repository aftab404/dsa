class Solution {
public:
    bool isAnagram(string s, string t) {
       unordered_map<char,int> rec;
       for(char c: s){
        rec[c]++;
       } 
       for(char c: t){
        rec[c]--;
       }

       for(auto [k,v]: rec){
        if(v != 0){
            return false;
        }
       }

       return true;
    }
};
