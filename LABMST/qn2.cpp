#include <bits/stdc++.h>
using namespace std;

int solve(vector<string>& words){
    vector<int>a(words.size(),0);
    for(int i=0;i<words.size();i++){
        for(auto it: words[i]){
            a[i]|=(1<<(it-'a'));
        }
    }
    int res=0;
    for(int i=0;i<words.size();i++){
        for(int j=i+1;j<words.size();j++){
            if((a[i]&a[j])==0){
                res=max(res,(int)words[i].size()*(int)words[j].size());
            }
        }
    }
    return res;
}


int main() {
    vector<string>words = {"abcd","bcz","foo","xtfn","abcdef"};
    cout<<solve(words)<<endl;
}
