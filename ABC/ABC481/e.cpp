//arg_sort
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

struct point{
    ll x, y;
};

int main(){
    
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
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

        sort(pts.begin(), pts.end(), cmp);

        int ans = 0;
        int r = 0;
        for(int l = 0; l < n * 2; l++){
            r = max(r, l + 1);
            while(r < n * 2){
                if(cross(pts[l % n], pts[r % n]) <= 0) break;
                r++;
            }
            ans = max(ans, r - l);
        }

        cout << ans << endl;
    }
    
    return 0;
}