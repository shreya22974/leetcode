class Solution {
public:
     multiset<int> low, high;
    long long sumLow = 0, sumHigh = 0;

    void balance() {
        while (low.size() > high.size() + 1) {
            int val = *low.rbegin();

            low.erase(low.find(val));
            sumLow -= val;

            high.insert(val);
            sumHigh += val;
        }

        while (low.size() < high.size()) {
            int val = *high.begin();

            high.erase(high.find(val));
            sumHigh -= val;

            low.insert(val);
            sumLow += val;
        }
    }

    void add(int val) {
        if (low.empty() || val <= *low.rbegin()) {
            low.insert(val);
            sumLow += val;
        } else {
            high.insert(val);
            sumHigh += val;
        }

        balance();
    }

    void remove(int val) {
        auto it = low.find(val);

        if (it != low.end()) {
            low.erase(it);
            sumLow -= val;
        } else {
            it = high.find(val);

            high.erase(it);
            sumHigh -= val;
        }

        balance();
    }

    long long getCost() {
        long long median = *low.rbegin();

        return median * low.size() - sumLow
             + sumHigh - median * high.size();
    }

    vector<long long> cost;
    vector<vector<long long>> dp;

long long solve(int i, int k, int n, int x) {

    if (k == 0) {
        return 0;
    }

    // Not enough elements to select k windows
    if (i + (long long)k * x > n) {
        return 1e18;
    }

    if (i >= cost.size()) {
        return 1e18;
    }

    if (dp[i][k] != -1) {
        return dp[i][k];
    }

    // Skip current window
    long long skip = solve(i + 1, k, n, x);

    // Take current window
    long long take = cost[i] +
                     solve(i + x, k - 1, n, x);

    return dp[i][k] = min(skip, take);
}
    long long minOperations(vector<int>& nums, int x, int k) {
    low.clear();
    high.clear();

    sumLow = 0;
    sumHigh = 0;

    cost.clear();

             int n = nums.size();


        for (int i = 0; i < x; i++) {
            add(nums[i]);
        }

        cost.push_back(getCost());

        for (int i = x; i < n; i++) {
            remove(nums[i - x]);
            add(nums[i]);

            cost.push_back(getCost());
        }

        dp.assign(n + 1, vector<long long>(k + 1, -1));

        return solve(0, k, n, x);
    }
};