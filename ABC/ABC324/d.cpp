#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < n; i++)
using ll = long long;

int main() {
    
    int n;
    string s;
    cin >> n >> s;
    sort(s.rbegin(), s.rend());
    ll mx = stoll(s);
    vector<int> cnt(10);
    for(auto c : s) cnt[c - '0']++;

    ll x = 0;
    int ans = 0;
    while(x * x <= mx){
        ll y = x * x;
        int digit = 0;
        vector<int> res(10);
        while(y){
            res[y % 10]++;
            y /= 10;
            digit++;
        }
        if(digit < n) res[0] += n - digit;
        bool ok = true;
        rep(i,10) if(cnt[i] != res[i]) ok = false;
        if(ok) ans++;
        x++;
    }

    cout << ans << endl;
    
    return 0;
}