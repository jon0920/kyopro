#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){

    int n, m;
    cin >> n >> m;
    vector<ll> d(n);
    rep(i,n){
        cin >> d[i];
    }
    sort(d.rbegin(), d.rend());

    if(m == n) cout << 0 << endl;
    else cout << d[m] << endl;

    return 0;
}