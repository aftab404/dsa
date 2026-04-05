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
        int n = strs.size();
        vector<vector<string>> res;
        vector<bool> checked(n, false);

        for(int i = 0; i < n; i++){
            if(checked[i]) continue;
            vector<string> int_res;
            int_res.push_back(strs[i]);
            checked[i] = true;
            for(int j = i + 1; j < n; j++){
                if(checked[j]) continue;
                if(isAnagram(strs[i], strs[j])) {
                    int_res.push_back(strs[j]);
                    checked[j] = true;
                }
            }
            res.push_back(int_res);
        }

        return res;
    }
};
