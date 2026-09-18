#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){

    int n, s, t;
    cin >> n >> s >> t;
    int ans = 0;
    rep(i,n){
        int a;
        cin >> a;
        if(abs(a-s) <= t) ans++;
    }
    cout << ans << endl;

    return 0;
}