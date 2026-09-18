#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){

    int n;
    cin >> n;
    vector<int> a(n);
    vector<vector<int>> G(n);
    rep(i,n){
        cin >> a[i];
        a[i]--;
        G[a[i]].push_back(i);
    }

    vector<int> ans(n, -1);
    queue<int> que;
    for(int i = n - 1; i >= 0; i--){
        if(ans[i] == -1) que.push(i);
        while(!que.empty()){
            int v = que.front(); que.pop();
            for(auto nv : G[v]){
                if(ans[nv] == -1){
                    ans[nv] = i;
                    que.push(nv);
                }
            }
        }
    }
    for(auto x : ans) cout << x + 1 << " ";
    cout << endl;
    return 0;
}