#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < n; i++)
using ll = long long;

int main() {
    
    int n;
    cin >> n;
    vector<int> p(n);
    rep(i,n) cin >> p[i];
    
    rep(i,n){
        int r = 1;
        rep(j,n){
            if(p[i] < p[j]) r++;
        }
        cout << r << endl;
    }
    
    
    return 0;
}