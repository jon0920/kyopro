#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

struct point{
    ll x, y;
};

int main(){
    
    int n, q;
    cin >> n >> q;
    vector<point> pts(n);
    rep(i,n) cin >> pts[i].x >> pts[i].y;

    auto cross = [&](const point &a, const point &b){
        return a.x * b.y - a.y * b.x;
    };

    auto cmp = [&](const point &a, const point &b){
        int a_half = (a.y < 0 || (a.y == 0 && a.x < 0));
        int b_half = (b.y < 0 || (b.y == 0 && b.x < 0));
        if(a_half != b_half) return a_half < b_half;
        return cross(a, b) > 0;
    };

    /*
    auto arg_sort = [&](vector<point> &pts) -> void {
        sort(pts.begin(), pts.end(), cmp);
    };
    */
    
    vector<int> ord(n);
    iota(ord.begin(), ord.end(), 0);
    sort(ord.begin(), ord.end(), [&](int a, int b){
        return cmp(pts[a], pts[b]);
    });
    reverse(ord.begin(), ord.end());

    vector<int> pos(n);
    rep(i,n) pos[ord[i]] = i;

    vector<int> l(n), r(n);
    l[0] = 0, r[n - 1] = n;
    for(int i = 1; i < n; i++){
        l[i] = (cmp(pts[ord[i]], pts[ord[i - 1]]) ? i : l[i - 1]);
    }
    for(int i = n - 2; i >= 0; i--){
        r[i] = (cmp(pts[ord[i + 1]], pts[ord[i]]) ? i + 1 : r[i + 1]);
    }

    while(q--){
        int a, b;
        cin >> a >> b;
        a--, b--;
        int res_a = l[pos[a]];
        int res_b = r[pos[b]];
        if(res_a < res_b) cout << res_b - res_a << endl;
        else cout << n - res_a + res_b << endl;
    }
    
    return 0;
}