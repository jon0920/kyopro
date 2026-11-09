#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){
    
    int n, q;
    cin >> n >> q;
    vector<int> num(n + 1);
    rep(i,n + 1) num[i] = i;

    rep(i,q){
        int k;
        cin >> k;
        vector<int> tmp(k + 1);
        for(int j = 1; j <= k; j++){
            tmp[j] = num[j];
        }
        for(int j = 1; j <= k; j++){
            num[j] = -tmp[k - j + 1];
        }
    }

    for(int i = 1; i <= n; i++) cout << num[i] << endl;

    return 0;
}