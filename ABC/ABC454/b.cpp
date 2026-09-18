#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){

    int n, m;
    cin >> n >> m;
    vector<bool> used(m);
    bool ok = true;
    rep(i,n){
        int f;
        cin >> f;
        f--;
        if(used[f]){
            ok = false;
        }

        used[f] = true;
    }

    bool wa = false;
    for(auto i : used) if(!i) wa = true;

    cout << (ok ? "Yes" : "No") << endl;
    cout << (wa ? "No" : "Yes") << endl;

    return 0;
}