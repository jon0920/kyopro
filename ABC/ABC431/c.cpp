#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < n; i++)
using ll = long long;

int main() {
    
    int n, m, k;
    cin >> n >> m >> k;
    vector<ll> h(n), b(m);
    rep(i,n) cin >> h[i];
    rep(i,m) cin >> b[i];

    sort(h.rbegin(),h.rend());
    sort(b.rbegin(),b.rend());

    int i = 0, j = 0, cnt = 0;
    while(i < n && j < m){
        if(h[i] <= b[j]){
            cnt++;
            i++;
            j++;
        }
        else{
            i++;
        }
    }

    cout << (cnt >= k ? "Yes" : "No") << endl;
    
    return 0;
}