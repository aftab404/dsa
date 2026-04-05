class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        for(int i: nums){
            mp[i]++;
        }

        vector<pair<int,int>> int_res;
        for(auto [k,v]: mp){
            int_res.push_back({v,k});
        }

        sort(int_res.rbegin(), int_res.rend());

        vector<int> res;

        for(int i = 0; i<k; i++){
            res.push_back(int_res[i].second);
        }

        return res;
    }
};
