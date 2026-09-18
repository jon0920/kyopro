#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < n; i++)
using ll = long long;

int main() {
    
    int n, k, x;
    cin >> n >> k >> x;
    vector<int> a(n);
    rep(i,n) cin >> a[i];

    vector<int> ans;
    bool flag = true;
    rep(i,n){
        if(i != k) ans.push_back(a[i]);
        else if(k != -1){
            k = -1;
            ans.push_back(x);
            i--;
        }
    }
    if(k != -1) ans.push_back(x); 
    rep(i,n+1) cout << ans[i] << " ";
    cout << endl;
    
    return 0;
}