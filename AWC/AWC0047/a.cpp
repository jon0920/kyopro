#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){

    int n, k;
    cin >> n >> k;
    int pre;
    int ans = 0;
    rep(i,n){
        int t;
        cin >> t;
        if(i && abs(pre - t) >= k) ans++;
        pre = t;
    }

    cout << ans << endl;

    return 0;
}