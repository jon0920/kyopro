#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){

    int n, x, y;
    cin >> n >> x >> y;
    vector<int> a(n);
    rep(i,n) cin >> a[i];
    set<int> dpx, dpy;
    dpx.insert(a[0]);
    dpy.insert(0);

    for(int i = 1; i < n; i++){
        set<int> nxt;
        if(i % 2 == 1){
            for(int v : dpy){
                nxt.insert(v + a[i]);
                nxt.insert(v - a[i]);
            }
            dpy = nxt;
        }
        else{
            for(int v : dpx){
                nxt.insert(v + a[i]);
                nxt.insert(v - a[i]);
            }
            dpx = nxt;
        }
    }
    if(dpx.count(x) && dpy.count(y)) cout << "Yes" << endl;
    else cout << "No" << endl;

    return 0;
}