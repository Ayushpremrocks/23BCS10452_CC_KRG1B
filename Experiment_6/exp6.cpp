#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    vector<string> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];

    vector<vector<int>> adj(26);
    vector<int> indeg(26, 0);

    for(int i = 0; i < n - 1; i++){
        string s = a[i], t = a[i + 1];
        int len = min(s.size(), t.size());
        bool found = false;

        for(int j = 0; j < len; j++){
            if(s[j] != t[j]){
                adj[s[j] - 'a'].push_back(t[j] - 'a');
                found = true;
                break;
            }
        }

        if(!found && s.size() > t.size()){
            cout << "Impossible\n";
            return 0;
        }
    }

    for(int i = 0; i < 26; i++){
        for(auto v : adj[i]) indeg[v]++;
    }

    queue<int> q;
    for(int i = 0; i < 26; i++){
        if(indeg[i] == 0) q.push(i);
    }

    string res = "";

    while(!q.empty()){
        int u = q.front();
        q.pop();
        res += char(u + 'a');

        for(auto v : adj[u]){
            indeg[v]--;
            if(indeg[v] == 0) q.push(v);
        }
    }

    if(res.size() != 26){
        cout << "Impossible\n";
    } else {
        cout << res << "\n";
    }
}