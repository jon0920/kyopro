#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){
    
    ll n, k, p;
    cin >> n >> k >> p;
    vector<pair<ll,ll>> ba(n);
    rep(i,n){
        ll a, b;
        cin >> a >> b;
        ba[i] = {b, a};
    }
    sort(ba.begin(), ba.end());

    priority_queue<ll, vector<ll>, greater<ll>> pq;
    ll sum = 0;
    for(auto [b, a] : ba){
        pq.push(a);
        sum += a;
        if(pq.size() > k){
            sum -= pq.top();
            pq.pop();
        }
        if(sum >= p && pq.size() == k){
            cout << b << endl;
            return 0;
        }
    }
    cout << -1 << endl;
    
    return 0;
}