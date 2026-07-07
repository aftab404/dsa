class Solution {
   public:
    int maxProfit(vector<int>& A) {
        int n = A.size();
        int ptr1 = 0;
        int ptr2 = 1;

        int res = 0;

        while (ptr1 <= ptr2 && ptr2 < n) {
            if (A[ptr2] < A[ptr1]) {
                ptr1++;
            } else {
                res = max(res, A[ptr2] - A[ptr1]);
                ptr2++;
            }
        }

        return res;
    }
};
