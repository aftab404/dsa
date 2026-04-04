class Solution {
public:
    int findMin(vector<int> &nums) {
        int left = 0;
        int right = nums.size() - 1;

        while(left <= right){
            int mid = left + ((right - left) / 2);
            if(nums[left] < nums[mid] && nums[mid] < nums[right]){
                return nums[left];
            }
            if(nums[left] < nums[mid]){
                left = mid;
            }else if(nums[right] > nums[mid]){
                right = mid;
            }else {
                return min(nums[left], nums[right]); 
            }
        }
        return 0;
    }
};

