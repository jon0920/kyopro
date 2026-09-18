#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){

    int n;
    cin >> n;
    ll last, ans = 0;
    rep(i,n){
        ll d;
        cin >> d;
        if(i == 0){
            ans += d;
        }
        else if(last < d){
            ans += d / 2;
        }
        else ans += d;
        last = d;
    }

    cout << ans << endl;

    return 0;
}