#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){

    int n;
    cin >> n;
    ll ans = 0;
    rep(i,n){
        string t;
        int p;
        cin >> t >> p;
        if(t == "normal") ans += p;
        else ans += p / 2;
    }
    cout << ans << endl;

    return 0;
}