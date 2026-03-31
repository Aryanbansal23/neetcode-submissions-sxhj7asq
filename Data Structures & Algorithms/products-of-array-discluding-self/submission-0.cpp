class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> p(n);  
        int t = 1;
        int zeroCount = 0;
        for (int i = 0; i < n; i++) {
            if (nums[i] != 0) {
                t *= nums[i];
            } else {
                zeroCount++;
            }
        }
        if (zeroCount > 1) {
            return vector<int>(n, 0);
        }
        for (int i = 0; i < n; i++) {
            if (nums[i] == 0) {
                p[i] = t;  
            } else if (zeroCount == 0) {
                p[i] = t / nums[i]; 
            } else {
                p[i] = 0;  
            }
        }

        return p;
    }
};
