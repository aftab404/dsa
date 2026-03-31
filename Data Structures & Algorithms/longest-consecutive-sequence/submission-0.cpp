class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.empty()) return 0;
        unordered_map<int, vector<int>> union_find;
        unordered_set<int> quick_find_buffer;

        for(int i: nums){
            quick_find_buffer.insert(i);
        }

        for(int i: nums){
            if(quick_find_buffer.find(i-1) == quick_find_buffer.end()){
                union_find[i] = {};
            }
        }

        int res = 0;

        for(auto [root, children]: union_find){
            int offset = 1;
            auto successor = quick_find_buffer.find(root + offset);
            while(successor != quick_find_buffer.end()){
                union_find[root].push_back(*successor);
                offset++;
                successor = quick_find_buffer.find(root + offset);
            }
            int curr_size = union_find[root].size() + 1;
            res = max(res, curr_size);
        }

        return res;
        
    }
};