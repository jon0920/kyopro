#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){
    
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    rep(i,n) cin >> a[i];
    rep(i,m){
        int b, c;
        cin >> b >> c;
        if(a[b - 1] >= c) a[b - 1] -= c;
    }

    for(int x : a) cout << x << " ";
    cout << endl;
    
    return 0;
}