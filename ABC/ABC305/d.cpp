#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){
    
    int n;
    cin >> n;
    vector<ll> a(n);
    rep(i,n) cin >> a[i];
    vector<ll> sum(n);
    for(int i = 1; i < n; i++){
        if(i % 2 == 1){
            sum[i] = sum[i - 1];
        } else {
            sum[i] = sum[i - 1] + (a[i] - a[i - 1]);
        }
    }

    int q;
    cin >> q;
    while(q--){
        ll l, r;
        cin >> l >> r;
        ll res = 0;
        int left = lower_bound(a.begin(), a.end(), l) - a.begin();
        int right = upper_bound(a.begin(), a.end(), r) - a.begin();
        right--;
        if(left % 2 == 0) res += a[left] - l;
        if(right % 2 == 1) res += r - a[right];
        res += sum[right] - sum[left];
        cout << res << endl;
    }
    
    return 0;
}