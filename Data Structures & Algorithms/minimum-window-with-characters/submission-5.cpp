class Solution {
public:
    bool containsAll(vector<int>& ct, string t){
        vector<int> lct = ct;
        for(char c: t){
            if(lct[c - 'A'] <= 0) return false;
            lct[c - 'A']--;
        }

        return true;
    }

    string minWindow(string s, string t) {
        vector<int> ct(100, 0);
        int n = s.size();
        int m = t.size();
        int l = 0;
        int r = 0;
        int res = INT_MAX;
        pair<int,int> ind(0,0);

        ct[s[0] - 'A']++;

        while(r<=n && l<=r){
            if(!containsAll(ct,t)){
                r++;
                ct[s[r] - 'A']++;
            }else {
                if(res > r-l+1){
                    res = r-l+1;
                    ind.first = l;
                }
                ct[s[l] - 'A']--;
                l++;
            }
        }

        if(res!=INT_MAX) return s.substr(ind.first, res); else return "";
    }
};
