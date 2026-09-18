#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < n; i++)
using ll = long long;

int main() {
    
    int n;
    cin >> n;
    vector<int> a(n);
    rep(i,n){
        cin >> a[i];
        a[i]--;
    }

    ll same = 0;
    rep(i,n) if(a[i] == i) same++;
    ll ans = 0;
    rep(i,n){
        if(a[i] > i){
            if(i == a[a[i]]) ans++;
        }
    }

    ans += same * (same - 1) / 2;
    cout << ans << endl;
    
    return 0;
}