#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){
    
    int n;
    cin >> n;
    vector<pair<ll,ll>> st;
    ll p = 0, ans = 0;
    rep(i,n){
        ll d, v;
        cin >> d >> v;
        if(d > p) st.push_back({d, v});
        else{
            p += d; ans += v;
            while(!st.empty()){
                if(st.back().first <= p){
                    p += st.back().first;
                    ans += st.back().second;
                    st.pop_back();
                } else break;
            }
        }
    }

    cout << ans << endl;
    
    return 0;
}