#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){

    int n, k;
    cin >> n >> k;
    int ans = 0;
    rep(i,n){
        int a;
        cin >> a;
        ans ^= a % (k + 1);
    }

    cout << (ans ? "Takahashi" : "Aoki") << endl;

    return 0;
}