#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){
    
    int n;
    cin >> n;
    vector<int> p(n), q(n);
    rep(i,n) cin >> p[i];
    rep(i,n) cin >> q[i];

    int l = -1, r = -1;
    rep(i,n){
        if(p[i] != q[i]){
            l = i;
            break;
        }
    }
    for(int i = n - 1; i >= 0; i--){
        if(p[i] != q[i]){
            r = i;
            break;
        }
    }
    if(l == -1){
        cout << "Yes" << endl;
        return 0;
    }
    
    vector<int> pp, qq;
    for(int i = l; i <= r; i++){
        pp.push_back(p[i]);
        qq.push_back(q[i]);
    }    
    reverse(qq.begin(), qq.end());

    rep(i,pp.size()){
        if(pp[i] != qq[i]){
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;
    
    return 0;
}