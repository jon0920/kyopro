#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < n; i++)
using ll = long long;

int main() {
    
    int n;
    cin >> n;
    vector<int> p(n);
    rep(i,n) cin >> p[i];
    int q;
    cin >> q;
    rep(i,q){
        int a, b;
        cin >> a >> b;
        rep(j,n){
            if(p[j] == a){
                cout << a << endl;
                break;
            }
            else if(p[j] == b){
                cout << b << endl;
                break;
            }
        }
    }
    
    return 0;
}