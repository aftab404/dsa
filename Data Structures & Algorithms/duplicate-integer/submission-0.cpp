class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_set<int> rec;
        for(int i: nums){
            rec.insert(i);
        }

        if(rec.size() != nums.size()){
            return true;
        }
         
        return false;
    }
};