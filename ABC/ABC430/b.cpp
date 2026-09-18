#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < n; i++)
using ll = long long;

int main() {
    
    int n, m;
    cin >> n >> m;
    vector<string> s(n);
    rep(i,n) cin >> s[i];

    set<string> p;

    rep(i,n - m + 1){
        rep(j, n - m + 1){
            string tp = "";
            rep(k,m){
                tp += s[i + k].substr(j,m);
            }
            p.insert(tp);
        }
    }
    cout << p.size() << endl;
    return 0;
}