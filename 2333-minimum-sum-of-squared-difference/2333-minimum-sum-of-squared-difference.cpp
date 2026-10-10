
class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2) {
        vector<int> diff(nums1.size());
        long long k = (long long)k1 + k2;
        int mx = 0;

        for (int i = 0; i < nums1.size(); i++) {
            diff[i] = abs(nums1[i] - nums2[i]);
            mx = max(mx, diff[i]);
        }

        long long total = 0;
        for (int d : diff) total += d;

        if (k >= total) return 0;

        int left = 0, right = mx;

        while (left < right) {
            int mid = left + (right - left) / 2;
            long long need = 0;

            for (int d : diff) {
                if (d > mid) need += d - mid;
            }

            if (need <= k)
                right = mid;
            else
                left = mid + 1;
        }

        int level = left;
        long long ans = 0;

        for (int d : diff) {
            if (d > level) {
                long long x = level;
                ans += x * x;
                k -= d - level;
            } else {
                ans += 1LL * d * d;
            }
        }

        for (int i = 0; i < diff.size() && k > 0; i++) {
            if (diff[i] >= level && level > 0) {
                ans -= 1LL * level * level;
                ans += 1LL * (level - 1) * (level - 1);
                k--;
            }
        }

        return ans;
    }
};
