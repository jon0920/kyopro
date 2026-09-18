#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){

    int n, k;
    cin >> n >> k;
    vector<int> x(n);
    rep(i,n) cin >> x[i];
    sort(x.begin(), x.end());

    deque<int> dq;
    int r = 0;
    int ans = 0;
    for(int l = 0; l < n; l++){
        while(r < n && (dq.empty() || x[r] - *dq.begin() <= k)){
            dq.push_back(x[r]);
            r++;
        }
        ans = max(ans, (int)dq.size());
        dq.pop_front();
    }
    cout << ans << endl;

    return 0;
}