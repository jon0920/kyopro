#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){

    int n, w, k;
    cin >> n >> w >> k;

    int pos = 0;
    rep(i,n - 1){
        pos += k;
    }
    if(pos > w) cout << "No" << endl;
    else cout << "Yes" << endl;

    return 0;
}