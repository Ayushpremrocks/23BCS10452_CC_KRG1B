// Brute Force

class SolutionBrute {
public:
    int nthMagicalNumber(int n, int a, int b) {
        long long mod = 1e9+7;
        long long count = 0;
        long long num = 1;

        while(count < n){
            if(num % a == 0 || num % b == 0){
                count++;
            }
            num++;
        }

        return (num - 1) % mod;
    }
};

// Optimal Approach

class SolutionOptimal {
public:
    long long gcd(long long a, long long b){
        while(b){
            a %= b;
            swap(a,b);
        }
        return a;
    }

    int nthMagicalNumber(int n, int a, int b) {
        long long mod = 1e9+7;

        long long g = gcd(a,b);
        long long lcm = (1LL * a * b) / g;

        long long low = 1;
        long long high = 1LL * n * min(a,b);
        long long ans = 0;

        while(low <= high){
            long long mid = low + (high - low) / 2;

            long long cnt = mid/a + mid/b - mid/lcm;

            if(cnt >= n){
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        return ans % mod;
    }
};
