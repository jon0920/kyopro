#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){

    int n;
    cin >> n;
    deque<ll> dq;
    rep(i,n){
        ll a;
        cin >> a;
        dq.push_back(a);
    }

    ll t = 0, a = 0;
    rep(i,n){
        ll p;
        if(dq.front() > dq.back()){
            p = dq.front();
            dq.pop_front();
        } else {
            p = dq.back();
            dq.pop_back();
        }

        if(i % 2 == 0) t += p;
        else a += p;
    }

    cout << t << " " << a << endl;

    return 0;
}