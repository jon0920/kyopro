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
        
        vector<int> tmp(n);
        iota(tmp.begin(), tmp.end(), 0);
        sort(tmp.begin(), tmp.end(), [&](int a, int b){
            return cmp(pts[a], pts[b]);
        });

        vector<int> ord(n * 2);
        rep(i,n){
            ord[i] = tmp[i];
            ord[i + n] = tmp[i];
        }

        int ans = 0;
        int R = 1;
        for(int L = 0; L < n * 2; L++){
            R = max(R, L + 1);
            while(R < n * 2){
                if(pts[ord[L]].x * pts[ord[R]].y - pts[ord[L]].y * pts[ord[R]].x > 0) R++;
                else break;
            }
            ans = max(ans, R - L);
        }

        cout << ans << endl;
    }
    
    return 0;
}