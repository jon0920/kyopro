#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){
    
    int n, q;
    cin >> n >> q;
    vector<int> s(n);
    rep(i,n) cin >> s[i];
    vector<int> imos(n + 1);
    while(q--){
        int l, r;
        cin >> l >> r;
        l--;
        imos[l]++; imos[r]--;
    }
    rep(i,n) imos[i + 1] += imos[i];

    rep(i,n){
        cout << max(0, s[i] - imos[i]) << " ";
    }
    cout << endl;
    
    return 0;
}