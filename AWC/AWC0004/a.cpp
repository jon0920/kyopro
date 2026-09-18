#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){

    int n, s, t;
    cin >> n >> s >> t;
    int time = (t - s) * 60;
    bool ans = true;
    rep(i,n){
        int a;
        cin >> a;
        time -= a;
        if(time < 0) ans = false; 
    }

    cout << (ans ? "Yes" : "No") << endl;

    return 0;
}