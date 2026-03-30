class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> copy = nums;
        vector<int> res;

        for(auto i = copy.begin(); i != copy.end(); i++) {
            copy.erase(i);
            int product = 1;
            for(int j: copy){
                product *= j;
            }
            res.push_back(product);
            copy = nums;
        }

        return res;

    }
};
