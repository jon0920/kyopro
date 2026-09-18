#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < n; i++)
using ll = long long;

int main() {
    
    ll n;
    cin >> n;
    vector<int> bi;
    while(n){
        bi.push_back(n % 2);
        n /= 2;
    }
    vector<int> pos;
    rep(i,bi.size()){
        if(bi[i] == 1) pos.push_back(i);
    }

    int m = pos.size();
    for(int bit = 0; bit < (1 << m); bit++){
        ll res = 0;
        rep(i,m){
            if((bit >> i) & 1){
                ll dig = 1LL << pos[i];
                res += dig;
            }
        }
        cout << res << endl;
    }
    
    
    return 0;
}