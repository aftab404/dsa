class Solution {
public:
    int lengthOfLongestSubstring(string s) {
       unordered_set<char> st;
       int n = s.size(); 
       int l = 0;
       int r = 0;
       int res = 0;

       while(l<=r && r<n){
        char curr = s[r];
        if(st.find(curr) != st.end()){
            st.erase(curr);
            res = max(res, r-l);
            while(s[l] != curr && l < r){
                st.erase(s[l]);
                l++;
            }
            l++;
        }else{
            st.insert(curr);
            r++;
            res = max(res, r-l);
        }
       }
       return res;
    }
};
