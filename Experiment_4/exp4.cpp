class Solution {
public:
    int countBits(int n, long long arr[]) {
        const long long mod = 1000000007;
        long long totalDiff = 0;

        for (int pos = 0; pos < 31; ++pos) {
            long long ones = 0;

            for (int j = 0; j < n; ++j) {
                if ((arr[j] >> pos) & 1)
                    ++ones;
            }

            long long zeros = n - ones;
            long long contribution = (2LL * ones * zeros) % mod;

            totalDiff = (totalDiff + contribution) % mod;
        }

        return (int)totalDiff;
    }
};
