#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){

    int n, l, r;
    cin >> n >> l >> r;
    int ans = 0;
    rep(i,n){
        int t;
        cin >> t;
        if(t >= l && t <= r) ans++;
    }

    cout << ans << endl;

    return 0;
}