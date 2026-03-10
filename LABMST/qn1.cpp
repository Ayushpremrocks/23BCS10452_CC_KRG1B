#include <bits/stdc++.h>
using namespace std;
static bool cmp(vector<int>& a, vector<int>& b){
    return(b[1]-b[0])<(a[1]-a[0]);
}
int main() {
    vector<vector<int>>a = {{1,2},{2,4},{4,8}};
    sort(a.begin(),a.end(),cmp);
    int currVal=0,res=0;
    for(int i=0;i<a.size();i++){
        int minVal=a[i][1];
        int actualVal = a[i][0];
        if(currVal<minVal){
            res+=minVal-currVal;
            currVal=minVal;
        }
        currVal-=actualVal;
    }
    cout<<res<<endl;
}
