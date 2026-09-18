#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < n; i++)
using ll = long long;

int main() {
    
    int n;
    cin >> n;
    vector<int> a(n);
    rep(i,n) cin >> a[i];

    vector<int> diff(n - 1);
    rep(i,n-1){
        diff[i] = a[i + 1] - a[i];
    }
    
    vector<int> distance_count;
    int cnt = 1;
    rep(i,n - 1){
        if(i == n - 2){
            distance_count.push_back(cnt);
            break;
        } 
        if(diff[i] == diff[i + 1]) cnt++;
        else{
            distance_count.push_back(cnt);
            cnt = 1;
        }
    }

    ll ans = n + n - 1;
    for(int x : distance_count) ans += (x - 1) * x / 2;
            
    cout << ans << endl;

    
    return 0;
}