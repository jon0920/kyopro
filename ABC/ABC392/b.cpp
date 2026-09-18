#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < n; i++)
using ll = long long;

int main() {
    
    int n, m;
    cin >> n >> m;
    vector<int> a(m);
    rep(i,m) cin >> a[i];

    vector<int> ans;
    rep(i,n){
        bool flag = false;
        rep(j,m){
            if(a[j] == i+1) flag = true;
        }
        if(!flag) ans.push_back(i+1);
    }

    cout << ans.size() << endl;
    rep(i,ans.size()){
        cout << ans[i] << " ";
    }
    cout << endl;
    
    return 0;
}