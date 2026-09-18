#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){

    int n, r;
    cin >> n >> r;
    rep(i,n){
        int d, a;
        cin >> d >> a;
        if(d == 1){
            if(r >= 1600 && r <= 2799) r += a;
        } else {
            if(r >= 1200 && r <= 2399) r += a;
        }
    }

    cout << r << endl;

    return 0;
}