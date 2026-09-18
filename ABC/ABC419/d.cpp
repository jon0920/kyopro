#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){
    
    int n, m;
    cin >> n >> m;
    string s, t;
    cin >> s >> t;
    vector<int> imos(n + 1);
    rep(i,m){
        int l, r;
        cin >> l >> r;
        l--;
        imos[l]++;
        imos[r]--;
    }
    rep(i,n) imos[i + 1] += imos[i];

    rep(i,n){
        if(imos[i] % 2 == 1) cout << t[i];
        else cout << s[i];
    }
    cout << endl;
    
    return 0;
}