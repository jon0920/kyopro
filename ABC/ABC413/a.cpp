#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < n; i++)
using ll = long long;

int main(){
    int n, m;
    cin >> n >> m;
    int a;
    int ans = 0;
    rep(i,n){
        cin >> a;
        ans += a;
    }
    if(ans <= m) cout << "Yes" << endl;
    else cout << "No" << endl;
        
}