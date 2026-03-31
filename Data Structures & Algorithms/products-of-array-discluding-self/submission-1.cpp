class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> prefix(n,1);
        vector<int> suffix(n,1);

        prefix[1] = nums[0];

        for(int i = 2; i<n; i++){
            prefix[i] = prefix[i-1] * nums[i-1];
        }

        suffix[n-2] = nums[n-1];

        for(int i = n-3; i>=0; i--){
            suffix[i] = suffix[i+1] * nums[i+1];
        }

        vector<int> res(n,1);

        for(int i = 0; i<n; i++){
            res[i] = prefix[i] * suffix[i];
        }

        return res;

    }
};