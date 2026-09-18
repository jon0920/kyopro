#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){

    ll L, n1, n2;
    cin >> L >> n1 >> n2;

    queue<pair<ll,ll>> rle1, rle2;
    rep(i,n1){
        ll v, l;
        cin >> v >> l;
        rle1.push({v,l}); 
    }
    rep(i,n2){
        ll v, l;
        cin >> v >> l;
        rle2.push({v,l});
    }

    ll ans = 0;
    while(!rle1.empty() && !rle2.empty()){
        auto &[num1, c1] = rle1.front();
        auto &[num2, c2] = rle2.front();
        ll mn = min(c1, c2);
        if(num1 != num2){
            c1 -= mn, c2 -= mn;
            if(c1 <= 0) rle1.pop();
            if(c2 <= 0) rle2.pop();
        }
        else{
            ans += mn;
            c1 -= mn, c2 -= mn;
            if(c1 <= 0) rle1.pop();
            if(c2 <= 0) rle2.pop();
        }
    }    
    cout << ans << endl;

    return 0;
}