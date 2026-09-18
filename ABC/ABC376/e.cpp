#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){

    int t;
    cin >> t;
    while(t--){
        int n, k;
        cin >> n >> k;
        vector<pair<ll,ll>> ab(n);
        rep(i,n) cin >> ab[i].first;
        rep(i,n) cin >> ab[i].second;
        sort(ab.begin(), ab.end());

        priority_queue<ll> pq;
        ll sum = 0;
        ll ans = 4e18;

        rep(i,n){
            auto [a, b] = ab[i];
            pq.push(b);
            sum += b;

            if(pq.size() > k){
                sum -= pq.top();
                pq.pop();
            }

            if(pq.size() == k){
                ans = min(ans, a * sum);
            }
        }
        cout << ans << endl;
    }

    return 0;
}