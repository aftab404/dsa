class Solution {
public:
    pair<char,int> currMax(string s){
        unordered_map<char,int> mp;

        for(char c: s){
            mp[c]++;
        }

        pair<char,int> most_freq(' ', 0);
        
        for(auto [k,v]: mp){
            if(most_freq.second < v){
                most_freq.second = v;
                most_freq.first = k;
            } 
        }

        return most_freq;
    }

    int characterReplacement(string s, int k) {
        int n = s.size();
        int l = 0;
        int r = 0;
        int res = 0;

        while(l<=r && r<n){
            int ws = r-l+1;
            int fmfc = currMax(s.substr(l,ws)).second;
            if(ws-fmfc <= k){
                res = max(res,ws);
                r++;
            }else{
                l++;
            }
        }

        return res;

    }
};
