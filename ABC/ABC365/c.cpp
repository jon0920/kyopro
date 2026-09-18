#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < n; i++)
using ll = long long;

int main() {
    
    int n;
    ll m;
    cin >> n >> m;
    vector<int> a(n);
    ll sum = 0;
    rep(i,n){
       cin >> a[i];
       sum += a[i];
    }

    if(sum <= m){
        cout << "infinite" << endl;
        return 0;
    }

    int target = 0, mx = 1e9;
    while(abs(target - mx) > 1){
        int mid = (target + mx) / 2;
        ll tmp = 0;
        for(auto x : a){
            tmp += min(x, mid);
        }
        if(tmp <= m) target = mid;
        else mx = mid; 
    }

    cout << target << endl;
    
    return 0;
}