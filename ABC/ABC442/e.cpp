#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < n; i++)
using ll = long long;

struct point{
    int x; int y;
};

ll cross(const point &a, const point &b){
    return (ll)a.x * b.y - (ll)a.y * b.x;
};

bool cmp(const point &a, const point &b){
    int ah = (a.y < 0 || (a.y == 0 && a.x < 0));
    int bh = (b.y < 0 || (b.y == 0 && b.x < 0));
    if(ah != bh) return ah < bh;
    return cross(a, b) > 0;
};

/*
void argument_sort(vector<point> &points){
    sort(points.begin(), points.end(), cmp);
}
*/

int main() {

    int n, q;
    cin >> n >> q;
    vector<point> pt(n);
    rep(i,n) cin >> pt[i].x >> pt[i].y;

    vector<int> ord(n);
    iota(ord.begin(), ord.end(), 0);
    sort(ord.begin(), ord.end(), [&](int i, int j){
        return cmp(pt[i], pt[j]);
    });
    reverse(ord.begin(), ord.end());
    vector<int> rev(n);
    rep(i,n) rev[ord[i]] = i;

    vector<int> l(n), r(n);
    l[0] = 0, r[n - 1] = n;
    for(int i = 1; i < n; i++){
        l[i] = (cmp(pt[ord[i]], pt[ord[i - 1]]) ? i : l[i - 1]);
    }
    for(int i = n - 2; i >= 0; i--){
        r[i] = (cmp(pt[ord[i + 1]], pt[ord[i]]) ? i + 1 : r[i + 1]);
    }

    while(q--){
        int a, b;
        cin >> a >> b;
        a--, b--;
        a = l[rev[a]];
        b = r[rev[b]];
        if(a < b) cout << b - a << endl;
        else cout << n - a + b << endl;
    }
    
    return 0;
}