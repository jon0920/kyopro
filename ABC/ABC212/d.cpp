#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){

    int q;
    cin >> q;

    priority_queue<ll, vector<ll>, greater<ll>> pq;
    ll sum = 0;
    while(q--){
        int p;
        cin >> p;
        if(p == 1){
            ll x;
            cin >> x;
            pq.push(x - sum);
        } else if(p == 2){
            ll x;
            cin >> x;
            sum += x;
        } else {
            cout << pq.top() + sum << endl;
            pq.pop();
        }
    }

    return 0;
}