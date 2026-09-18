#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)


int main(){

    int n;
    cin >> n;
    vector<int> H;
    ll ans = 0;
    rep(i,n){
        int h;
        cin >> h;
        while(!H.empty()){
            if(H.back() <= h) H.pop_back();
            else break;
        }
        ans += H.size();
        H.push_back(h);
    }
    cout << ans << endl;

    return 0;
}