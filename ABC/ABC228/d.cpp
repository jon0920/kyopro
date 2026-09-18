#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)


int main(){
    
    const ll n = 1 << 20;
    vector<ll> a(n, -1);
    int q;
    cin >> q;
    while(q--){
        ll t, x;
        cin >> t >> x;
        x--;
        if(t == 1){
            ll h = x;
            while(a[h % n] != -1){
                h++;
                h %= n;
            }
            a[h % n] = x + 1;
        }
        else{
            cout << a[x % n] << endl;
        }
    }

    return 0;
}