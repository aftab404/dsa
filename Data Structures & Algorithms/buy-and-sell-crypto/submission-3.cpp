class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int l = 0;
        int r = n -1;

        int ptr1 = 0;
        int ptr2 = n -1;

        int res = 0;

       int prev_ptr1 = ptr1;
int prev_ptr2 = ptr2;

while(ptr1 < ptr2){
    res = max(prices[r]- prices[l],res);

    prev_ptr1 = ptr1;
    while(ptr1 < r - 1 && prices[l] <= prices[ptr1]){
        ptr1++;
    }
    if(prices[ptr1] < prices[l]) l = ptr1;

    res = max(prices[r]- prices[l],res);

    prev_ptr2 = ptr2;
    while(l + 1 < ptr2 && prices[r] >= prices[ptr2]){
        ptr2--;
    }
    if(prices[ptr2] > prices[r]) r = ptr2;

    res = max(prices[r]- prices[l],res);

    // 🔥 minimal safety fix
    if (ptr1 == prev_ptr1 && ptr2 == prev_ptr2) {
        ptr1++;  // or ptr2--
    }
}

        return res;
    }
};
