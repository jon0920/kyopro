#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){

    int n;
    cin >> n;
    vector<int> a(n);
    rep(i,n) cin >> a[i];

    int ans = 0, cnt = 0;
    int r;
    set<int> st;
    bool check = false;
    for(int l = 0; l < n; l++){
        r = l + 1;
        if(r >= n) break;
        if(a[l] == a[r] && !st.count(a[l])){
            cnt += 2;
            st.insert(a[l]);
            l++;
            check = true;
        } else {
            cnt = 0;
            st.clear();
            if(check) l -= 2;
            check = false;
        }
        ans = max(ans, cnt);
    }

    cout << ans << endl;

    return 0;
}