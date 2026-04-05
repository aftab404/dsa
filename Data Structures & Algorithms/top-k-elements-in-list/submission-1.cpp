class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        for(int i: nums){
            mp[i]++;
        }

        vector<pair<int,int>> int_res;
        for(auto p: mp){
            int_res.push_back(p);
        }

        sort(int_res.begin(), int_res.end(), [](auto a, auto b){
            return a.second > b.second;
        });

        vector<int> res;

        for(int i = 0; i<k; i++){
            res.push_back(int_res[i].first);
        }

        return res;
    }
};
