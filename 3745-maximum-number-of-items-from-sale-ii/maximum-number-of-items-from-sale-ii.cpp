class Solution {
public:
    int maximumSaleItems(vector<vector<int>>& items, int budget) {
        int n = items.size();

        // Step 1: Count frequency of every factor
        vector<int> freq(n + 1, 0);

        int minPrice = INT_MAX;

        for (auto &it : items) {
            freq[it[0]]++;
            minPrice = min(minPrice, it[1]);
        }

        // Step 2: Calculate how many free items each factor can give
        vector<int> gain(n + 1, 0);

        for (int i = 1; i <= n; i++) {
            for (int j = i; j <= n; j += i) {
                gain[i] += freq[j];
            }

            // Exclude the item itself
            if (gain[i] > 0) {
                gain[i]--;
            }
        }

        // Step 3: Store useful items (price, free item count)
        vector<pair<int, int>> v;

        for (auto &it : items) {
            int factor = it[0];
            int price = it[1];

            if (gain[factor] > 0 &&
                2LL * price < 2LL * minPrice * 2) {
                v.push_back({price, gain[factor]});
            }
        }

        // Step 4: Sort by price
        sort(v.begin(), v.end());

        long long ans = 0;

        // Step 5: Buy copies that provide 2 items per purchase
        for (auto &[price, cnt] : v) {

            long long buy = min((long long)cnt,
                                (long long)budget / price);

            ans += buy * 2;
            budget -= buy * price;
        }

        // Step 6: Spend remaining budget on cheapest item
        ans += budget / minPrice;

        return (int)ans;
    }
};