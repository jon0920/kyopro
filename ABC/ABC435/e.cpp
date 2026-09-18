#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < n; i++)
using ll = long long;

int main() {
    
    int n, q, L, R;
    set<pair<int,int>> st;
    set<pair<int,int>>::iterator itr;

    cin >> n >> q;
    st.insert({n, 1});
    int ans = n;
    for(int i = 0; i < q; i++){
        cin >> L >> R;
        itr = st.lower_bound({L, -1});
        vector<pair<int,int>> resv;
        while(itr != st.end()){
            int sl = (*itr).second;
            int sr = (*itr).first;
            if(R < sl) break;
            if((sl < L) && (R < sr)){
                resv.push_back({L - 1, sl});
                resv.push_back({sr, R + 1});
            }
            else if((sl < L) && (L <= sr)){
                resv.push_back({L - 1, sl});
            }
            else if((R < sr) && (sl < R)){
                resv.push_back({sr, R + 1});
            }
            ans -= min(sr, R) - max(sl, L) + 1;
            itr = st.erase(itr);
        }
        int sz = resv.size();
        for(int i = 0; i < sz; i++){
            st.insert(resv[i]);
        }
        cout << ans << endl;
    }
    
    return 0;
}