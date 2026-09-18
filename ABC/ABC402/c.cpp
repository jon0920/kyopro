#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < n; i++)
using ll = long long;

int main() {
    
    int n, m;
    cin >> n >> m;

    vector<vector<int>> menulist(n);
    vector<int> cnt(m);
    int ans = 0;
    rep(i,m){
        int k;
        cin >> k;
        cnt[i] = k;
        rep(j,k){
            int a;
            cin >> a;
            a--;
            menulist[a].push_back(i);
        }
    }

    rep(i,n){
        int b;
        cin >> b;
        b--;
        for(int j : menulist[b]){
            cnt[j]--;
            if(cnt[j] == 0) ans++;
        }
        cout << ans << '\n';
    }
    
    return 0;
}