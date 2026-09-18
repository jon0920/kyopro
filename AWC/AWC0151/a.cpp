#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){
    
    ll n, m, k;
    cin >> n >> m >> k;
    ll rem = n * k;
    rep(i,m){
        ll a;
        cin >> a;
        rem -= a;
        if(rem < 0){
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;
    
    return 0;
}