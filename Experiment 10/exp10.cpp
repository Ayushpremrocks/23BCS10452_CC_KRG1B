#include <bits/stdc++.h>
using namespace std;

class SegmentTree {
public:
    vector<int> seg;
    int n;

    SegmentTree(int size) {
        n = size;
        seg.resize(4 * n, 0);
    }

    void update(int idx, int low, int high, int pos) {
        if (low == high) {
            seg[idx] += 1;
            return;
        }
        int mid = (low + high) / 2;
        if (pos <= mid) update(2 * idx + 1, low, mid, pos);
        else update(2 * idx + 2, mid + 1, high, pos);
        seg[idx] = seg[2 * idx + 1] + seg[2 * idx + 2];
    }

    int query(int idx, int low, int high, int l, int r) {
        if (r < low || high < l) return 0;
        if (l <= low && high <= r) return seg[idx];
        int mid = (low + high) / 2;
        return query(2 * idx + 1, low, mid, l, r) +
               query(2 * idx + 2, mid + 1, high, l, r);
    }
};

class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        int n = nums.size();

        vector<int> sorted = nums;
        sort(sorted.begin(), sorted.end());
        sorted.erase(unique(sorted.begin(), sorted.end()), sorted.end());

        unordered_map<int, int> comp;
        for (int i = 0; i < sorted.size(); i++) {
            comp[sorted[i]] = i;
        }

        SegmentTree st(sorted.size());
        vector<int> ans(n);

        for (int i = n - 1; i >= 0; i--) {
            int idx = comp[nums[i]];
            ans[i] = st.query(0, 0, sorted.size() - 1, 0, idx - 1);
            st.update(0, 0, sorted.size() - 1, idx);
        }

        return ans;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {5,2,6,1};
    vector<int> res = sol.countSmaller(nums);

    for (int x : res) cout << x << " ";
    return 0;
}