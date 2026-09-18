#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){
    
    ll x, a, d, n;
    cin >> x >> a >> d >> n;

    if(d < 0){
        ll fi = a + d * (n - 1);
        a = fi;
        d *= -1;
    }

    ll st = a;
    ll fi = a + d * (n - 1);
    if(st <= x && x <= fi){
        ll m = (d != 0 ? (x - st) % d : 0);
        cout << min(m, d - m) << endl;
    } else if(x < st){
        cout << st - x << endl;
    } else {
        cout << x - fi << endl;
    }
    
    return 0;
}