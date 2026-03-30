class Solution {
public:
    bool isAnagram(string s, string t){
        unordered_map<char,int> bf;
        for(char c: s){
            bf[c]++;
        }
        for(char c: t){
            bf[c]--;
        }
        for(auto [c,i]: bf){
            if(i != 0) return false;
        }

        return true;
    }

    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> res;
        vector<string> checked = {};

        for(int i = 0; i<strs.size(); i++){
            if(find(checked.begin(), checked.end(), strs[i]) == checked.end()){
                vector<string> int_res;
                int_res.push_back(strs[i]);
                checked.push_back(strs[i]);
                for(int j = i + 1; j < strs.size(); j++){
                    if(isAnagram(strs[i],strs[j])){
                        int_res.push_back(strs[j]);
                        checked.push_back(strs[j]);
                    }
                }
                res.push_back(int_res);
            }
        }

        return res;
    }
};
