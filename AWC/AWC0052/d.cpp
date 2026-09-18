#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){

    int n, m;
    cin >> n >> m;
    vector<set<int>> s(m);
    vector<int> r(m);
    rep(i,m){
        int k;
        cin >> k;
        rep(j,k){
            int x;
            cin >> x;
            x--;
            s[i].insert(x);
        }
        cin >> r[i];
    }

    int ans = n;
    for(int bit = 0; bit < (1 << n); bit++){
        vector<int> vi;
        rep(i,n){
            if(bit & (1 << i)) vi.push_back(i);
        }

        bool ok = true;
        rep(j,m){
            bool wa = false;
            if(r[j] == 1){
                bool check = false;
                for(auto x : vi){
                    if(s[j].count(x)) check = true;
                }
                if(!check) wa = true;
            } else {
                for(auto x : vi){
                    if(s[j].count(x)) wa = true;
                }
            }
            if(wa) ok = false;
        }
        if(ok) ans = min(ans, (int)vi.size());
    }

    cout << ans << endl;

    return 0;
}