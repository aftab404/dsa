class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char,int> bf;
        for(char c: s){
            bf[c]++;
        }
        for(char c: t){
            bf[c]--;
        }

        for(auto [c,i]: bf){
            if (i != 0) return false;
        }
        return true;
    }
};
