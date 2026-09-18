#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < n; i++)
using ll = long long;

int solve(){
    int n;
    cin >> n;
    vector<int> s(n);
    rep(i,n) cin >> s[i];

    if(s.back() <= s[0] * 2) return 2;

    vector<int> ns;
    for(int x : s){
        if(x < s[0]) continue;
        if(x > s.back()) continue;
        ns.push_back(x);
    }

    s = ns;
    n = s.size();
    sort(s.begin(), s.end());
    rep(i,n-1){
        if(s[i] * 2 < s[i + 1]) return -1;
    }

    int last = s[0], ans = 1;
    for(int i = 1; i < n; i++){
        if(last * 2 < s[i]){
            last = s[i - 1];
            ans++;
        }
    }
    return ans + 1;
}

int main() {
    int t;
    cin >> t;
    rep(ti,t) cout << solve() << endl;
    return 0;
}