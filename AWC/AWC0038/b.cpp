#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){

    int n, k;
    cin >> n >> k;
    vector<ll> d(n);
    ll sum = 0;
    rep(i,n){
        cin >> d[i];
        sum += d[i];
    }
    sort(d.begin(), d.end());
    rep(i,k) sum -= d[i];
    cout << sum << endl;

    return 0;
}