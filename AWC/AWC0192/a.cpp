#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){
    
    ll n, a, b;
    cin >> n >> a >> b;
    rep(i,n){
        cout << a << endl;
        a += b;
    }

    return 0;
}