#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

set<ll> solve(){
    set<ll> res;
    for(int init = 1; init <= 9; init++){
        for(int d = -9; d <= 8; d++){
            string s;
            int digit = init;
            rep(_,18){
                s.push_back(digit + '0');
                res.insert(stoll(s));
                digit += d;
                if(digit < 0 || digit > 9) break;
            }
        }
    }
    return res;
}

int main(){

    ll x;
    cin >> x;

    set<ll> st = solve();

    cout << *st.lower_bound(x) << endl;

    return 0;
}