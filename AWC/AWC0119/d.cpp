#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){
    
    int n, m;
    cin >> n >> m;
    vector<pair<int,int>> ec(n);
    vector<int> d(m);
    rep(i,n) cin >> ec[i].first >> ec[i].second;
    rep(i,m) cin >> d[i];

    sort(ec.begin(), ec.end());
    sort(d.begin(), d.end());

    int j = 0;
    int ans = 0;
    rep(i,m){
        while(j < n){
            if(ec[j].first >= d[i]){
                ans++;
                ec[j].second--;
                if(ec[j].second == 0) j++;
                break;
            } else {
                j++;
            }
        }
    }

    cout << ans << endl;
    
    return 0;
}