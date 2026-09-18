#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){

    int n, m;
    cin >> n >> m;
    vector<int> d(n), s(m);
    rep(i,n) cin >> d[i];
    rep(i,m) cin >> s[i];
    sort(s.begin(), s.end());

    ll ans = 0;
    for(auto x : d){
        auto it = lower_bound(s.begin(), s.end(), x);
        if(it == s.begin()){
            ans += abs(x - *it);
        }
        else if(it == s.end()){
            it--;
            ans += abs(x - *it);
        }
        else{
            auto it2 = it - 1;
            ans += min(abs(x - *it), abs(x - *it2));
        }
    }
    cout << ans << endl;

    return 0;
}