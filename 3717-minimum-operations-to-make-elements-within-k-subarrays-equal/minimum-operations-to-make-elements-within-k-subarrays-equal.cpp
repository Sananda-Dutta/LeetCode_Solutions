
class Solution {
public:
    multiset<int> low, high;
    long long lowSum = 0, highSum = 0;
    void balance() {
        int total = low.size() + high.size();
        int target = (total + 1) / 2;

        while ((int)low.size() > target) {
            int val = *low.rbegin();

            low.erase(prev(low.end()));
            lowSum -= val;

            high.insert(val);
            highSum += val;
        }

        while ((int)low.size() < target) {
            int val = *high.begin();

            high.erase(high.begin());
            highSum -= val;

            low.insert(val);
            lowSum += val;
        }
    }

    void add(int val) {
        if (low.empty() || val <= *low.rbegin()) {
            low.insert(val);
            lowSum += val;
        }
        else {
            high.insert(val);
            highSum += val;
        }

        balance();
    }

    void remove(int val) {
        auto it = low.find(val);

        if (it != low.end()) {
            low.erase(it);
            lowSum -= val;
        }
        else {
            it = high.find(val);
            high.erase(it);
            highSum -= val;
        }

        balance();
    }

    long long getCost() {
        long long median = *low.rbegin();

        long long leftCost =
            median * (long long)low.size() - lowSum;

        long long rightCost =
            highSum - median * (long long)high.size();

        return leftCost + rightCost;
    }

    long long minOperations(vector<int>& nums, int x, int k) {
        int n = nums.size();

        // Step 1: Calculate cost of every window of size x
        vector<long long> cost;

        for (int i = 0; i < x; i++) {
            add(nums[i]);
        }

        cost.push_back(getCost());

        for (int i = x; i < n; i++) {
            remove(nums[i - x]);
            add(nums[i]);

            cost.push_back(getCost());
        }

        // Step 2: DP to select k non-overlapping windows

        int m = cost.size();

        const long long INF = LLONG_MAX / 4;

        vector<long long> prev(m + 1, 0);
        vector<long long> curr(m + 1, INF);

        for (int j = 1; j <= k; j++) {

            curr[m] = INF;

            for (int i = m - 1; i >= 0; i--) {

                long long skip = curr[i + 1];

                long long take = INF;

                int next = min(m, i + x);

                if (prev[next] != INF) {
                    take = cost[i] + prev[next];
                }

                curr[i] = min(skip, take);
            }

            prev.swap(curr);
            fill(curr.begin(), curr.end(), INF);
        }

        return prev[0];

    }
};
