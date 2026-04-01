class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
       sort(nums.begin(), nums.end());
       vector<vector<int>> res;

       for(int i = 1; i<=nums.size() -2; i++){
        int p1 = 0;
        int p2 = nums.size() - 1;
        while(p1 < i && p2 > i){
            int sum = nums[p1] + nums[i] + nums[p2] ;
            if(sum > 0){
                p2--;
            }else if(sum < 0){
                p1++;
            }
            else if(sum == 0){
                vector<int> triplet = {nums[p1], nums[i], nums[p2]};
                if(find(res.begin(), res.end(), triplet) == res.end()){
                 res.push_back({nums[p1], nums[i], nums[p2]});
                }
                p1++;
            }
        }

       }

       return res;
    }
};
