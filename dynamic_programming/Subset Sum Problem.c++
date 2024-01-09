class Solution {
public:
    int algo(int i, int sum, vector<int>& arr, vector<vector<int>>& dp) {
        if (sum == 0) {
            return 1;  
        }
        if (sum < 0 || i >= arr.size()) {
            return 0;  
        }
        if (dp[sum][i] != -1) {
            return dp[sum][i];
        }
        int taken = algo(i + 1, sum - arr[i], arr, dp);
        int nottaken = algo(i + 1, sum, arr, dp);
        return dp[sum][i] = taken || nottaken;
    }

    bool isSubsetSum(vector<int> arr, int sum) {
        int all_sum = 0;
        for (int i = 0; i < arr.size(); i++) {
            all_sum += arr[i];
        }
        vector<vector<int>> dp(sum + 1, vector<int>(arr.size() + 1, -1));
        return algo(0, sum, arr, dp);
    }
};
// time complexity o(sum*n)
// space complexity o(sum*n)