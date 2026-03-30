class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> bf;
        for(int i: nums){
            bf[i]++;
        }

        vector<pair<int,int>> int_res;

        for(auto [i,j]: bf){
            int_res.push_back({i,j});
        }

        sort(int_res.begin(), int_res.end(), [](pair<int,int> a, pair<int,int> b) {
           return a.second > b.second;
        });

        vector<int> res;

        for(int i = 0; i < k; i++){
            res.push_back(int_res[i].first);
        }

        return res;
     
    }
};
