#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){

    int n;
    cin >> n;
    ll sum = 0;
    rep(i,n){
        ll a;
        cin >> a;
        sum += a;
    }

    if(sum % 2 == 1) cout << "Takahashi" << endl;
    else cout << "Aoki" << endl;

    return 0;
}