#include <bits/stdc++.h>
using namespace std;
struct Node {
    int sum, mx, mn;
};
class SegTree {
public:
    int n;
    vector<Node> seg;
    SegTree(vector<int>& arr) {
        n = arr.size();
        seg.resize(4*n);
        build(0, 0, n-1, arr);
    }
    Node merge(Node a, Node b) {
        Node res;
        res.sum = a.sum + b.sum;
        res.mx = max(a.mx, b.mx);
        res.mn = min(a.mn, b.mn);
        return res;
    }
    void build(int idx, int l, int r, vector<int>& arr) {
        if(l == r) {
            seg[idx] = {arr[l], arr[l], arr[l]};
            return;
        }
        int mid = (l + r) / 2;
        build(2*idx+1, l, mid, arr);
        build(2*idx+2, mid+1, r, arr);
        seg[idx] = merge(seg[2*idx+1], seg[2*idx+2]);
    }
    Node query(int idx, int l, int r, int ql, int qr) {
        if(qr < l || r < ql) return {0, INT_MIN, INT_MAX};
        if(ql <= l && r <= qr) return seg[idx];
        int mid = (l + r) / 2;
        Node left = query(2*idx+1, l, mid, ql, qr);
        Node right = query(2*idx+2, mid+1, r, ql, qr);
        return merge(left, right);
    }
};
int main() {
    vector<int>arr={1,3,5,7,9,11};
    SegTree st(arr);
    int l=2,r=4;
    Node ans=st.query(0,0,arr.size()-1,l,r);
    cout<<ans.sum<<" "<<ans.mx<<" "<<ans.mn<<endl;
}