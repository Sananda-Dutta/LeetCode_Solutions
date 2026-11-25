class Solution {
public:
    int smallestUniqueSubarray(vector<int>& nums) {
        int n = nums.size();

        vector<int> sa(n), r(n), nr(n);
        iota(sa.begin(), sa.end(), 0);

        sort(sa.begin(), sa.end(), [&](int a, int b) {
            return nums[a] < nums[b];
        });

        for (int i = 0; i < n; i++) {
            r[sa[i]] = (i > 0 && nums[sa[i]] == nums[sa[i-1]])
                       ? r[sa[i-1]] : i;
        }

        for (int k = 1; k < n; k *= 2) {
            sort(sa.begin(), sa.end(), [&](int a, int b) {
                if (r[a] != r[b]) return r[a] < r[b];

                int x = a + k < n ? r[a+k] : -1;
                int y = b + k < n ? r[b+k] : -1;

                return x < y;
            });

            nr[sa[0]] = 0;

            for (int i = 1; i < n; i++) {
                int a = sa[i-1], b = sa[i];

                int x = a+k < n ? r[a+k] : -1;
                int y = b+k < n ? r[b+k] : -1;

                nr[b] = nr[a] + (r[a] != r[b] || x != y);
            }

            r = nr;

            if (r[sa[n-1]] == n-1) break;
        }

        vector<int> pos(n), lcp(n, 0);

        for (int i = 0; i < n; i++)
            pos[sa[i]] = i;

        int h = 0;

        for (int i = 0; i < n; i++) {
            int p = pos[i];

            if (p == 0) continue;

            int j = sa[p-1];

            while (i+h < n && j+h < n &&
                   nums[i+h] == nums[j+h])
                h++;

            lcp[p] = h;

            if (h > 0) h--;
        }

        int ans = n;

        for (int i = 0; i < n; i++) {
            int common = 0;

            if (pos[i] > 0)
                common = max(common, lcp[pos[i]]);

            if (pos[i] + 1 < n)
                common = max(common, lcp[pos[i]+1]);

            int len = common + 1;

            if (len <= n-i)
                ans = min(ans, len);
        }

        return ans;
    }
};