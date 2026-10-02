#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){
    
    int n, x, y;
    cin >> n >> x >> y;
    vector<vector<int>> v;
    vector<int> tmp;
    rep(i,n){
        int a;
        cin >> a;
        if(a <= x && a >= y) tmp.push_back(a);
        else {
            if(!tmp.empty()){
                v.push_back(tmp);
                tmp.clear();
            }
        }
    }
    if(!tmp.empty()) v.push_back(tmp);

    auto solve = [&](vector<int> v){
        ll res = 0;
        int sz = v.size();
        int x_cnt = 0, y_cnt = 0;
        int r = 0;
        for(int l = 0; l < sz; l++){
            while(r < sz && (x_cnt == 0 || y_cnt == 0)){
                if(v[r] == x) x_cnt++;
                if(v[r] == y) y_cnt++;
                r++;
            }
            if(x_cnt && y_cnt) res += sz - r + 1;
            if(v[l] == x) x_cnt--;
            if(v[l] == y) y_cnt--;
        }
        return res;
    };

    ll ans = 0;
    for(auto vec : v){
        ans += solve(vec);
    }

    cout << ans << endl;
    
    return 0;
}

/*
最大値、最小値が(x,y)である範囲を分割
尺取りで数える
条件を満たすrを求めて、そこから先はすべて満たす((x,y)である範囲で分割しているため)
よってsz - r + 1を加算
*/