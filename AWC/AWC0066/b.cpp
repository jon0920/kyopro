#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){

    int n, l, k, y;
    cin >> n >> l >> k >> y;
    int ans = 0;
    int cnt = 0;
    rep(i,n){
        int a;
        cin >> a;
        if(a <= l) continue;
        if(a - y <= l) cnt++;
        else ans++;
    }

    cout << ans + min(cnt, k) << endl;

    return 0;
}