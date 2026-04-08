class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int l = 0;
        int r = n - 1;

        while(l<r){
            int m = l + (r-l)/2;

            if(nums[m] > nums[r]){
                l = m + 1;

            }else {
                r = m;
            }

        }

        if(target >= nums[0] && target <= nums[l-1]){
            auto res = lower_bound(nums.begin(), nums.begin() + l - 1, target);
            if(*res == target) return res - nums.begin() ; else return -1;
        }else{
            auto res = lower_bound(nums.begin() + l, nums.end(), target);
            if(*res == target) return res - nums.begin(); else return -1;
        }
    }
};
