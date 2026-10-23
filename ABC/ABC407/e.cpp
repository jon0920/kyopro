#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){
    
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<ll> a(n * 2);
        rep(i,n * 2) cin >> a[i];

        priority_queue<ll> pq;
        ll ans = 0;
        rep(i,n * 2){
            pq.push(a[i]);
            if(i % 2 == 0){
                ans += pq.top();
                pq.pop();
            }
        }

        cout << ans << endl;
    }
    
    return 0;
}