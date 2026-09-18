#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < n; i++)
using ll = long long;

int main() {

    int n;
    cin >> n;
    vector<int> h(n);
    rep(i,n) cin >> h[i];

    int ans = 1;
    for(int k = 1; k < n; k++){
        for(int i = 0; i < k; i++){
            int cnt = 1;
            int pos = 0;
            while(true){
                if(i + pos + k >= n){
                    ans = max(cnt, ans);
                    break;
                }
                if(h[i + pos] == h[i + pos + k]) cnt++;
                else{
                    ans = max(ans, cnt);
                    cnt = 1;
                }
                pos += k;
            }
        }

    }
    cout << ans << endl;

}