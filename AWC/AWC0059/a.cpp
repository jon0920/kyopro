#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){

    int n;
    cin >> n;
    vector<ll> a(n);
    rep(i,n) cin >> a[i];
    vector<bool> check(n);

    rep(i,n - 1){
        if(check[i] || check[i + 1]) continue;
        else if(a[i] == a[i + 1]) continue;
        else{
            if(a[i] > a[i + 1]){
                a[i] += a[i + 1] / 2;
                check[i + 1] = true;
            } else {
                a[i + 1] += a[i] / 2;
                check[i] = true;
            }
        }
    }

    int ans = 0;
    for(auto x : check) if(!x) ans++;
    cout << ans << endl;

    return 0;
}