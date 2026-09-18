#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){

    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    rep(i,m){
        int l, r;
        cin >> l >> r;
        l--;
        a[l]++, a[r]--;
    }
    rep(i,n){
        if(i) a[i] += a[i - 1];
    }

    for(auto x : a) cout << x << ' ';
    cout << endl;

    return 0;
}