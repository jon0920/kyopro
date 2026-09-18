#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){
    
    int n;
    cin >> n;
    vector<vector<int>> ans(n);
    rep(i,n){
        int k;
        cin >> k;
        rep(j,k){
            int a;
            cin >> a;
            a--;
            ans[a].push_back(i);
        }
    }

    rep(i,n){
        cout << ans[i].size() << " ";
        for(auto x : ans[i]) cout << x + 1 << " ";
        cout << endl;
    }
    
    return 0;
}