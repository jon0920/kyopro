#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){
    
    ll s, p, r;
    cin >> s >> p >> r;
    int m;
    cin >> m;
    rep(_,m){
        ll e, v;
        cin >> e >> v;
        if(e == 1){
            s += v;
        } else {
            s -= p * v;
        }
    }

    cout << s - r << endl;
    
    return 0;
}