#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){
    
    int n, k;
    cin >> n >> k;
    vector<int> h(n);
    vector<int> diff(n - 1);    
    rep(i,n) cin >> h[i];
    rep(i,n - 1){
        if(h[i] < h[i + 1]) diff[i] = 1;
        else if(h[i] > h[i + 1]) diff[i] = 2;
        else diff[i] = 0;
    }

    int ans = 0;
    pair<int,int> minmax = {1e9+10, 0};
    vector<bool> check(3);
    rep(i,n - 1){
        if(!check[1]){
            
        }
    }
    
    return 0;
}