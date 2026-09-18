#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){
    
    int n, k;
    cin >> n >> k;
    vector<int> t(n);
    rep(i,n) cin >> t[i];
    sort(t.begin(), t.end());

    int r = 0;
    int ans = 0;
    rep(l,n){
        while(r < n && t[r] - t[l] <= k) r++;
        ans++;
        l = r - 1;
    }

    cout << ans << endl;
    
    return 0;
}