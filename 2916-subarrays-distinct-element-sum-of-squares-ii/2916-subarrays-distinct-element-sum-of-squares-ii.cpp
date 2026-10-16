class Solution {
    static const int MOD = 1e9 + 7;
    
    vector<long long> sumSq;
    vector<long long> sumVal;
    vector<long long> lazy;
    
    void pushDown(int node, int l, int r) {
        if (lazy[node] != 0) {
            int mid = (l + r) / 2;
            apply(2 * node, l, mid, lazy[node]);
            apply(2 * node + 1, mid + 1, r, lazy[node]);
            lazy[node] = 0;
        }
    }
    
    void apply(int node, int l, int r, long long val) {
        long long len = (r - l + 1);
        // (x + val)^2 = x^2 + 2 * val * x + val^2 * len
        sumSq[node] = (sumSq[node] + 2 * val * sumVal[node] % MOD + val * val % MOD * len % MOD) % MOD;
        sumVal[node] = (sumVal[node] + val * len % MOD) % MOD;
        lazy[node] = (lazy[node] + val) % MOD;
    }
    
    void update(int node, int l, int r, int ql, int qr, long long val) {
        if (ql > r || qr < l) return;
        if (ql <= l && r <= qr) {
            apply(node, l, r, val);
            return;
        }
        pushDown(node, l, r);
        int mid = (l + r) / 2;
        update(2 * node, l, mid, ql, qr, val);
        update(2 * node + 1, mid + 1, r, ql, qr, val);
        sumSq[node] = (sumSq[2 * node] + sumSq[2 * node + 1]) % MOD;
        sumVal[node] = (sumVal[2 * node] + sumVal[2 * node + 1]) % MOD;
    }

public:
    int sumCounts(vector<int>& nums) {
        int n = nums.size();
        sumSq.assign(4 * n, 0);
        sumVal.assign(4 * n, 0);
        lazy.assign(4 * n, 0);
        
        unordered_map<int, int> lastPos;
        long long totalSum = 0;
        long long currentAns = 0;
        
        for (int j = 0; j < n; ++j) {
            int prev = lastPos.count(nums[j]) ? lastPos[nums[j]] : -1;
            // Update range [prev + 1, j] by adding 1
            update(1, 0, n - 1, prev + 1, j, 1);
            lastPos[nums[j]] = j;
            
            // sumSq[1] holds the sum of squares of distinct counts for all subarrays ending at index j
            totalSum = (totalSum + sumSq[1]) % MOD;
        }
        
        return totalSum;
    }
};