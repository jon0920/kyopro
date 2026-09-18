#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){
    
    int n, x, y;
    cin >> n >> x >> y;
    vector<int> a(n);
    rep(i,n) cin >> a[i];

    vector<vector<int>> sep;
    vector<int> tmp;
    rep(i,n){
        if(a[i] >= y && a[i] <= x) tmp.push_back(a[i]);
        else {
            if(!tmp.empty()){
                sep.push_back(tmp); 
                tmp.clear();
            }
        }
    }
    if(!tmp.empty()) sep.push_back(tmp);

    auto calc = [&](vector<int> v){
        ll res = 0;
        int sz = v.size();
        int l = 0, r = 0;
        int X_cnt = 0, Y_cnt = 0;

        while(l != sz){
            while(r != sz && (X_cnt == 0 || Y_cnt == 0)){
                if(v[r] == x) X_cnt++;
                if(v[r] == y) Y_cnt++;
                r++;
            }
            if(X_cnt > 0 && Y_cnt > 0) res += sz - r + 1;
            if(v[l] == x) X_cnt--;
            if(v[l] == y) Y_cnt--;
            l++;
        }
        return res;
    };

    ll ans = 0;
    for(auto vec : sep){
        ans += calc(vec);
    }

    cout << ans << endl;
    
    return 0;
}