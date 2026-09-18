#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){
    
    ll n, w;
    cin >> n >> w;
    rep(i,n){
        ll v;
        cin >> v;
        if(v <= w){
            w += v;
        }
    }
    cout << w << endl;
    
    return 0;
}