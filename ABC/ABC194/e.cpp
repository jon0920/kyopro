#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){
    
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    rep(i,n) cin >> a[i];

    vector<int> cnt(n);
    rep(i,m) cnt[a[i]]++;

    set<int> st;
    rep(i,n) if(cnt[i] == 0) st.insert(i);

    int ans = st.empty() ? n : *st.begin();
    rep(i,n - m){
        cnt[a[i]]--;
        if(cnt[a[i]] == 0){
            st.insert(a[i]);
        }
        if(cnt[a[i + m]] == 0){
            st.erase(a[i + m]);
        }
        cnt[a[i + m]]++;
        ans = min(ans, *st.begin());
    }

    cout << ans << endl;

    return 0;
}