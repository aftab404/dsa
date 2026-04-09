class Solution {
public:
    int maxArea(vector<int>& heights) {
        int n = heights.size();
        int left = 0;
        int right = n - 1;

        int res = 0;

        while(left < right){
            int water = (right-left) * min(heights[right], heights[left]); 
            res = max(res, water);
            if(heights[left] < heights[right]){
                left++;
            }else {
                right--;
            }
        }


        return res;

    }
};;
