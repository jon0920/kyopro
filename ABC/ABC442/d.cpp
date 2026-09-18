#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < n; i++)
using ll = long long;


int main() {
    
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, q;
    cin >> n >> q;
    vector<ll> a(n), sum(n + 1);
    rep(i,n){
        cin >> a[i];
        sum[i + 1] = sum[i] + a[i];
    }

    while(q--){
        int type;
        cin >> type;
        if(type == 1){
            int x;
            cin >> x;
            x--;
            swap(a[x], a[x + 1]);
            sum[x + 1] = sum[x] + a[x]; 
        }
        else{
            int l, r;
            cin >> l >> r;
            l--;
            cout << sum[r] - sum[l] << "\n";
        }
    }
    
    return 0;
}